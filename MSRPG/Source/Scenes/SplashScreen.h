#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "SDL.h"
#include "SDL_image.h"

#include "Scene.h"
#include "Splash.h"


class SplashScreen : public Scene
{
public:
	SplashScreen();
	~SplashScreen();

	//inherited from Scene
	void SplashScreen::Setup();
	void SplashScreen::Input();
	void SplashScreen::Update();
	//void SplashScreen::Draw();
	void SplashScreen::TearDown();
	
private:
	Splash* FirstSplash; //instancia da GenericObject
};

#endif