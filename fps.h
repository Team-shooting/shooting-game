#pragma once
#include <SDL.h>

class Fps {
	Uint32 mStartTime = 0;
	int frameCount = 0;
	double mfps = 0;
	static const int N = 60;
	static const Uint32 FPS = 60;

public:
	Fps() = default;
	~Fps() = default;
	void Update();
	void delay();
	double getFps();
};
