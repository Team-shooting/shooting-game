#pragma once

#include "actor.h"

#include <SDL.h>


class Enemy : public Actor{
	//Textureの処理をただ一度に限定するためのフラグ
	//bool tex_init = false;

	VEC vec = RIGHT;

public:
	Enemy() = default;
	~Enemy() = default;

	bool initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img);

	bool initialize();

	void update();

	void draw(SDL_Renderer **render);

	void finalize();

	void move();

	int attack();
};
