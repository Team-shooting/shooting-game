#include <SDL.h>

class Fps {
	private:
		Uint32 preTime = SDL_GetTicks();
		Uint32 now;
		double fps;
		const Uint32 mspf = 1000 / 60;

		Uint32 stotalTime = 0;
		int frameCount = 0;
		char drawFps[10];

	public:
		Fps() = default;
		~Fps() = default;
		double delay();
};