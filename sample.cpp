#include <SDL.h>

int main(int argc, char *argv[])
{
	constexpr int window_width = 640;
	constexpr int window_height = 480;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Hello!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, 0);
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

	SDL_Event ev;
	bool flag = true;
	while (flag) {
		SDL_SetRenderDrawColor(render, 0, 0, 0, 0xff);
		SDL_RenderClear(render);
		
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) {
				flag = false;
			}
		}

		SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
		SDL_RenderDrawLine(render, 10, 10, 400, 400);
		SDL_RenderPresent(render);
	}

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
