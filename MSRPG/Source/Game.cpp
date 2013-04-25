#include "Game.h"

#include "Scene.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "InGame.h"
#include "Creditos.h"
#include "Options.h"
#include "AnimationManager.h"
#include "ListManager.h"

#include <iostream>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "SDL.h"
#include "SDL_mixer.h"

Game::Game():
done(FALSE),
currentState(STATE_SPLASHSCREEN)
{
	FirstStateChange(new SplashScreen());
}

Game::~Game()
{
	
}

int Game::GameLooping()
{
	InitWindow();
	GameSetup();

	TheScene->Setup();

	g_TheFPSControl->SetInitialOneSecondTime(SDL_GetTicks());

	while(!done)
    {
		//std::cout << "looping \n" ;

		//pega o tempo de quando o frame iniciou
		g_TheFPSControl->SetInitialFrameTime(SDL_GetTicks());
		g_TheFPSControl->AddToFrameCounter();

		TheScene->Input();
		TheScene->Update();
		TheScene->Draw();

		if(TheScene->GetDone())
			done = 1;

		//verifica se houve alguma transição de cena
		VerifyStateChange();

		//verifica quanto tempo se passou no loop, e da um delay se necessário
		g_TheFPSControl->VerifyFrameEnd();
	}

	TheScene->TearDown();
	LastTearDown();
	return 0;
}

void Game::InitWindow()
{
	//VSyncOn( 0 );

    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        SDL_Quit();
    }
	if ( SDL_Init(SDL_INIT_AUDIO) < 0 ) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		SDL_Quit();
	}
	if ( SDL_Init(SDL_INIT_TIMER) < 0 ) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		SDL_Quit();
	}

	//Initialize SDL_mixer
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) <0 ){
		printf("Mix_OpenAudio> %s\n", Mix_GetError());
	    SDL_Quit();
	}

	if( Mix_Init( MIX_INIT_MP3 ) <0 ){
		printf("Mix_Init> %s\n", Mix_GetError());
		SDL_Quit();
	}

	freopen( "CON", "w", stdout );
	freopen( "CON", "w", stderr );

    //SDL_WM_SetIcon(IMG_Load("Imagem/xvid.bmp"), NULL);
    SDL_WM_SetCaption("SDLSkeleton", NULL);


    //SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    //SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    //SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    //SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    //SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
    //SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );
    //SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    //SDL_GL_SetAttribute( SDL_GL_ACCUM_RED_SIZE, 0);
    //SDL_GL_SetAttribute( SDL_GL_ACCUM_GREEN_SIZE, 0);
    //SDL_GL_SetAttribute( SDL_GL_ACCUM_BLUE_SIZE, 0);
    //SDL_GL_SetAttribute( SDL_GL_ACCUM_ALPHA_SIZE, 0);
    //SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 0 ) ;


    if ( SDL_SetVideoMode(1024, 720, 0, SDL_OPENGL) == NULL ) {
        fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
        SDL_Quit();
    }

    SDL_EnableKeyRepeat(500, SDL_DEFAULT_REPEAT_INTERVAL);

    glViewport( 0, 0, SDL_GetVideoInfo()->current_w, SDL_GetVideoInfo()->current_h );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

	gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);
    glEnable( GL_BLEND );
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.3, 0.3, 0.0, 0.0);
}

void Game::FirstStateChange(Scene* newState)
{
	TheScene = newState;	
}	

void Game::ChangeState(Scene* newState)
{
	TheScene = newState;	
}	

void Game::TearDownScene()
{
	delete TheScene;
}

void Game::VerifyStateChange()
{
	if(TheScene->GetDesiredState() != TheScene->GetMyState())
	{ 
		switch(TheScene->GetDesiredState()) //verifica qual a nova cena 
		{ 
		case STATE_SPLASHSCREEN:
			ChangeState(new SplashScreen());
			break;
		case STATE_MENU:
			TearDownScene();
			ChangeState(new Menu());
			break;
		case STATE_OPTIONS:
			TearDownScene();
			ChangeState(new Options());
			break;
		case STATE_CREDITS:
			TearDownScene();
			ChangeState(new Creditos());
			break;
		case STATE_INGAME:
			TearDownScene();
			ChangeState(new InGame());
			break;
		case STATE_INVALID:
		default:
			TearDownScene();
			fprintf(stderr, "Invalid State");
			SDL_Quit();
			break;
		}

		TheScene->Setup();
	}
}

void Game::LastTearDown()
{
	delete g_TheFPSControl;
	delete TheScene;

	Mix_Quit();
	SDL_Quit();
}

void Game::GameSetup()
{
	AnimationManager::GetAnimationManager()->ParseAnimationXML();
	ListManager::GetListManager()->CreateMyImageList();
}
