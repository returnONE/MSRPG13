#include "RenderManager.h"

#include "SDL.h"

RenderManager* RenderManager::s_RenderManager = 0;

RenderManager* RenderManager::GetRenderManager (void) 
{

	if (s_RenderManager == 0)
	{
		s_RenderManager = new RenderManager;
		s_RenderManager->lastImage = NULL;
	}
	return s_RenderManager;
}

void RenderManager::RenderSprite( SpriteFrame* _spriteFrame, float _screenX0, float _screenY0, float _screenX1, float _screenY1, GLuint _image)
{
	if(lastImage != _image)
	{
		glBindTexture(GL_TEXTURE_2D, _image);
		lastImage = _image;
	}

	for(int i=0; i <= (_spriteFrame->GetSpriteVectorSize() - 1); i++)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		float finalScreenX0 = _screenX0 + _spriteFrame->GetSprite(i)->GetXRelative();
		float finalScreenX1 = _screenX1 + _spriteFrame->GetSprite(i)->GetXRelative();
		float finalScreenY0 = _screenY0 + _spriteFrame->GetSprite(i)->GetYRelative();
		float finalScreenY1 = _screenY1 + _spriteFrame->GetSprite(i)->GetYRelative();

		//transformação do offset da tela:
		TransformScreenOffset(finalScreenX0, finalScreenY0, finalScreenX1, finalScreenY1);

		GLfloat vertices[] = {screenX0Transformed, screenY0Transformed, screenX0Transformed, screenY1Transformed,  screenX1Transformed, screenY1Transformed, screenX1Transformed, screenY0Transformed}; //coordenadas da tela. le-se de 2 em 2.
		glVertexPointer(2, GL_FLOAT, 0, vertices); //le-se de 2 em 2, tipo float, sem espaçamento entre os vertices, array de vertices

		GLfloat textureVertices[] = {_spriteFrame->GetSprite(i)->GetTextureX0(), _spriteFrame->GetSprite(i)->GetTextureY1(),
			_spriteFrame->GetSprite(i)->GetTextureX0(), _spriteFrame->GetSprite(i)->GetTextureY0(),
			_spriteFrame->GetSprite(i)->GetTextureX1(), _spriteFrame->GetSprite(i)->GetTextureY0(),
			_spriteFrame->GetSprite(i)->GetTextureX1(), _spriteFrame->GetSprite(i)->GetTextureY1()};

		glTexCoordPointer(2, GL_FLOAT, 0,  textureVertices); //le-se de 2 em 2, tipo float, sem espaçamento entre os vertices, array de vertices

		GLubyte indices[] = {0,1,2,3,4,5,6,7}; //ordem pro array ser lido

		glPushMatrix();
		glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices); //substitui render com glBegin/glEnd
		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);	
	}
}

void RenderManager::RenderFont(string _string, Charset* _charSet, float _x, float _y)
{
	if(lastImage != _charSet->image)
	{
		glBindTexture(GL_TEXTURE_2D,  _charSet->image);
		lastImage =  _charSet->image;
	}

	for(int i=0; i < _string.size(); i++)
	{
		int currentGlyph = (int)_string[i];

		if(currentGlyph < 0) //caracteres especiais são devolvidos com sinal, precisando ser transformados de volta
			currentGlyph += 256;

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		float screenX0, screenY0, screenX1, screenY1;
		screenX0 = _x        + _charSet->Chars[currentGlyph].XOffset;
		screenY0 = _y        - _charSet->Chars[currentGlyph].YOffset;
		screenX1 = screenX0  + _charSet->Chars[currentGlyph].Width;
		screenY1 = screenY0  - _charSet->Chars[currentGlyph].Height;

		TransformScreenOffset(screenX0, screenY0, screenX1, screenY1);

		GLfloat vertices[] = {screenX0Transformed, screenY0Transformed, screenX0Transformed, screenY1Transformed,  screenX1Transformed, screenY1Transformed, screenX1Transformed, screenY0Transformed}; //coordenadas da tela. le-se de 2 em 2.
		glVertexPointer(2, GL_FLOAT, 0, vertices); //le-se de 2 em 2; tipo float; sem espaçamento entre os vertices; array de vertices

		//posição na textura:
		float textureX0, textureY0, textureX1, textureY1;
		textureX0 = _charSet->Chars[currentGlyph].x;
		textureY0 = _charSet->Chars[currentGlyph].y;
		textureX1 = _charSet->Chars[currentGlyph].x + _charSet->Chars[currentGlyph].Width;
		textureY1 = _charSet->Chars[currentGlyph].y + _charSet->Chars[currentGlyph].Height;

		TransformTextureOffset(textureX0, textureY0, textureX1, textureY1, _charSet);

		GLfloat textureVertices[] = {textureX0, textureY0,
			textureX0, textureY1,
			textureX1, textureY1,
			textureX1, textureY0};


		glTexCoordPointer(2, GL_FLOAT, 0,  textureVertices); //le-se de 2 em 2, tipo float, sem espaçamento entre os vertices, array de vertices

		GLubyte indices[] = {0,1,2,3,4,5,6,7}; //ordem pro array ser lido

		glPushMatrix();
		glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices); //substitui render com glBegin/glEnd
		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);	

		_x += _charSet->Chars[currentGlyph].XAdvance; //passo pra frente pra ficarmos na posição do proximo glyph
	}


}

void RenderManager::TransformScreenOffset( float _screenX0, float _screenY0, float _screenX1, float _screenY1 )
{
	screenX0Transformed = OffsetTransformationWidth(_screenX0);
	screenY0Transformed = OffsetTransformationHeight(_screenY0);
	screenX1Transformed = OffsetTransformationWidth(_screenX1);
	screenY1Transformed = OffsetTransformationHeight(_screenY1);
}

float RenderManager::OffsetTransformationWidth( float _offset )
{
	float transformedOffset = (float)_offset/((float)SDL_GetVideoInfo()->current_w/2); //converte o int pra float na proporção de 0 a 2
	transformedOffset = transformedOffset - 1; //converte o int pra float na proporção de -1 a 1
	return transformedOffset;
}

float RenderManager::OffsetTransformationHeight( float _offset )
{
	float transformedOffset = (float)_offset/((float)SDL_GetVideoInfo()->current_h/2); //converte o int pra float na proporção de 0 a 2
	transformedOffset = transformedOffset - 1; //converte o int pra float na proporção de -1 a 1
	return transformedOffset;
}

void RenderManager::TransformTextureOffset( float &_textureX0, float &_textureY0, float &_textureX1, float &_textureY1, Charset* _charSet )
{
	_textureX0 = _textureX0 / _charSet->Width;
	_textureY0 = _textureY0 / _charSet->Height;
	_textureX1 = _textureX1 / _charSet->Width;
	_textureY1 = _textureY1 / _charSet->Height;
}

GLuint RenderManager::GetImage() const
{
	return image;
}

SDL_Surface* RenderManager::GetLocalSurface()
{
	SDL_Surface* tmpPointer;
	tmpPointer = &localSurface;
	return tmpPointer;
}

GLuint RenderManager::LoadTexture( const char* fileName )
{
	SDL_Surface*  surface = IMG_Load(fileName);

	if (!surface) {
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());
		SDL_Quit();
	}

	localSurface = *surface;

	glGenTextures(1, &image); //OpenGL te da somente um indice do vetor que ele criou pra alocar as imagens. a imagem em si nao e retornada
	glBindTexture(GL_TEXTURE_2D, image);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

	SDL_FreeSurface(surface);

	return image;
}

void RenderManager::SceneExchange()
{
	lastImage = NULL;
}
