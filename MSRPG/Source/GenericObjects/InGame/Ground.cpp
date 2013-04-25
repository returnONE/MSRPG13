#include "Ground.h"

Ground::Ground(unsigned int _animationID, int _state, int _objectID, int _xGlobalPosition, int _yGlobalPosition):
InGameObject(_animationID, _state, _objectID, _xGlobalPosition, _yGlobalPosition)
{
}

Ground::~Ground(void)
{
}
