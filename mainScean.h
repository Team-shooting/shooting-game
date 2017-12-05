#pragma once

#include "board.h"
#include "actorMgr.h"
#include "image.h"

#include <queue>

class MainScean {
	Board board;
	ActorMgr actorMgr;

	//std::queue<SDL_Event> event_que;
	SDL_Event event;

	bool playerAttackFlg = false;
	unsigned int playerAttackAdjust = 0;

	bool upFlg = false, downFlg = false, rightFlg = false, leftFlg = false;

	Image background1, background2;
	int scrollspeed;
	int totalMove = 0;

	//Tools
	void scrollStart(int speed);
	void scrollStop();
	void keyEvent();
	void playerMoveCtrl();
	void playerAttackCtrl();
	void scrollBackground();

public:
	MainScean() = default;
	~MainScean() = default;

	bool initialize();
	void update();
	void draw(SDL_Renderer **render);
	void finalize();
};
