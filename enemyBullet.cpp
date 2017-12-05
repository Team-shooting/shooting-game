#include "enemyBullet.h"

#include "commonData.h"

bool EnemyBullet::initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img)
{
	int flag = true;

	flag *= Bullet::initialize(x, y, width_, height_, life_, ap, v, img);
	type = ENEMY_BULLET;

	return flag;
}

bool EnemyBullet::initialize()
{
	int flag = true;

	flag *= Bullet::initialize();
	type = ENEMY_BULLET;
	
	return flag;
}

void EnemyBullet::move() {
	int mainSceanHeight = CommonData::getMainSceanHeight();

	if (posY > mainSceanHeight){
		posY += velocity;
		image.getRect()->y = posY;
	} else {
		posY = 0;

		//画面から消去
		life = 0;
	}

	image.setPos(posX, posY);
}

