#ifndef CREDITOS_H_
#define CREDITOS_H_

#include "Scene.h"
#include "Button.h"
#include "Background.h"

class Creditos : public Scene
{
public:
	Creditos();
	~Creditos();

	//inherited
	void Creditos::Setup();
	void Creditos::Input();
	void Creditos::Update();
	//void Creditos::Draw();
	void Creditos::TearDown();

	//gets e sets


	//outras
	void SetScreenOffsets();
	void VerifyButtons(int _x, int _y);

private:

	Button* Button1;
	Background* CreditosBackground;
};

#endif