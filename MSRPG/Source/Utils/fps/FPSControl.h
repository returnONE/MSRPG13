#ifndef FPSCONTROL_H_
#define FPSCONTROL_H_

#define TOTALFRAMETIME 1000.0f/60.0f

#include "SDL.h"

class FPSControl
{
public:
	FPSControl();
	~FPSControl();

	//gets e sets
	void SetInitialFrameTime(Uint32 _time);
	void SetInitialOneSecondTime(Uint32 _time);
	Uint32 GetCurrentFPS() const;

	//outras
	void AddToFrameCounter();
	bool VerifyFrameEnd();

private:

	Uint32 initialFrameTime;
	Uint32 initialOneSecondTime;
	int frameCounter;

	Uint32 currentFPS;
};

extern FPSControl *g_TheFPSControl;


#endif