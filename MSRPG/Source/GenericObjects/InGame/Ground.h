#ifndef	GROUND_H_
#define GROUND_H_

#include "IngameObject.h"

class Ground : public InGameObject
{
public:
	Ground(unsigned int _animationID, int _state, int _objectID, int _xGlobalPosition, int _yGlobalPosition);
	~Ground(void);
};

#endif