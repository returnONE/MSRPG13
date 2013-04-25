#ifndef	FIXEDOBJECTS_H_
#define FIXEDOBJECTS_H_

#include "IngameObject.h"

class FixedObject : public InGameObject
{
public:
	FixedObject(unsigned int _animationID, int _state, int _objectID, int _xGlobalPosition, int _yGlobalPosition);
	~FixedObject(void);
};

#endif