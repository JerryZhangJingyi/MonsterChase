#include "Timer.h"

float _Timer::Tick(float deltaTime, clock_t beginFrame, clock_t endFrame)
{
	//counting milliseconds
	deltaTime = float(clock() - beginFrame) / (CLOCKS_PER_SEC / 1000);
	return deltaTime;
}

