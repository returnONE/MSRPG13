#ifndef ANIMATIONMANAGER_H_
#define ANIMATIONMANAGER_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "rapidxml.hpp"


using namespace std;
using namespace rapidxml;

struct SpriteData
{
	float xTex0;
	float yTex0;
	float xTex1;
	float yTex1;

	float xRelative;
	float yRelative;
};

struct FrameData
{
	unsigned int frameCode;
	vector <SpriteData> spriteList;
};

struct StateData
{
	unsigned int stateCode;
	vector <FrameData> frameList;
};

struct AnimationData
{
	unsigned int animationCode;
	unsigned int imageID;
	vector <StateData> stateList;
};

class AnimationManager //administra geração de sprites animados com suas respectivas animações
{

private:

	vector <AnimationData> animationList;

public:

	static class AnimationManager *s_AnimationManager;
	static AnimationManager *GetAnimationManager (void);

	AnimationData* GetAnimationData(unsigned int _animationCode);
	void ParseAnimationXML();
};

#endif
