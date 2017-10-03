#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Board {
	private:
		int hiscore;
		int nowscore = 0;
		int life;
		int power;


		//Font
		//TTF_Font *font;
		SDL_Surface *surf_score;
		SDL_Texture *tex_score;
		SDL_Rect texRect, pasteRect;


	public:
		Board() = default;
		~Board() = default;
		bool initialize();
		void update();
		void draw(SDL_Renderer **render);
		void finalize();
};
