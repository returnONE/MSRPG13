#include "SDL.h"
#include "Game.h"


int main( int argc, char* args[] )
{


	Game TheGame;

	TheGame.GameLooping();

	//Quit SDL
	SDL_Quit();

	return 0;
}