#pragma once

#include <string>

#include <SDL.h>

#include "bullet.h"

class EnemyBullet : public Bullet {

public:
	EnemyBullet() = default;
	~EnemyBullet() = default;

	bool initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img);
	bool initialize();

	void move();
};
