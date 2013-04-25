#ifndef SPRITEFRAME_H_
#define SPRITEFRAME_H_

#include <windows.h>
#include "GL/gl.h"

#include "Sprite.h"

#include <vector>

using namespace std;

class SpriteFrame //abstract class to point sprites
{
public:
	SpriteFrame();
	~SpriteFrame();

	//gets and sets
	void NewSprite();
	Sprite* GetSprite(int _spriteIndex);
	Sprite* GetLatestSpriteAdded();
	int GetSpriteVectorSize();

private:

	vector<Sprite*> spriteList;

};

#endif
