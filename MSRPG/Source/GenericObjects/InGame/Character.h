#ifndef CHARACTER_H_
#define CHARACTER_H_


#include "InGameObject.h"

enum
{
	STAND_UP
	,STAND_RIGHT
	,STAND_DOWN
	,STAND_LEFT
	,WALKING_UP
	,WALKING_RIGHT
	,WALKING_DOWN
	,WALKING_LEFT
};


class Character : public InGameObject
{
public:
	Character(unsigned int _animationID, int _state, int _objectID, int _xGlobalPosition, int _yGlobalPosition);
	~Character();

	//gets e sets
	void Setup();

	//outras
	bool Update(); //virtual


private:

	int CharacterTimer;
};


#endif