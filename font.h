#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <memory>

typedef enum fontcolor{
	BLACK,
	RED,
} FontColor;


class Font {
	SDL_Renderer *render;

	SDL_Surface *surface = nullptr;
	SDL_Texture *texture = nullptr;
	SDL_Rect texRect, pasteRect;

	TTF_Font *font;
	int fontsize;
	std::string str;
	//std::string fontname;

	bool ttfInit = false;
	static bool ttfSysInit;

public:
	Font() = default;
	~Font() = default;

	void changeStr(std::string str);
	//void changeFont(std::string font);

	bool initialize();
	bool initialize(int x, int y, std::string str_, std::string fontname, int fontsize_);
	void draw();
	void draw(SDL_Renderer **renderer);   //SDL系のクラス作成前の仮措置
	void finalize();
};

