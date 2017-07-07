#pragma once
#include <SDL.h>
#include "fps.h"

class System {
	bool sdl_initialize();
	void sdl_finalize();
	void main_loop();

	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Event event;

	Fps fps;

	char title[20] = "Shooting-Gmae";
	const int width = 800;
	const int height = 600;


	public:
		System() = default;
		~System() = default;

		void run();
};
