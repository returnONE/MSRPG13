#ifndef SPRITE_H_
#define SPRITE_H_

#include <windows.h>
#include "GL/gl.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	//gets and sets
	float GetTextureX0() const;
	void SetTextureX0(int _textureX0, int _textureTotalW);
	float GetTextureX1() const;
	void SetTextureX1(int _textureX1, int _textureTotalW);
	float GetTextureY0() const;
	void SetTextureY0(int _textureY0, int _textureTotalH);
	float GetTextureY1() const;
	void SetTextureY1(int _textureY1, int _textureTotalH);
	float GetXRelative() const;
	void SetXRelative(int _xRelative);
	float GetYRelative() const;
	void SetYRelative(int _yRelative);
	void SetSpriteTextureOffset(int _x0, int _x1, int _y0, int _y1, int _xRelative, int _yRelative, int _imageWidth, int _imageHeight);

private:

	float textureX0; //sprite só mantem a posição do sprite no arquivo da imagem
	float textureX1; //quem sabe sua posição na tela é a scene
	float textureY0;
	float textureY1;

	float xRelative; //posição relativa à posição original
	float yRelative;
};

#endif
