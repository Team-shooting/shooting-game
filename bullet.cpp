#include "bullet.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <string>


bool Bullet::initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img) {
	setPos(x, y);
	setSize(width_, height_);
	setLife(life_);
	setPower(ap);
	setVelocity(v);
	setImg(img);

	type = BULLET;

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

bool Bullet::initialize() {
	setPos(400, 10);
	setSize(40, 34);
	setLife(1);
	setPower(10);
	setVelocity(4);
	setImg("./resources/bullet.jpg");

	type = BULLET;

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

void Bullet::update() {
	move();
}

void Bullet::draw(SDL_Renderer **render) {

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

void Bullet::finalize() {
	//tex, surfの解放
/*---
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
---*/

	image.finalize();
}

//Bulletの固有の関数

//Not complete
void Bullet::move() {
	if (posY + height > velocity) {
		posY -= velocity;
		//image.getRect()->y = posY;
		//image.setPos(posX, posY);
	} else {
		posY = 0;

		//画面から消去
		life = 0;
	}

	image.setPos(posX, posY);
}

int Bullet::attack()
{
	return power;
}

