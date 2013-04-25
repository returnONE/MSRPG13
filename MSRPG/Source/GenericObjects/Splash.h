#ifndef SPLASH_H_
#define SPLASH_H_

#define SPLASHDELAY 1000

#include "GenericObject.h"


class Splash : public GenericObject
{
public:
	Splash(unsigned int _animationID, int _state);
	~Splash();

	//gets e sets
	void Setup(int _splashTimer);
	int  GetSplashTimer() const;

	//outras
	bool Update(); //virtual


private:

	int splashTimer;
};


#endif
