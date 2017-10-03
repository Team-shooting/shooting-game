#pragma once

#include <SDL.h>
#include <board.h>

class Game {
	Board board;

public:
	Game() = default;
	~Game() = default;

	bool initialize();
	void update();
	void draw(SDL_Renderer **render);
	void finalize();
};

