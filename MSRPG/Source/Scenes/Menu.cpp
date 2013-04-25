#include "Menu.h"

class Game;

Menu::Menu():
Scene(STATE_MENU)
{
	SetDone(0);
}

Menu::~Menu()
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

void Menu::Setup()
{
	SetDesiredState(GetMyState());


	//Setup das imagens na tela Menu
	ListManager::GetListManager()->NewImageToTheList(RenderManager::GetRenderManager()->LoadTexture(BUTTONFILE), IMAGE_BUTTON1);

	//Button1 = (Button*)NewObjectToTheList(new Button( ANIMATION_BUTTON1, NORMAL, STATE_INGAME));
	NewObjectToTheList(&Button1, new Button( ANIMATION_BUTTON1, NORMAL, STATE_INGAME));
	//Button1 = new Button( ANIMATION_BUTTON1, NORMAL, STATE_INGAME);

	NewObjectToTheList(&Button2, new Button( ANIMATION_BUTTON1, NORMAL, STATE_OPTIONS));
	//Button2 = new Button( ANIMATION_BUTTON1, NORMAL, STATE_OPTIONS);

	NewObjectToTheList(&Button3, new Button( ANIMATION_BUTTON1, NORMAL, STATE_CREDITS));
	//Button3 = new Button( ANIMATION_BUTTON1, NORMAL, STATE_CREDITS);
	GetMyRenderList();

	SetImageScreenOffsets();


	//load da fonte
	//filestr.open("Data/Font/CenturyGothic.fnt");
	FontManager::GetFontManager()->NewFontToTheList("Data/Font/CenturyGothic", FONT_CENTURY_GOTHIC);


	//nova mensagem na tela
	ListManager::GetListManager()->NewMessageToTheList("Play Game", FONT_CENTURY_GOTHIC, 100, 100, 5000, 0);


	//Load the music
	ListManager::GetListManager()->NewMusicToTheList(MUSICFILE, MENUMUSIC);
	ListManager::GetListManager()->NewSfxToTheList(SFXFILE, SWORDSFX);
}

void Menu::Input()
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
	{
//////////// Mouse
		VerifyMouseOverButtons(event.button.x, event.button.y);

		switch( event.type ){
			case SDL_MOUSEBUTTONDOWN:
				switch( event.button.state ){
					case SDL_PRESSED:
						VerifyPressedButtons(event.button.x, event.button.y);
						break;
					default:
						break;
				}
				break;
//////////// Teclado
			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ){
					case SDLK_1:
						ListManager::GetListManager()->GetMySfxList()->GetNode(SWORDSFX)->GetNodeData()->PlaySfx();
						break;
					case SDLK_2:
						if( Mix_PlayingMusic() == 1 && Mix_PausedMusic() == 0 )
							ListManager::GetListManager()->GetMyMusicList()->GetNode(MENUMUSIC)->GetNodeData()->PauseMusic();
						else
							ListManager::GetListManager()->GetMyMusicList()->GetNode(MENUMUSIC)->GetNodeData()->PlayMusic();
						break;
					default:
						break;
				}
				break;
//////////// Botão na janela
			case SDL_QUIT:
				SetDone(1);
				break;
		}
	}
}

void Menu::Update()
{
	int state = Button1->IsPressed();
	if(state < 0)
		state = Button2->IsPressed();
	if(state < 0)
		state = Button3->IsPressed();

	if (state >= 0)
		SetDesiredState(state);
}

//void Menu::Draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//DrawIt(Button1);
//	//DrawIt(Button2);
//	//DrawIt(Button3);
//
//	RenderManager::GetRenderManager()->RenderFont("+..=,,+**Hello, World!**+,,=..+`^~´", myCharsetCenturyGothic, 70, 400);
//	//GetRenderManager()->RenderFont("ÑÑñúúáéÁÉóÓãÃñêÊôÔ", myCharsetCenturyGothic, 70, 370);
//
//	char stringFPS[5];
//	sprintf(stringFPS,"%d", g_TheFPSControl->GetCurrentFPS());
//	RenderManager::GetRenderManager()->RenderFont(stringFPS, myCharsetCenturyGothic, 1, 600);
//
//	DrawMessages();
//
//	SDL_GL_SwapBuffers();
//}

void Menu::TearDown()
{

}

void Menu::VerifyPressedButtons( int _x, int _y )
{
	if(Button1->IsButtonArea(_x, _y))
		Button1->SetState(PRESSED);
	if(Button2->IsButtonArea(_x, _y))
		Button2->SetState(PRESSED);
	if(Button3->IsButtonArea(_x, _y))
		Button3->SetState(PRESSED);
}

void Menu::VerifyMouseOverButtons( int _x, int _y )
{
	if(Button1->GetState() != PRESSED &&
	   Button2->GetState() != PRESSED &&
	   Button3->GetState() != PRESSED )
	{
		if(Button1->IsButtonArea(_x, _y))
			Button1->SetState(MOUSE_OVER);
		else
			Button1->SetState(NORMAL);

		if(Button2->IsButtonArea(_x, _y))
			Button2->SetState(MOUSE_OVER);
		else
			Button2->SetState(NORMAL);

		if(Button3->IsButtonArea(_x, _y))
			Button3->SetState(MOUSE_OVER);
		else
			Button3->SetState(NORMAL);
	}
}

void Menu::SetImageScreenOffsets()
{
	float buttonWidth = ListManager::GetListManager()->GetMyImageList()->GetNode(Button1->GetMyAnimatedSprite()->GetImageID())->GetNodeData()->GetImageW();

	//metade da largura da tela menos
	////x1 - x0/2 (metade da largura do sprite)
	Button1->SetScreenX0( (SDL_GetVideoInfo()->current_w/2) - (buttonWidth/2) );
	Button1->SetScreenX1( (SDL_GetVideoInfo()->current_w/2) + (buttonWidth/2) );
	////quarto da altura da tela
	//// vezes 3 (primeiro botão de cima, os outros são 2 e 1)
	////y1 - y0/2 (metade da  altura do sprite)
	Button1->SetScreenY0( 308 ); 
	Button1->SetScreenY1( 364 );

	Button2->SetScreenX0( (SDL_GetVideoInfo()->current_w/2) - (buttonWidth/2) );
	Button2->SetScreenX1( (SDL_GetVideoInfo()->current_w/2) + (buttonWidth/2) );
	Button2->SetScreenY0( 223 ); 
	Button2->SetScreenY1( 279 );

	Button3->SetScreenX0( (SDL_GetVideoInfo()->current_w/2) - (buttonWidth/2) );
	Button3->SetScreenX1( (SDL_GetVideoInfo()->current_w/2) + (buttonWidth/2) );
	Button3->SetScreenY0( 138 ); 
	Button3->SetScreenY1( 194 );
}
