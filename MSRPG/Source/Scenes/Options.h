#ifndef OPTIONS_H_
#define OPTIONS_H_

#include "Scene.h"
#include "GenericObjects/Button.h"
#include "Background.h"


class Options : public Scene
{
public:
	Options();
	~Options();

	//inherited
	void Options::Setup();
	void Options::Input();
	void Options::Update();
	//void Options::Draw();
	void Options::TearDown();

	//outras
	void SetScreenOffsets();
	void VerifyButtons(int _x, int _y);

private:

	Button* Button1;
	Background* OptionsBackground;
};

#endif