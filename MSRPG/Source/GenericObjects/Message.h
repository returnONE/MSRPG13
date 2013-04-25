#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "SDL.h"

#include <windows.h>
#include <GL/glu.h>
#include <string>

#include "FontCharset.h"
#include "FontManager.h"

//using namespace std;

class Message
{
public:
	Message(std::string _myString, int _charsetCode, float _x, float _y, int _lifeTime);
	~Message();

	//sets e gets
	int GetLifeTime() const;
	void SetLifeTime(int _lifetime);

	int GetMessageX() const;
	void SetMessageX(int _imageW);
	int GetMessageY() const;
	void SetMessageY(int _imageH);

	std::string GetMyString() const;
	void SetMyString(std::string _string);

	Charset* GetMyCharSet() const;

	//outras
	bool VerifyMessageDuration();

private:
	std::string myString;

	int charsetCode;

	float x;
	float y;

	int lifeTime; //0 if not temporary
	int creationTime;
};


#endif