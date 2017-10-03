#include <SDL.h>

class Fps {
	private:
		Uint32 preTime;
		Uint32 nowTime = SDL_GetTicks();
		int frameCount = 1;
		Uint32 timeCount = 0;
		double fps = 0.0;
		const Uint32 mspf = 1000 / 60;

	public:
		Fps() = default;
		~Fps() = default;
		double delay();
		double wait();
};
