#include "playerBullet.h"

bool PlayerBullet::initialize(int x, int y, int width_, int height_, int life_, int ap, int v, std::string img)
{
	int flag = true;

	flag *= Bullet::initialize(x, y, width_, height_, life_, ap, v, img);
	type = PLAYER_BULLET;

	return flag;
}

bool PlayerBullet::initialize()
{
	int flag = true;

	flag *= Bullet::initialize();
	type = PLAYER_BULLET;
	
	return flag;
}

void PlayerBullet::move() {
	if (posY + height > velocity) {
		posY -= velocity;
		image.getRect()->y = posY;
	} else {
		posY = 0;

		//画面から消去
		life = 0;
	}

	image.setPos(posX, posY);
}

