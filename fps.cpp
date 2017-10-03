#include <SDL.h>
#include <cstdlib>
#include "fps.h"


void Fps::delay()
{
	if (timeCount >= 1000) {
		fps = static_cast<double>(frameCount) / (static_cast<double>(timeCount) / 1000.0);
		timeCount = 0;
		frameCount = 0;
	}

	frameCount++;

	nowTime = SDL_GetTicks();

	Uint32 diff = nowTime - preTime;

	preTime = nowTime;

	if (mspf > diff) {
		SDL_Delay(mspf - diff);
	}

	timeCount += diff;
}

double Fps::getFps()
{
	return fps;
}


