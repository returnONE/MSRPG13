#include "FPSControl.h"

FPSControl *g_TheFPSControl = new FPSControl;

FPSControl::FPSControl()
{
	initialFrameTime = NULL;
	frameCounter = 0;
}

FPSControl::~FPSControl()
{

}


void FPSControl::SetInitialFrameTime( Uint32 _time )
{
	initialFrameTime = _time;
}

bool FPSControl::VerifyFrameEnd()
{
	float currentFrameTime = (float)SDL_GetTicks() - (float)initialFrameTime;

	if( currentFrameTime < TOTALFRAMETIME ) 
	{
		SDL_Delay( TOTALFRAMETIME - (SDL_GetTicks() - initialFrameTime) );
		return true;
	}
	else
		return false;
}

void FPSControl::AddToFrameCounter()
{
	if( (SDL_GetTicks() - initialOneSecondTime) >= 1000 )
	{
		currentFPS = frameCounter;
		frameCounter = 0;
		initialOneSecondTime = SDL_GetTicks();
	}

	frameCounter++;
}

void FPSControl::SetInitialOneSecondTime( Uint32 _time )
{
	initialOneSecondTime = _time;
}

Uint32 FPSControl::GetCurrentFPS() const
{
	return currentFPS;
}
