#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>

#include "commonData.h"
#include "font.h"

class Board {
	int hiscore;
	int nowscore = 0;
	int life;
	int power;

	//Font
	Font scoreFont;
	std::string scoreStr;
	int counter = 0;

	//Background
	SDL_Rect background;

	bool tex_init = false;



public:
	Board() = default;
	~Board() = default;
	bool initialize();
	void update();
	void draw(SDL_Renderer **render);
	void finalize();
};
