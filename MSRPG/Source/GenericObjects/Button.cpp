#include "Button.h"


Button::Button(unsigned int _animationID, int _state, int _sceneState):
GenericObject(_animationID, _state)
{
	//state = _state;
	sceneState = _sceneState;
	SetAnimationTime(500);
	//InitializeOffsetValues(_imageW, _imageH);
}

Button::~Button()
{

}

bool Button::IsButtonArea( int _x, int _y )
{
	_x -= SDL_GetVideoInfo()->current_w;
	_x *= -1;
	_y -= SDL_GetVideoInfo()->current_h;
	_y *= -1;

	if(_x > GetScreenX0() && _x < GetScreenX1() &&
		_y > GetScreenY0() && _y < GetScreenY1())
		return TRUE;
	else
		return FALSE;
}

int Button::IsPressed() const
{
	if(GetState() == PRESSED)
		return sceneState;
	else
		return -1;
}
