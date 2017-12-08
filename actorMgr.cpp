#include "actorMgr.h"

#include <SDL.h>

#include "actor.h"
#include "hitActor.h"
#include "commonData.h"

#include <iostream>
#include <list>
#include <memory>
#include <cstdlib>



void ActorMgr::erasePlayer()
{
	player->finalize();

	ActorList.pop_front();

	player.reset();
}


void ActorMgr::addList(std::shared_ptr<Actor> &chara)
{
	ActorList.push_back(chara);
}


void ActorMgr::addEnemy()
{
	std::shared_ptr<Actor> p = std::make_shared<Enemy>();
	p->initialize(random() % 500, random() % 300, 69, 79, 1, 5, 3,
	              "./resources/rabit.png");
	addList(p);
}


void ActorMgr::addBullet(std::shared_ptr<Actor> chara, ACTORTYPE type)
{
	std::shared_ptr<Actor> p;

	switch (type) {
	case PLAYER_BULLET:
		p = std::make_shared<PlayerBullet>();

		break;
	
	case ENEMY_BULLET:
		p = std::make_shared<EnemyBullet>();

		break;
	default:
		std::cerr << "Error in Actor::addBullet : Undefined actor type" << std::endl;
		return;
	}
		
	p->initialize(chara->getPosX() + chara->getWidth() / 2 - 20, 
	              chara->getPosY() - 40, 40, 34, 1, chara->attack(),
		      	  10, "./resources/bullet.png");
	addList(p);
}

void ActorMgr::attackEnemy(std::shared_ptr<Actor> chara)
{
	addBullet(chara, ENEMY_BULLET);
}

/*----------------------------------------------------------*/
//FOR PLAYER

void ActorMgr::movePlayer(VEC vec) {
	if (player && player->areaCheck(vec)) {
		player->move(vec);
	}
}


void ActorMgr::attackPlayer() {

	if (player) {
		addBullet(player, PLAYER_BULLET);
	} 
}


/*---------------------------------------------------------*/
//General


bool ActorMgr::initialize() {
	bool flag = true;

	player = std::make_shared<Player>();
	ActorList.push_front(player);

	flag *= player->initialize();

	return flag;
}

void ActorMgr::update() {
	auto chara = ActorList.begin();
	auto actor = ActorList.begin();

	if (player) {
		actor = ActorList.begin();
		actor++;

		while(actor != ActorList.end()) {
			if (HitActor::isHit((*chara)->getRect(), (*actor)->getRect()) && 
				((*actor)->getType() == ENEMY_BULLET || (*actor)->getType() == ENEMY) ) {

				player->downLife((*actor)->attack());
				(*actor)->downLife(player->attack());
			}
			
			if ((*actor)->isDead()) {
				(*actor)->finalize();
				actor = ActorList.erase(actor);

				continue;
			}
			

			actor++;
		}


		if (player->isDead()) {
			erasePlayer();

			chara = ActorList.begin();
		} else {
			chara++;
		}

	}

	while (chara != ActorList.end()) {
		
		actor = chara;
		actor++;

		while(actor != ActorList.end()) {

			if ( ((*chara)->getType() == ENEMY && (*actor)->getType() == PLAYER_BULLET) ||
				 ((*chara)->getType() == PLAYER_BULLET && (*actor)->getType() == ENEMY) ) {

				if ( HitActor::isHit((*chara)->getRect(), (*actor)->getRect()) ) {

					(*chara)->downLife((*chara)->attack());
					(*actor)->downLife((*actor)->attack());
				}
			}

			if ((*actor)->isDead()) {
				(*actor)->finalize();
				actor = ActorList.erase(actor);
				continue;
			}

			actor++;
		}

		if ((*chara)->isDead()) {
			(*chara)->finalize();
			chara = ActorList.erase(chara);

			CommonData::changeScore(1);

			continue;
		}

		chara++;
	}

	//update
	chara = ActorList.begin();
	while (chara != ActorList.end()) {

		(*chara)->update();
		chara++;
	}

/*
	if (player) {
		player->update();
	}
*/

/*
	while (chara != ActorList.end()) {
		if (player && SDL_HasIntersection((*chara)->getRect(), player->getRect())) {
			(*chara)->downLife(1);
			player->downLife(1);
		}

		actor = ActorList.begin();

		while (actor != ActorList.end()) {
			if ((*chara)->getType() == PLAYER_BULLET) {
				break;
			}

			if (actor == chara) {
				actor++;
				continue;
			}

			if (SDL_HasIntersection((*chara)->getRect(), (*actor)->getRect())) {
				if ((*actor)->getType() == PLAYER_BULLET) {
					(*chara)->downLife((*actor)->getPower());
					(*actor)->downLife(1);
					CommonData::changeScore(1);
				}
			}

			actor++;
		}

		chara++;
	}

	chara = ActorList.begin();
	while (chara != ActorList.end()) {
		if ((*chara)->isDead()) {
			(*chara)->finalize();
			chara = ActorList.erase(chara);
			continue;
		}

		(*chara)->update();

		chara++;
	}


	if (player) {
		if (player->isDead()) {
			erasePlayer();
		} else {
			player->update();
		}
	}
*/

}

void ActorMgr::draw(SDL_Renderer **render) {
	auto chara = ActorList.begin();

	while (chara != ActorList.end()) {
		if (!((*chara)->isDead())) {
			(*chara)->draw(render);
		}

		chara++;
	}
}

void ActorMgr::finalize() {
	if (player) {
		player->finalize();
		ActorList.pop_front();
		player.reset();
	}

	auto chara = ActorList.begin();
	chara++;
	while (chara != ActorList.end()) {
		(*chara)->finalize();
		chara = ActorList.erase(chara);

		chara++;
	}
}

/*----------------------------------------------------------*/



/*----------------------------------------------------------*/
//FOR DEBUG
void ActorMgr::deletePlayer_debug() {
	if (player) {
		erasePlayer();

		//std::cout << "Player is deleted" << endl;
	}
}

void ActorMgr::addPlayer_debug() {
	if (!player) {
		player = std::make_shared<Player>();
		player->initialize();

		ActorList.push_front(player);

		//std::cout << "Add Player" << std::endl;
	}
}

void ActorMgr::deleteEnemy_debug() {
	if (!ActorList.empty()) {
		if (player && (*(--(ActorList.end()))) == player) return;

		std::shared_ptr<Actor> p = ActorList.back();
		p->finalize();
		//p.reset();
		ActorList.pop_back();
	}
}

