#ifndef GENERICOBJECT_H_
#define GENERICOBJECT_H_

#include "Sprite.h"
#include "AnimatedSprite.h"
#include "AnimationManager.h"
#include "Constants.h"

#include <windows.h>
#include "GL/gl.h"

#include "SDL.h"


//classe abstrata que aponta um objeto na cena e o linka com seu(s) respectivo(s) sprite(s) e som(s)
class GenericObject
{

public:
	//constructor:
	GenericObject(unsigned int _animationID, int _state);
	GenericObject();

	//destructor:
	virtual ~GenericObject();

	//sets and gets
	AnimatedSprite* GetMyAnimatedSprite();
	int GetState() const;
	void SetState(int _state);
	int GetAnimationTime() const;
	void SetAnimationTime(int _animationTime);

	int GetScreenX0() const;
	void SetScreenX0(int _x);
	int GetScreenX1() const;
	void SetScreenX1(int _x);
	int GetScreenY0() const;
	void SetScreenY0(int _y);
	int GetScreenY1() const;
	void SetScreenY1(int _y);

	void SetVisibility(bool _visible);
	bool IsVisible();

	//others

	virtual bool Update();
	virtual void Setup();


	void SetTexture(AnimationData* _animationData);

private:

	bool visible;

	float screenX0; // object position on screen
	float screenY0;
	float screenX1;
	float screenY1;

	AnimatedSprite* myAnimatedSprite;
	int state; //estado do objeto (andando esquerda, parado direita, etc)

	int animationTime;

};


#endif