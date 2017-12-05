#include"mainScean.h"

#include "commonData.h"

bool MainScean::initialize()
{
	bool flag = true;

	scrollspeed = 2;
	//scrollspeed = 2;

	flag *= board.initialize();

	flag *= actorMgr.initialize();

	int h = CommonData::getMainSceanHeight();
	flag *= background1.initialize(0, 0, "./resources/background_test.png");
	flag *= background2.initialize(0, h * -1, "./resources/background_test.png");

	return flag;
}

void MainScean::update()
{
	keyEvent();

	playerAttackCtrl();

	playerMoveCtrl();

	actorMgr.update();

	scrollBackground();
}


void MainScean::draw(SDL_Renderer **render)
{
	board.draw(render);

	background1.draw(render);
	background2.draw(render);

	actorMgr.draw(render);
}

void MainScean::finalize()
{
	board.finalize();

	background1.finalize();
	background2.finalize();

	actorMgr.finalize();
}

/*---------------------------------------------------------*/
//Tools

void MainScean::playerMoveCtrl()
{
	if (upFlg) actorMgr.movePlayer(UP);
	if (downFlg) actorMgr.movePlayer(DOWN);
	if (rightFlg) actorMgr.movePlayer(RIGHT);
	if (leftFlg) actorMgr.movePlayer(LEFT);
}

void MainScean::playerAttackCtrl()
{
	if (playerAttackFlg) {
		if (playerAttackAdjust % 4 == 0) {
			actorMgr.attackPlayer();
		}
		playerAttackAdjust++;
	} else {
		playerAttackAdjust = 0;
	}
}

void MainScean::scrollBackground()
{
	if (scrollspeed == 0) {
		return;
	}

	int h = CommonData::getMainSceanHeight();
	if (totalMove + scrollspeed < h) {
		background1.movePos(0, scrollspeed);
		background2.movePos(0, scrollspeed);
		totalMove += scrollspeed;
	} else {
		background1.setPos(0, 0);
		background2.setPos(0, h * -1);
		totalMove = 0;
	}
}

/*---------------------------------------------------------*/


void MainScean::keyEvent()
{
	while (SDL_PollEvent(&event)) {
		switch (event.key.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_d:
				actorMgr.deletePlayer_debug();
				break;
			case SDLK_e:
				actorMgr.addEnemy();
				break;
			case SDLK_c:
				actorMgr.deleteEnemy_debug();
				break;
			case SDLK_a:
				actorMgr.addPlayer_debug();
				break;
			case SDLK_UP:
				upFlg = true;
				break;
			case SDLK_DOWN:
				downFlg = true;
				break;
			case SDLK_RIGHT:
				rightFlg = true;
				break;
			case SDLK_LEFT:
				leftFlg = true;
				break;
			case SDLK_t:
				playerAttackFlg = true;
				break;
			case SDLK_s:
				scrollStart(2);
				break;
			case SDLK_z:
				scrollStop();
				break;
			
			//default:
				//event_que.push(event);
			}

			break;
		
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				upFlg = false;
				break;
			case SDLK_DOWN:
				downFlg = false;
				break;
			case SDLK_RIGHT:
				rightFlg = false;
				break;
			case SDLK_LEFT:
				leftFlg = false;
				break;
			case SDLK_t:
				playerAttackFlg = false;
				break;

			//default:
				//event_que.push(event);		
			}

			break;

		//default:
			//event_que.push(event);	
		}

	}

/*
	while (!event_que.empty()) {
		event = event_que.front();
		SDL_PushEvent(&event);
		event_que.pop();
	}
*/
}

/*---------------------------------------------------------*/
//For Debug

void MainScean::scrollStart(int speed)
{
	scrollspeed = speed;
}

void MainScean::scrollStop()
{
	scrollspeed = 0;
}

