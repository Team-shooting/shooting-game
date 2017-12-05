#pragma once

#include <SDL.h>

#include <iostream>
#include <cstdlib>

class HitActor {
	static HitActor *instance;
	HitActor() = default;
	HitActor(HitActor &ob) = delete;
	~HitActor() = default;

	static void checkInstance() {
		if (!instance) {
			std::cerr << "Error: [HitActor] Not get instance" << std::endl;
			SDL_Quit();
			exit(1);
		}
	}

public:
	static HitActor *getInstance() {
		if (!instance) {
			instance = new HitActor();
		}

		return instance;
	}

	static void Destroy(){
		if (instance) {
			delete instance;
			instance = nullptr;
		}
	}

	static bool isHit(SDL_Rect *rect1, SDL_Rect *rect2) {
		checkInstance();

		if (SDL_HasIntersection(rect1, rect2)) {
			return true;
		}

		return false;
	}
};

