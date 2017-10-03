#include "game.h"

bool Game::initialize()
{
	board.initialize();

	return true;
}

void Game::update()
{
}

void Game::draw(SDL_Renderer **render)
{
	SDL_SetRenderDrawColor(*render, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(*render, 10, 10, 100, 100);
	
	board.draw(render);
}

void Game::finalize()
{
	board.finalize();
}

