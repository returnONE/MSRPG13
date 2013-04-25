#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(unsigned int _animationID)
{
	image = ListManager::GetListManager()->GetMyImageList()->GetNode(AnimationManager::GetAnimationManager()->GetAnimationData(_animationID)->imageID)->GetNodeData()->GetImage();
	imageID = AnimationManager::GetAnimationManager()->GetAnimationData(_animationID)->imageID;
	lastTime = NULL;
	lastState = NULL;
	lastLoadedState = NULL;
	spriteFrameIndex = 0;
}

AnimatedSprite::~AnimatedSprite()
{
	std::size_t vectorSize = animationStateList.size();
	
	for (int i=0; i < vectorSize; i++)
	{
		delete animationStateList[i];
		animationStateList[i] = NULL;
	}
}

void AnimatedSprite::NewAnimationState()
{
	animationStateList.push_back(new AnimationState());
}

AnimationState* AnimatedSprite::GetAnimationState(int _stateIndex)
{
	return animationStateList[_stateIndex];
}

SpriteFrame* AnimatedSprite::GetCurrentSpriteFrame(int _state, int _animationTime)
{
	int vectorSize = animationStateList[_state]->GetSpriteFrameVectorSize();

	if(this->lastState != _state)
	{
		spriteFrameIndex = 0;
		lastTime = SDL_GetTicks();
		lastState = _state;
		return animationStateList[_state]->GetSpriteFrame(spriteFrameIndex);
	}

	if( (SDL_GetTicks() - lastTime) > _animationTime)
	{
		spriteFrameIndex++;
		lastTime = SDL_GetTicks();

		if(vectorSize == spriteFrameIndex) //se não há mais sprites no vetor, volta pro primeiro
			spriteFrameIndex = 0;
	}

	return animationStateList[_state]->GetSpriteFrame(spriteFrameIndex);
}

void AnimatedSprite::SetImage( GLuint _image )
{
	image = _image;
}

void AnimatedSprite::SetImageID( int _imageID )
{
	imageID = _imageID;
}

GLuint AnimatedSprite::GetImage()
{
	return image;
}

GLuint* AnimatedSprite::GetImageAsPointer()
{
	GLuint* tmpPointer = &image;
	return tmpPointer;
}

int AnimatedSprite::GetImageID()
{
	return imageID;
}
