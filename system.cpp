#include <SDL.h>
#include <iostream>
#include "system.h"


bool System::sdl_initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING  < 0)) {
		std::cerr << "Faild to initialize" << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (window == nullptr) {
		std::cerr << "Faild to create window" << std::endl;
		return false;
	}

	render = SDL_CreateRenderer(window, -1, 0);
	if (render == nullptr) {
		std::cerr << "Faild to create render" << std::endl;
		return false;
	}

	//Init game
	game.initialize();

	return true;
}

void System::sdl_finalize() {
	game.finalize();

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void System::main_loop() {
	bool flag = true;
	char valFps[10];


	while (flag) {
		//fps.Update();

		//clear
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_RenderClear(render);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				flag = false;
			}
		}
		
		/*
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255); 
		SDL_RenderDrawLine(render, 10, 10, 400, 400);
		*/

		game.draw(&render);


		//Draw
		SDL_RenderPresent(render);

		fps.delay();
		sprintf(valFps, "%f", fps.getFps());
		SDL_SetWindowTitle(window, valFps);
		
        /*
		fps.delay();
		sprintf(valFps, "%f", fps.getFps());
		SDL_SetWindowTitle(window, valFps);
		*/
	}
}

void System::run()
{
	if (sdl_initialize()) {
		main_loop();
		sdl_finalize();
	}
}


