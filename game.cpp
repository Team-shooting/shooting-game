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
	board.draw(render);
}

void Game::finalize()
{
}

