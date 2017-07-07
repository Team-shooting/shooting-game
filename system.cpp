#include <SDL.h>
#include <iostream>
#include "system.h"

bool System::sdl_initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING  < 0)) {
		std::cerr << "Faild to initialize" << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (window == NULL) {
		std::cerr << "Faild to create window" << std::endl;
		return false;
	}

	render = SDL_CreateRenderer(window, -1, 0);
	if (render == NULL) {
		std::cerr << "Faild to create render" << std::endl;
		return false;
	}

	return true;
}

void System::sdl_finalize() {
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void System::main_loop() {
	bool flag = true;
	char valFps[10];
	int frameCount = 0;

	while (flag) {
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_RenderClear(render);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				flag = false;
			}
		}

		SDL_SetRenderDrawColor(render, 0, 0, 0, 255); 
		SDL_RenderDrawLine(render, 10, 10, 400, 400);
		SDL_RenderPresent(render);


		sprintf(valFps, "%f", fps.delay());
		if (frameCount % 60 == 59) {
			SDL_SetWindowTitle(window, valFps);
		}
		frameCount++;
	}
}

void System::run()
{
	if (sdl_initialize()) {
		main_loop();
		sdl_finalize();
	}
}


