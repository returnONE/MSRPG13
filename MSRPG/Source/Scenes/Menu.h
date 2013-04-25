#ifndef MENU_H_
#define MENU_H_

#include <string>

#include "Scene.h"
#include "Button.h"
//#include "Message.h"
#include "FPSControl.h"

#include "SDL_mixer.h"
#include "SDL.h"
#include "SDL_image.h"

#include <windows.h>
#include <GL/glu.h>


//#define FONTTEXTURE 202

#define SWORDSFX 101

#define MENUMUSIC 101


#define BUTTONFILE "Data/Images/ButtonRaw.png"
#define MUSICFILE "Data/Sound/music.mp3"
#define SFXFILE "Data/Sound/sword01.wav"
#define FILE_FONT_CENTURY_GOTHIC "Data/Font/CenturyGothic_0.png"


class Menu : public Scene
{
public:
	Menu();
	~Menu();

	//herdadas
	void Menu::Setup();
	void Menu::Input();
	void Menu::Update();
	//void Menu::Draw();
	void Menu::TearDown();

	//outras
	void SetImageScreenOffsets();
	void VerifyPressedButtons(int _x, int _y);
	void VerifyMouseOverButtons(int _x, int _y);

private:
	Button* Button1;
	Button* Button2;
	Button* Button3;

};

#endif