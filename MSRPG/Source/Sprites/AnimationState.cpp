#include "AnimationState.h"


AnimationState::AnimationState()
{

}

AnimationState::~AnimationState()
{
	std::size_t vectorSize = spriteFrameList.size();

	for (int i=0; i < vectorSize; i++)
	{
		delete spriteFrameList[i];
		spriteFrameList[i] = NULL;
	}
}

SpriteFrame* AnimationState::GetSpriteFrame(int _spriteFrameIndex)
{
	return spriteFrameList[_spriteFrameIndex];
}

void AnimationState::NewSpriteFrame()
{
	spriteFrameList.push_back(new SpriteFrame());
}

int AnimationState::GetSpriteFrameVectorSize()
{
	std::size_t vectorSize = spriteFrameList.size();
	return (int)vectorSize;
}
