#include "SpriteFrame.h"


SpriteFrame::SpriteFrame()
{

}

SpriteFrame::~SpriteFrame()
{
	std::size_t vectorSize = spriteList.size();

	for (int i=0; i < vectorSize; i++)
	{
		delete spriteList[i];
		spriteList[i] = NULL;
	}
}

void SpriteFrame::NewSprite()
{
	spriteList.push_back(new Sprite());
}

Sprite* SpriteFrame::GetSprite( int _spriteIndex )
{
	return spriteList[_spriteIndex];
}

Sprite* SpriteFrame::GetLatestSpriteAdded()
{
	int index = GetSpriteVectorSize();
	return spriteList[index-1];
}

int SpriteFrame::GetSpriteVectorSize()
{
	std::size_t vectorSize = spriteList.size();
	return (int)vectorSize;
}
