#include "board.h"

#include "commonData.h"

#include <iostream>
#include <cstdlib>
#include <string>

bool Board::initialize()
{
	bool flag = true;

	//ハイスコアの取得
	//残機・攻撃力の初期値を設定

	background.x = 600;
	background.y = 0;
	background.w = 200;
	background.h = 600;

	scoreStr = "SCORE: " + std::to_string(CommonData::getScore());

	scoreFont.initialize(605, 10, scoreStr.c_str(), "./resources/font/ipagp-mona.ttf", 30);

	return flag;
}

void Board::update()
{
	//残機の更新
	//攻撃力の更新
}

void Board::draw(SDL_Renderer **render)
{
	SDL_SetRenderDrawColor(*render, 0, 255, 65, 255);
	SDL_RenderFillRect(*render, &background);


	if (!(counter % 8)) { 
		scoreStr = "SCORE: " + std::to_string(CommonData::getScore());
		scoreFont.changeStr(scoreStr.c_str());
	}
	counter++;
	scoreFont.draw(render);
}

void Board::finalize()
{
	//ハイスコアの処理

	scoreFont.finalize();

}
