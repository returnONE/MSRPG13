#include "Splash.h"
#include "SDL.h"

Splash::Splash(unsigned int _animationID, int _state):
GenericObject(_animationID,  _state)
{
	Setup(SDL_GetTicks());
}

Splash::~Splash()
{

}

void Splash::Setup(int _splashTimer)
{
	splashTimer = _splashTimer;
}

int Splash::GetSplashTimer() const
{
	return splashTimer;
}

bool Splash::Update()
{
	if((SDL_GetTicks() - GetSplashTimer()) > SPLASHDELAY) //se a splashscreen está tempo o suficiente na tela, vai para o main menu
		return true;
	else
		return false;
}
