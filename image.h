#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>


class Image {
	SDL_Renderer *render;

	SDL_Surface *surface = nullptr;
	SDL_Texture *texture = nullptr;
	SDL_Rect texRect, pasteRect;

	std::string imagePath;

	bool imgInit = false;
	static bool imgSysInit;

public:
	Image() = default;
	~Image() = default;

	void changeImg(std::string imgPath);
	void setPos(int x, int y);
	void movePos(int diffX, int diffY);
	SDL_Rect *getRect();

	bool initialize();
	bool initialize(int x, int y, std::string imgPath);
	void draw();
	void draw(SDL_Renderer **renderer);   //SDL系のクラス作成前の仮措置
	void finalize();
};

