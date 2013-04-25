#include "Creditos.h"

#include "SDL.h"
#include "SDL_image.h"

#include <windows.h>
#include <GL/glu.h>

#include "Button.h"

Creditos::Creditos():
Scene(STATE_CREDITS)
{
	SetDone(0);
}

Creditos::~Creditos()
{
	if(ListManager::GetListManager()->GetMyImageList())
		ListManager::GetListManager()->GetMyImageList()->DeleteList();
	if(ListManager::GetListManager()->GetMyMessageList())
		ListManager::GetListManager()->GetMyMessageList()->DeleteList();
	if(ListManager::GetListManager()->GetMySfxList())
		ListManager::GetListManager()->GetMySfxList()->DeleteList();
	if(ListManager::GetListManager()->GetMyMusicList())
		ListManager::GetListManager()->GetMyMusicList()->DeleteList();
	if(GetMyRenderList())
		GetMyRenderList()->DeleteList();
}

void Creditos::Setup()
{
	SetDesiredState(GetMyState());

	// BACKGROUND
	ListManager::GetListManager()->NewImageToTheList(RenderManager::GetRenderManager()->LoadTexture("Data/Images/MSsplash2.png"), IMAGE_BACKGROUND_CREDITOS);
	NewObjectToTheList(&CreditosBackground, new Background(ANIMATION_BACKGROUND_CREDITOS, 0 ));
	//CreditosBackground = new Background(ANIMATION_BACKGROUND_CREDITOS, 0 );

	//define posição na tela
	CreditosBackground->SetScreenX0(0);
	CreditosBackground->SetScreenY0(0);
	CreditosBackground->SetScreenX1(SDL_GetVideoInfo()->current_w);
	CreditosBackground->SetScreenY1(SDL_GetVideoInfo()->current_h);


	// BUTTON
	ListManager::GetListManager()->NewImageToTheList(RenderManager::GetRenderManager()->LoadTexture("Data/Images/ButtonRaw.png"), IMAGE_BUTTON1);
	NewObjectToTheList(&Button1, new Button( ANIMATION_BUTTON1, NORMAL, STATE_MENU));
	//Button1 = new Button( ANIMATION_BUTTON1, NORMAL, STATE_MENU);

	SetScreenOffsets();
}

void Creditos::Input()
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
	{
		switch( event.type ){
			case SDL_MOUSEBUTTONDOWN:
				switch( event.button.state ){
			case SDL_PRESSED:
				VerifyButtons(event.button.x, event.button.y);
				break;
			default:
				break;
				}
				break;
			case SDL_QUIT:
				SetDone(1);
				break;
		}
	}
}

void Creditos::Update()
{
	int state = Button1->IsPressed();

	if (state >= 0)
		SetDesiredState(state);
}

//void Creditos::Draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	DrawIt(CreditosBackground);
//	DrawIt(Button1);
//
//	SDL_GL_SwapBuffers();
//}

void Creditos::TearDown()
{

}

void Creditos::SetScreenOffsets()
{
	float buttonWidth = ListManager::GetListManager()->GetMyImageList()->GetNode(Button1->GetMyAnimatedSprite()->GetImageID())->GetNodeData()->GetImageW();
	////metade da largura da tela menos
	////x1 - x0/2 (metade da largura do sprite)
	Button1->SetScreenX0( (SDL_GetVideoInfo()->current_w/2) - (buttonWidth/2) );
	Button1->SetScreenX1( (SDL_GetVideoInfo()->current_w/2) + (buttonWidth/2) );
	////quarto da altura da tela
	//// vezes 3 (primeiro botão de cima, os outros são 2 e 1)
	////y1 - y0/2 (metade da  altura do sprite)
	Button1->SetScreenY0( 308 ); 
	Button1->SetScreenY1( 364 );
}

void Creditos::VerifyButtons( int _x, int _y )
{
	if(Button1->IsButtonArea(_x, _y))
		Button1->SetState(PRESSED);
}
