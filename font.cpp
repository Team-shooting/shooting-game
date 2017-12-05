#include "font.h"

#include <iostream>
#include <cstdlib>

bool Font::ttfSysInit = false;

void Font::changeStr(std::string str_)
{
	str = str_;

	//色の指定　仮措置
	if (surface) {
		SDL_FreeSurface(surface);
		surface = nullptr;
	}
	
	surface = TTF_RenderUTF8_Solid(font, str.c_str(), (SDL_Color){0, 0, 0, 255});
	if (!surface) {
		std::cerr << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}
	
	ttfInit = false;
}

bool Font::initialize()
{
	return true;
}

bool Font::initialize(int x, int y, std::string str_, std::string fontname, int fontsize_)
{
	bool flag = true;

	str = str_;

	texRect.x = texRect.y = 0;	//Important!!!
	pasteRect.x = x;
	pasteRect.y = y;

	if (!ttfInit) {
		if (!ttfSysInit) {
			int flags = TTF_Init();
			if (flags == -1) {
				std::cerr << "Error: " << TTF_GetError() << std::endl;
				SDL_Quit();
				exit(1);
			}

			//std::cout << "TTF_Init" << std::endl;
		}

		fontsize = fontsize_;

		font = TTF_OpenFont(fontname.c_str(), fontsize_);
		if (!font) {
			std::cerr << "Can't open font" << std::endl;
			SDL_Quit();
			exit(1);
		}
		//std::cout << "Open Font  " + fontname << std::endl;;

		//色の指定　仮措置
		surface = TTF_RenderUTF8_Solid(font, str.c_str(), (SDL_Color){0, 0, 0, 255});

		if (!surface) {
			std::cerr << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			exit(1);
		}
		//std::cout << "Create font surface" << std::endl;
	}

	return true; 
}

void Font::draw()
{
}

void Font::draw(SDL_Renderer **renderer)
{
	if (!ttfInit) {
		int w, h;

		render = *renderer;

		if (texture) {
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}

		texture = SDL_CreateTextureFromSurface(render, surface);
		if (!texture) {
			std::cerr << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			exit(1);
		}

		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		pasteRect.w = texRect.w = w;
		pasteRect.h = texRect.h = h;
	}


	SDL_RenderCopy(render, texture, &texRect, &pasteRect);
}

void Font::finalize()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}


