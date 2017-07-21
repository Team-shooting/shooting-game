#pragma once

#include <SDL.h>

class Board {
	private:
		int hiscore;
		int nowscore = 0;
		int life;
		int power;

		const int width = 200;
		const int height = 600;
		const int xPos = 600;
		const int yPow = 0;
		SDL_Rect board = {600, 0, 200, 600};
	public:
		Board() = default;
		~Board() = default;
		bool initialize();
		void update();
		void draw();
		void finalize();
}
