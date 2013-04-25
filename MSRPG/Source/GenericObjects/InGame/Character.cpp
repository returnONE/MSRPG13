#include "Character.h"

Character::Character(unsigned int _animationID, int _state, int _objectID, int _xGlobalPosition, int _yGlobalPosition):
InGameObject(_animationID, _state, _objectID, _xGlobalPosition, _yGlobalPosition)
{
	this->SetAnimationTime(200);
}

Character::~Character()
{

}

void Character::Setup()
{

}

bool Character::Update()
{
	return 1;
}
