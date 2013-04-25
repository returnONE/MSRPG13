#ifndef ANIMATIONSTATE_H_
#define ANIMATIONSTATE_H_

#include "SpriteFrame.h"

class AnimationState //abstract class to point sprites
{
public:
	AnimationState();
	~AnimationState();

	//gets and sets
	SpriteFrame* GetSpriteFrame(int _spriteFrameIndex);
	int GetSpriteFrameVectorSize();

	void NewSpriteFrame();

private:

	int animationTime;

	vector<SpriteFrame*> spriteFrameList;

};

#endif
