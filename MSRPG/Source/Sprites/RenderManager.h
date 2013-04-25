#ifndef RenderManager_H_
#define RenderManager_H_

//#include "FontManager.h"
#include "SpriteFrame.h"
#include "FontCharset.h"

#include <windows.h>
#include <GL/glu.h>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"

class RenderManager
{
public:
	static class RenderManager *s_RenderManager;
	static RenderManager *GetRenderManager (void);

	void RenderSprite( SpriteFrame* _spriteFrame, float _screenX0, float _screenY0, float _screenX1, float _screenY1, GLuint _image);
	void RenderFont(string _string, Charset* _charSet, float _x, float _y);
	void TransformScreenOffset(float _screenX0, float _screenY0, float _screenX1, float _screenY1);
	float OffsetTransformationWidth(float _offset);
	float OffsetTransformationHeight(float _offset);
	void TransformTextureOffset(float &_textureX0, float &_textureY0, float &_textureX1, float &_textureY1, Charset* _charSet);

	GLuint GetImage() const;
	SDL_Surface* GetLocalSurface();

	//other
	GLuint LoadTexture(const char* fileName);
	void SceneExchange();

private:

	GLuint image;
	SDL_Surface  localSurface;

	GLuint lastImage;

	float screenX0Transformed; // object position on screen
	float screenY0Transformed;
	float screenX1Transformed;
	float screenY1Transformed;
};


#endif