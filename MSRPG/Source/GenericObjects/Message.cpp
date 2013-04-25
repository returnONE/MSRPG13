#include "Message.h"

Message::Message(std::string _myString, int _charsetCode, float _x, float _y, int _lifeTime):
myString(_myString),
charsetCode(_charsetCode),
x(_x),
y(_y),
lifeTime(_lifeTime),
creationTime(SDL_GetTicks())
{

}

Message::~Message()
{
	//glDeleteTextures( 1, this->GetMyAnimatedSprite()->GetImageAsPointer());
}

int Message::GetLifeTime() const
{
	return lifeTime;
}

void Message::SetLifeTime( int _lifetime )
{
	lifeTime = _lifetime;
}

bool Message::VerifyMessageDuration() //retorna falso caso a msg deve ser deletada
{
	if(lifeTime != 0)
	{
		int timeNow = SDL_GetTicks();
		if (timeNow > creationTime + lifeTime)
			return false;
		else
			return true;
	}
	else
		return true;
}

int Message::GetMessageX() const
{
	return x;
}

void Message::SetMessageX( int _x )
{
	x = _x;
}

int Message::GetMessageY() const
{
	return y;
}

void Message::SetMessageY( int _y )
{
	y = _y;
}

std::string Message::GetMyString() const
{
	return myString;
}

void Message::SetMyString( std::string _string )
{
	myString = _string;
}

Charset* Message::GetMyCharSet() const
{
	return FontManager::GetFontManager()->GetMyCharsetList()->GetNode(charsetCode)->GetNodeData();
}
