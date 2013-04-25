#ifndef STATICSPRITE_H_
#define STATICSPRITE_H_

#include "Sprite.h"

class StaticSprite //abstract class to point sprites
{
public:
	StaticSprite();
	~StaticSprite();

	//gets and sets
	Sprite* GetMySprite() const;
	void SetMySprite(Sprite* _sprite);

private:
	Sprite* mySprite;

};

#endif