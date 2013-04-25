#include "ImageFile.h"

ImageFile::ImageFile(GLuint _image)
{
	image = _image;
}

ImageFile::~ImageFile()
{
	glDeleteTextures( 1, this->GetImageAsPointer() );
}

GLuint ImageFile::GetImage()
{
	return image;
}


GLuint* ImageFile::GetImageAsPointer()
{
	GLuint* tmpPointer = &image;
	return tmpPointer;
}

void ImageFile::SetImage( GLuint _image )
{
	image = _image;
}

int ImageFile::GetImageW() const
{
	return imageW;
}

void ImageFile::SetImageW( int _imageW )
{
	imageW = _imageW;
}

int ImageFile::GetImageH() const
{
	return imageH;
}

void ImageFile::SetImageH( int _imageH )
{
	imageH = _imageH;
}