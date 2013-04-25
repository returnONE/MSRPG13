#ifndef IMAGEFILE_H_
#define IMAGEFILE_H_

#include <windows.h>
#include <GL/gl.h>

class ImageFile
{
public:
	ImageFile(GLuint _image);
	~ImageFile();

	//sets e gets
	GLuint GetImage();
	GLuint* GetImageAsPointer();
	void SetImage(GLuint _image);

	int GetImageW() const;
	void SetImageW(int _imageW);
	int GetImageH() const;
	void SetImageH(int _imageH);

private:
	GLuint image;

	int imageW;
	int imageH;
};


#endif