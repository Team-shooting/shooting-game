#include "player.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <string>
#include <queue>


bool Player::initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img) {
	bool flag = true;

	setPos(x, y);
	setSize(width_, height_);
	setLife(life_);
	setPower(ap);
	setVelocity(v);
	setImg(img);

	type = PLAYER;


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

	surf = IMG_Load(imagepath.c_str());

	if (surf == nullptr) {
		std::cout << "Error : IMG_Load -- " << SDL_GetError() << std::endl;
		exit(1);
		//return false;
	}
---*/

	flag *= image.initialize(posX, posY, imagepath);

	return flag;
}

bool Player::initialize() {
	bool flag = true;

	setPos(300, 300);
	setSize(60, 60);
	setLife(10);
	setPower(10);
	setVelocity(5);
	setImg("./resources/rize.png");

	type = PLAYER;

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

	surf = IMG_Load(imagepath.c_str());

	if (surf == nullptr) {
		std::cout << "Error : IMG_Load -- " << SDL_GetError() << std::endl;
		exit(1);
		//return false;
	}
---*/

	image.initialize(posX, posY, imagepath);

	return flag;
}

void Player::update() {
	//this->move();
}

void Player::draw(SDL_Renderer **render) {

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

void Player::finalize() {
	//tex, surfの解放
/*---
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
---*/
	
	image.finalize();
}

//Player固有のメソッド?

int Player::attack() {
	return power;
}

void Player::move(VEC vec)
{
	switch (vec) {
	case UP:
		posY -= velocity;
		//std::cout << "UP" << std::endl;
		break;
	case DOWN:
		posY += velocity;
		//std::cout << "DOWN" << std::endl;
		break;
	case RIGHT:
		posX += velocity;
		//std::cout << "RIGHT" << std::endl;
		break;
	case LEFT:
		posX -= velocity;
		//std::cout << "LEFT" << std::endl;
		break;
	default:
		break;
	}

	//pasteRect.x = posX;
	//pasteRect.y = posY;
	image.setPos(posX, posY);
}

void Player::move() {
	static std::queue<SDL_Event> event_que;
	static bool upFlg = false, downFlg = false, leftFlg = false, rightFlg = false;

	//For SDL
	static SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				upFlg = true;
				//std::cout << "Press Up key" << std::endl;
				break;
			case SDLK_DOWN:
				downFlg = true;
				//std::cout << "Press Down key" << std::endl;
				break;
			case SDLK_LEFT:
				leftFlg = true;
		 		//std::cout << "Press Left key" << std::endl;
				break;
			case SDLK_RIGHT:
				rightFlg = true;
				//std::cout << "Press Right key" << std::endl;
				break;
			default:
				event_que.push(event);
			}	

			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				upFlg = false; 
				//std::cout << "Release Up key" << std::endl;
				break;
			case SDLK_DOWN:
				downFlg = false;
				//std::cout << "Release Down key" << std::endl;
				break;
			case SDLK_LEFT:
				leftFlg = false;
				//std::cout << "Release Left key" << std::endl;
				break;
			case SDLK_RIGHT:
				rightFlg = false;
				//std::cout << "Release Right key" << std::endl;
				break;
			default:
				event_que.push(event);
			
			}

			break;

		default:
			event_que.push(event);

		}
	}    

	while (!event_que.empty()) {
		event = event_que.front();
		SDL_PushEvent(&event);
		event_que.pop();
	}

	int pasteWidth, pasteHeight;
	pasteWidth = image.getRect()->w;
	pasteHeight = image.getRect()->h;

	if (posX < velocity) {
		if (rightFlg) posX += velocity;
	} else if (posX + velocity > 600 - pasteWidth) {
		if (leftFlg) posX -= velocity;
	} else {
		if (leftFlg) posX -= velocity;
		if (rightFlg) posX += velocity;
	}

	if (posY < velocity) {
		if (downFlg) posY += velocity;
	} else if (posY + velocity > 600 - pasteHeight) {
		if (upFlg) posY -= velocity;
	} else {
		if (upFlg) posY -= velocity;
		if (downFlg) posY += velocity;
	}

	//pasteRect.x = posX;
	//pasteRect.y = posY;
	image.setPos(posX, posY);

}
