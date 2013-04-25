#include "StaticSprite.h"

StaticSprite::StaticSprite()
{

}

StaticSprite::~StaticSprite()
{

}

Sprite* StaticSprite::GetMySprite() const
{
	return mySprite;
}

void StaticSprite::SetMySprite( Sprite* _sprite )
{
	mySprite = _sprite;
}
