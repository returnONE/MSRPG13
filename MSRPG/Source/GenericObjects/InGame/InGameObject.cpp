#include "InGameObject.h"

InGameObject::InGameObject(unsigned int _animationID, int _state, unsigned int _objectID, int _xGlobalPosition, int _yGlobalPosition):
GenericObject(_animationID, _state), objectID(_objectID)
{
	this->SetGlobalPosition(_xGlobalPosition, _yGlobalPosition);
}

InGameObject::~InGameObject(void)
{
}

void InGameObject::SetGlobalPosition( int _xGlobalPosition, int _yGlobalPosition )
{
	mGlobalPosition.xGlobalPosition = _xGlobalPosition;
	mGlobalPosition.yGlobalPosition = _yGlobalPosition;
}
