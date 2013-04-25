#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include "SDL.h"

//#include "SpriteFrame.h"
#include "ListManager.h"
#include "AnimationManager.h"
#include "AnimationState.h"

#include <vector>

class ListManager;

using namespace std;

class AnimatedSprite //abstract class to point sprites
{
public:
	AnimatedSprite(unsigned int _animationID);
	~AnimatedSprite();

	//gets and sets
	AnimationState* GetAnimationState(int _stateIndex);
	void SetImage(GLuint _image);
	GLuint GetImage();
	GLuint* GetImageAsPointer();
	int GetImageID();
	void SetImageID(int _imageID);
	SpriteFrame* GetCurrentSpriteFrame(int _stateIndex, int _animationTime);

	void NewAnimationState();

private:
	//todos sprites do animatedSprite estarão sempre no mesmo spritesheet
	int imageID;
	GLuint image;

	vector<AnimationState*> animationStateList;

	int lastLoadedState;

	int lastTime;
	int lastState;
	int spriteFrameIndex;

};

#endif
