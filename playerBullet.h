#pragma once

#include <string>

#include <SDL.h>

#include "bullet.h"

class PlayerBullet : public Bullet {

public:
	PlayerBullet() = default;
	~PlayerBullet() = default;

	bool initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img);

	bool initialize();

	void move();
};
