#include "board.h"

#include <iostream>
using namespace std;

bool Board::initialize()
{
	//ハイスコアの取得
	//残機・攻撃力の初期値を設定

	//Init SDL_ttf
	if (TTF_Init() < 0) cout << "Error : TTF_Init" << endl;
	else cout << "Done... TTF_Init" << endl;

	TTF_OpenFont("TakaoGothic.ttf", 16);
	if (font == nullptr) cout << "Error : TTF_OpenFont -- " << TTF_GetError() << endl;
	else cout << "Done... TTF_OpenFont" << endl;

	return true;
}

void Board::update()
{
	//残機の更新
	//攻撃力の更新
}

void Board::draw(SDL_Renderer **render)
{
	//SDL_SetRenderDrawColor(*render, 255, 165, 0, 255);
	//SDL_RenderDrawRect(*render, &board);

	cout << "Start TTF_RenderUTF8_Solid" << endl;
	surf = TTF_RenderUTF8_Solid(font, "Hello World",(SDL_Color){0, 0, 0, 255});
	if (surf == nullptr) cout << "Error : " << SDL_GetError() << endl;
	else cout << "Done... TTF_RenderUTF8_Solid" << endl;


	tex = SDL_CreateTextureFromSurface(*render, surf);
	if (tex == nullptr) cout << "Error : " << SDL_GetError() << endl;
	else cout << "Done... SDL_CreateTextureFormSurface" << endl;

	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	cout << "Done... SDL_QueryTexture" << endl;

	texRect = (SDL_Rect){0, 0, w, h};
	pasteRect = (SDL_Rect){100, 100, w, h};

	SDL_RenderCopy(*render, tex, &texRect, &pasteRect);
	cout << "Done... SDL_RenderCopy" << endl;
}

void Board::finalize()
{
	//ハイスコアの処理
	

	SDL_FreeSurface(surf);
}
