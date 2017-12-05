#include "game.h"
#include <iostream>

bool Game::initialize()
{
	bool flag = true;

	flag *= mainScean.initialize();

	return flag;
}

void Game::update()
{
	mainScean.update();
}

void Game::draw(SDL_Renderer **render)
{
	mainScean.draw(render);
}

void Game::finalize()
{
	mainScean.finalize();
}

