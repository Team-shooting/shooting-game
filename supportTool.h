#pragma once

#include <SDL.h>

#include <iostream>
#include <cstdlib>

#include "commonData.h"
#include "hitActor.h"

class SupportTool {
	static SupportTool *instance;
	SupportTool() = default;
	SupportTool(SupportTool &ob) = default;
	~SupportTool() = default;

	static void checkInstance() {
		if (!instance) {
			std::cerr << "Error: [SupportTool] Not get instance" << std::endl;
			SDL_Quit();
			exit(1);
		}
	}

public:
	static SupportTool *getInstance() {
		if (!instance) {
			instance = new SupportTool();
		}

		return instance;
	}

	static void Destroy() {
		if (instance) {
			delete instance;
			instance = nullptr;
		}
	}

	static void SupportToolInit() {
		if (instance) {
			HitActor::getInstance();
			CommonData::getInstance();
		}
	}
};
