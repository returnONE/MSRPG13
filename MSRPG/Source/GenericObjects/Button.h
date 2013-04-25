#ifndef BUTTON_H_
#define BUTTON_H_

#include "GenericObject.h"
#include "AnimationManager.h" //descobrir outro lugar pra por

#include "SDL.h"

enum
{
	NORMAL
	,PRESSED
	,MOUSE_OVER
	,DESABILITADO
};

class Button : public GenericObject
{
public:
	Button(unsigned int _animationID, int _state, int _sceneState);
	~Button();

	//outras
	bool IsButtonArea(int _x, int _y);
	int IsPressed() const;


private:
	int sceneState; //scene pra qual esse botão leva

};

#endif
