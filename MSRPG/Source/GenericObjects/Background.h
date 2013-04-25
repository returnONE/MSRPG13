#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "GenericObject.h"

class Background : public GenericObject
{

public:
	Background(unsigned int _animationID, int _state);
	~Background();
};


#endif