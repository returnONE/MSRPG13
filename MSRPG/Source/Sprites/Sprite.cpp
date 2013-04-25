#include "Sprite.h"

#include "SDL.h"

#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

float Sprite::GetTextureX0() const
{
	return textureX0;
}

void Sprite::SetTextureX0( int _textureX0, int _textureTotalW )
{
	textureX0 = (float)_textureX0 / (float)_textureTotalW;
}

float Sprite::GetTextureX1() const
{
	return textureX1;
}

void Sprite::SetTextureX1( int _textureX1, int _textureTotalW  )
{
	textureX1 = (float)_textureX1 / (float)_textureTotalW;
}

float Sprite::GetTextureY0() const
{
	return textureY0;
}

void Sprite::SetTextureY0( int _textureY0, int _textureTotalH  )
{
	textureY0 = (float)_textureY0 / (float)_textureTotalH;
}

float Sprite::GetTextureY1() const
{
	return textureY1;
}

void Sprite::SetTextureY1( int _textureY1, int _textureTotalH  )
{
	textureY1 = (float)_textureY1 / (float)_textureTotalH;
}

void Sprite::SetSpriteTextureOffset(int _x0, int _x1, int _y0, int _y1, int _xRelative, int _yRelative, int _imageWidth, int _imageHeight)
{
	SetTextureX0(_x0, _imageWidth);
	SetTextureX1(_x1, _imageWidth);
	SetTextureY0(_y0, _imageHeight);
	SetTextureY1(_y1, _imageHeight);
	SetXRelative(_xRelative);
	SetYRelative(_yRelative);
}

float Sprite::GetXRelative() const
{
	return xRelative;
}

void Sprite::SetXRelative( int _xRelative )
{
	xRelative = _xRelative;
}

float Sprite::GetYRelative() const
{
	return yRelative;
}

void Sprite::SetYRelative( int _yRelative )
{
	yRelative = _yRelative;
}
