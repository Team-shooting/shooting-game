#pragma once

#include <SDL.h>

#include "actor.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "playerBullet.h"
#include "enemyBullet.h"

#include <list>
#include <memory>


class ActorMgr {
	std::list<std::shared_ptr<Actor>> ActorList;
	std::shared_ptr<Player> player;

	/*----------------------------------------------------------*/

	void erasePlayer();

	void addList(std::shared_ptr<Actor>& chara);


	/*----------------------------------------------------------*/


public:
	ActorMgr() = default;
	~ActorMgr() = default;

	void addEnemy();

	void addBullet(ACTORTYPE type);

	void attackEnemy();

	/*----------------------------------------------------------*/
	//FOR PLAYER

	void movePlayer(VEC vec);

	void attackPlayer();


	/*---------------------------------------------------------*/
	//General


	bool initialize();

	void update();

	void draw(SDL_Renderer **render);

	void finalize();


	/*----------------------------------------------------------*/
	//FOR DEBUG
	void deletePlayer_debug();

	void addPlayer_debug();

	void deleteEnemy_debug();
};

