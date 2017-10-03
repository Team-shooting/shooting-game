#include "board.h"

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool Board::initialize()
{
	//ハイスコアの取得
	//残機・攻撃力の初期値を設定

	//IMG_Init
	int flags = IMG_INIT_JPG;
	if (IMG_Init(flags) != flags) {
		cout << "Error : IMG_Init -- " << IMG_GetError() << endl;
		exit(1);
	}

	surf = IMG_Load("/home/hoge/shooting-game/shooting-game/resources/sake.jpg");
	if (surf == nullptr) {
		cout << "Error : IMG_Load -- " << IMG_GetError() << endl;
		exit(1);
	}

	return true;
}

void Board::update()
{
	//残機の更新
	//攻撃力の更新
}

void Board::draw(SDL_Renderer **render)
{
	//IMG
	static int tex_init = 0;

	if (tex_init == 0) {
		tex = SDL_CreateTextureFromSurface(*render, surf);
		if (tex == nullptr) {
			cerr << "Error : " << SDL_GetError() << endl;
			exit(1); 
		}

		int w, h;
		SDL_QueryTexture(tex, NULL, NULL, &w, &h);

		texRect = (SDL_Rect){0, 0, w, h};
		pasteRect = (SDL_Rect){0, 0, w, h};

		tex_init = 1;
	}

	SDL_RenderCopy(*render, tex, &texRect, &pasteRect);

}

void Board::finalize()
{
	//ハイスコアの処理

	SDL_FreeSurface(surf);
}
