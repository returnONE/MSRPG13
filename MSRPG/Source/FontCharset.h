#ifndef FONTCHARSET_H_
#define FONTCHARSET_H_

#include <windows.h>
#include <GL/glu.h>


struct CharDescriptor
{
	float x, y;
	float Width, Height;
	float XOffset, YOffset;
	float XAdvance;
	float Page;

	CharDescriptor() : x( 0 ), y( 0 ), Width( 0 ), Height( 0 ), XOffset( 0 ), YOffset( 0 ),XAdvance( 0 ), Page( 0 )
	{ }
};

struct Charset
{
	GLuint image;
	float LineHeight;
	float Base;
	float Width, Height;
	float Pages;
	CharDescriptor Chars[256];
};

#endif
