#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>

#include "image.h"

typedef enum actortype { PLAYER, ENEMY, BULLET, PLAYER_BULLET, ENEMY_BULLET } ACTORTYPE;
typedef enum vec { UP, DOWN, RIGHT, LEFT } VEC;


class Actor {
protected:
	int posX, posY;
	int width, height;
	int life;
	int power;
	int velocity;
	std::string imagepath;

	ACTORTYPE type;

	//For SDL
	//SDL_Surface *surf;
	//SDL_Texture *tex;
	//SDL_Rect texRect, pasteRect;

	Image image;

	Actor() = default;

	~Actor() = default;

public:

	/*************************
	 *Set parameter          *
	 *************************/

	void setPos(int x, int y) {
		this->posX = x;
		this->posY = y;
	}

	void setSize(int x, int y) {
		this->width = x;
		this->height = y;
	}

	void setLife(int life_) {
		this->life = life_;
	}

	void setPower(int ap) {
		this->power = ap;
	}

	void setVelocity(int v) {
		this->velocity = v;
	}

	void setImg(std::string img) {
		this->imagepath = img;
	}

	/*************************
	 *Get parameter          *
	 *************************/

	int getPosX() {
		return this->posX;
	}

	int getPosY() {
		return this->posY;
	}

	int getWidth() {
		return this->width;
	}

	int getHeight() {
		return this->height;
	}

	int getVelocity() {
		return this->velocity;
	}

	int getPower() {
		return this->power;
	}

	ACTORTYPE getType() {
		return type;
	}

	SDL_Rect *getRect() { return (this->image.getRect()); }
	 


	/************************
	 *method                *
	 ***********************/

	virtual bool initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img_) =  0;

	virtual bool initialize() { return true; }

	virtual void update() = 0;

	virtual void draw(SDL_Renderer **) = 0;

	virtual void finalize() = 0;

	virtual int attack() {
		return power;
	}

	bool isDead() {
		return life > 0 ? false : true;
	}

	void downLife(int down) {
		if (this->life > 0) {
			this->life -= down;
		}
	}

	bool areaCheck(VEC vec) {
		bool flag = false;

		switch (vec) {
		case UP:
			if (posY >= velocity) flag = true; 
			break;
		case DOWN:
			if (posY + velocity <= 600 - image.getRect()->h) flag = true;
			break;
		case RIGHT:
			if (posX + velocity <= 600 - image.getRect()->w) flag = true;
			break;
		case LEFT:
			if (posX >= velocity) flag = true;
			break;

		default:
			break;

		}

		return flag;
	}
};


