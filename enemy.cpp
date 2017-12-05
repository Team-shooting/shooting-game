#include "enemy.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>


bool Enemy::initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img) {
	bool flag = true;

	setPos(x, y);
	setSize(width_, height_);
	setLife(life_);
	setPower(ap);
	setVelocity(v);
	setImg(img); 

	type = ENEMY;

	//SDL
	//texRect = (SDL_Rect){0, 0, width, height};
	//pasteRect = (SDL_Rect){posX, posY, width, height};

/*---
	texRect.x = texRect.y = 0;
	texRect.w = width;
	texRect.h = height;

	pasteRect.x = posX;
	pasteRect.y = posY;
	pasteRect.w = width;
	pasteRect.h = height;
	
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (IMG_Init(flags) != flags) {
		std::cout << "Error : IMG_Init -- " << IMG_GetError() << std::endl;
		exit(1);
		//return false;
	}

	surf = IMG_Load(image.c_str());

	if (surf == nullptr) {
		std::cout << "Error : IMG_Load -- " << SDL_GetError() << std::endl;
		exit(1);
		//return false;
	}
---*/

	image.initialize(posX, posY, imagepath);

	return flag;
}

bool Enemy::initialize() {
	bool flag = true;

	setPos(100, 100);
	setSize(100, 100);
	setLife(3);
	setPower(5);
	setVelocity(0);
	setImg("./resources/test_player.jpg"); 

	type = ENEMY;

	//SDL
	//texRect = (SDL_Rect){0, 0, width, height};
	//pasteRect = (SDL_Rect){posX, posY, width, height};

/*---
	texRect.x = texRect.y = 0;
	texRect.w = width;
	texRect.h = height;

	pasteRect.x = posX;
	pasteRect.y = posY;
	pasteRect.w = width;
	pasteRect.h = height;
	
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (IMG_Init(flags) != flags) {
		std::cout << "Error : IMG_Init -- " << IMG_GetError() << std::endl;
		exit(1);
		//return false;
	}

	surf = IMG_Load(image.c_str());

	if (surf == nullptr) {
		std::cout << "Error : IMG_Load -- " << SDL_GetError() << std::endl;
		exit(1);
		//return false;
	}
---*/

	image.initialize(posX, posY, imagepath);

	return true;
}

void Enemy::update() {
	move();
}

void Enemy::draw(SDL_Renderer **render) {
	//SDL
/*---
	if (!tex_init) {
		tex = SDL_CreateTextureFromSurface(*render, surf);
		if (tex == nullptr) {
			std::cerr << "Error : " << SDL_GetError() << std::endl;
			exit(1);
		}

		tex_init = true;
	}

	SDL_RenderCopy(*render, tex, &texRect, &pasteRect);
---*/
	
	image.draw(render);
}

void Enemy::finalize() {
	//tex, surfの解放
/*---
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
---*/
	
	image.finalize();
}

void Enemy::move()
{
	switch (random() % 8) {
	case 0:
		posY -= velocity;
		break;
	case 1:
		posY += velocity;
		break;
	case 2:
		posX += velocity;
		break;
	case 3:
		posX -= velocity;
		break;
	case 4:
		posY -= velocity;
		posX += velocity;
		break;
	case 5:
		posY -= velocity;
		posX -= velocity;
		break;
	case 6:
		posY += velocity;
		posX += velocity;
		break;
	case 7:
		posY += velocity;
		posX -= velocity;
		break;
	}

	image.setPos(posX, posY);
}

int Enemy::attack()
{
	return power;
}

