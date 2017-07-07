#include <SDL.h>
#include <cstdlib>
#include "fps.h"

double Fps::delay()
{
	now = SDL_GetTicks();

	Uint32 diff = now - preTime;
	if (diff < mspf) SDL_Delay(mspf - diff);

	//stotalTime += diff;
	//frameCount++;

	fps = 1.0 / static_cast<double>(SDL_GetTicks() - preTime) * 1000.0;

	preTime = now;

	return fps;
}

	/*
	//Caution SDL_SetWindowTitle need SDL_Window object you use directly
	static char fps[10];

	if (stotalTime > 1000) {
		sprintf(fps, "%.3f", (double)frameCount / (double)stotalTime * 1000.0);
		SDL_SetWindowTitle(*win, fps);

		frameCount = 0;
		stotalTime = 0;
	*/
