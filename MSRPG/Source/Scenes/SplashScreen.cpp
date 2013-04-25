#include "SplashScreen.h"

SplashScreen::SplashScreen():
Scene(STATE_SPLASHSCREEN)
{
	SetDone(FALSE);
}

SplashScreen::~SplashScreen()
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

void SplashScreen::Setup()
{
	//set this scene state
	SetDesiredState(GetMyState());

	ListManager::GetListManager()->NewImageToTheList(RenderManager::GetRenderManager()->LoadTexture("Data/Images/MSsplash2.png"), IMAGE_SPLASH1);

	//load splash generic object
	//FirstSplash = new Splash(ANIMATION_SPLASH1, 0);
	NewObjectToTheList(&FirstSplash, new Splash(ANIMATION_SPLASH1, 0));

	//define posição na tela
	FirstSplash->SetScreenX0(0);
	FirstSplash->SetScreenY0(0);
	FirstSplash->SetScreenX1(SDL_GetVideoInfo()->current_w);
	FirstSplash->SetScreenY1(SDL_GetVideoInfo()->current_h);
}

void SplashScreen::Input()
{
	while( SDL_PollEvent( &event ) )
	{
		switch( event.type ){
			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ){
					case SDLK_ESCAPE:
						SetDone(TRUE);
						break;
					case SDLK_RETURN:
						SetDesiredState(STATE_MENU);
						break;
					default:
						break;
				}
				break;
			case SDL_QUIT:
				SetDone(TRUE);
				break;
		}
	}
}

void SplashScreen::Update()
{
	if(FirstSplash->Update())
		SetDesiredState(STATE_MENU);
}

//void SplashScreen::Draw() // define onde os sprites serão desenhados
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	DrawIt(FirstSplash);
//
//	SDL_GL_SwapBuffers();
//}

void SplashScreen::TearDown()
{
	//delete Scene;
}