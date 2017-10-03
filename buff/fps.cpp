#include <SDL.h>
#include <cstdlib>
#include "fps.h"


double Fps::delay()
{
	nowTime = SDL_GetTicks();

	if (timeCount >= 1000) {
		fps = (double)frameCount / ((double)timeCount / 1000.0);
		timeCount = 0;
		frameCount = 0;
	}

	Uint32 diff = nowTime - preTime;
	preTime = nowTime;

	if (mspf > diff) {
		SDL_Delay(mspf - diff);
	}

	frameCount++;
	timeCount += diff;

	//printf("Frame : %hd, Time : %hd, diff : %hd\n", frameCount, timeCount, diff);

	return fps;
}


