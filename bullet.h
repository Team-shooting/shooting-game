#pragma once

#include "actor.h"

#include <SDL.h>


class Bullet : public Actor{
	//bool tex_init = false;

public:
	Bullet() = default;
	~Bullet() = default;

	virtual bool initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img);

	virtual bool initialize();

	virtual void update();

	virtual void draw(SDL_Renderer **render);

	virtual void finalize();

	//Bulletの固有の関数

	//Not complete
	virtual void move();

	int attack();
};

