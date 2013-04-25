#ifndef	MOVABLEPICKABLEOBJECT_H_
#define MOVABLEPICKABLEOBJECT_H_

#include "IngameObject.h"

class MovablePickableObject : public InGameObject
{
public:
	MovablePickableObject(unsigned int _animationID, int _state, int _objectID, int _xGlobalPosition, int _yGlobalPosition);
	~MovablePickableObject(void);
};

#endif