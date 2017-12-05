#pragma once

#include <SDL.h>
#include "mainScean.h"

class Game {
	MainScean mainScean;

public:
	Game() = default;
	~Game() = default;

	bool initialize();
	void update();
	void draw(SDL_Renderer **render);
	void finalize();
};

