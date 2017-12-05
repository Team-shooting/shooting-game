#include "image.h"

#include <iostream>
#include <cstdlib>

bool Image::imgSysInit = false;

void Image::changeImg(std::string imgPath) 
{
	imagePath = imgPath;

	//色の指定　仮措置
	if (!surface) {
		SDL_FreeSurface(surface);
		surface = nullptr;
	}

	surface = IMG_Load(imagePath.c_str());

	if (!surface) {
		std::cerr << "Error in Image::changeImg: " << IMG_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}
	
	imgInit = false;
}

void Image::setPos(int x, int y)
{
	pasteRect.x = x;
	pasteRect.y = y;
}

void Image::movePos(int diffX, int diffY)
{
	pasteRect.x += diffX;
	pasteRect.y += diffY;
}

SDL_Rect *Image::getRect()
{
	return &pasteRect;
}

bool Image::initialize()
{
	return true;
}

bool Image::initialize(int x, int y, std::string imgPath)
{
	bool flag = true;

	imagePath = imgPath;

	texRect.x = texRect.y = 0;
	pasteRect.x = x;
	pasteRect.y = y;

	if (!imgInit) {
		if (!imgSysInit) {
			//check
			int flags = IMG_INIT_JPG | IMG_INIT_PNG;
			if (IMG_Init(flags) != flags) {
				flag = false;
				std::cerr << "Error in Image::initialize-IMG_Init: " << IMG_GetError() << std::endl;
				SDL_Quit();
				exit(1);
			}

			imgSysInit = true;
		}

		surface = IMG_Load(imagePath.c_str());

		if (!surface) {
			std::cerr << "Error in Image::initialize-surface: " << IMG_GetError() << std::endl;
			SDL_Quit();
			exit(1);
		}
	}

	return flag; 
}

void Image::draw()
{
}

void Image::draw(SDL_Renderer **renderer)
{
	if (!imgInit) {
		int w, h;

		render = *renderer;

		if (!texture) {
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}

		texture = SDL_CreateTextureFromSurface(render, surface);

		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		pasteRect.w = texRect.w = w;
		pasteRect.h = texRect.h = h;

		if (!texture) {
			std::cerr << "Error in Image::drwa-texture: " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(1);
		}

		imgInit = true;
	}

	SDL_RenderCopy(render, texture, &texRect, &pasteRect);
}

void Image::finalize()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}


