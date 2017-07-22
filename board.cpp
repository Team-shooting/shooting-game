#include "board.h"

bool Board::initialize()
{
	//ハイスコアの取得
	//残機・攻撃力の初期値を設定

	return true;
}

void Board::update()
{
	//残機の更新
	//攻撃力の更新
}

void Board::draw(SDL_Renderer **render)
{
	SDL_SetRenderDrawColor(*render, 255, 165, 0, 255);
	SDL_RenderFillRect(*render, &board);
}

void Board::finalize()
{
	//ハイスコアの処理
}
