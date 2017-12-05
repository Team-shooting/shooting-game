#include <fps.h>

#include <iostream>

void Fps::Update()
{
	if (frameCount == 0) {
		mStartTime = SDL_GetTicks();
	} else if (frameCount == N) {
		Uint32 t = SDL_GetTicks();
		//型に注意
		mfps = static_cast<double>(N) / static_cast<double>(t - mStartTime) * 1000.0;
		frameCount = 0;
		mStartTime = t;
	}

	frameCount++;
}

void Fps::delay()
{
	Uint32 tookTime = SDL_GetTicks() - mStartTime;
	Uint32 waitTime = static_cast<Uint32>(frameCount) * static_cast<Uint32>(1000) / FPS - tookTime;

	//Uint32 : unsigned int ?
	if (static_cast<int>(waitTime) > 0) {
		SDL_Delay(waitTime);
	}
}

double Fps::getFps()
{
	return mfps;
}

