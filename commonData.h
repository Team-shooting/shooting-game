#pragma once

#include <SDL.h>

#include <iostream>
#include <cstdlib>

class CommonData {
	static CommonData *instance;
	CommonData() = default;

	static int windowWidth;
	static int windowHeight;

	static int mainSceanPosX;
	static int mainSceanPosY;
	static int mainSceanWidth;
	static int mainSceanHeight;

	static int boardSceanPosX;
	static int boardSceanPosY;
	static int boardSceanWidth;
	static int boardSceanHeight;

	static int score;

	static void checkInstance() {
		if (!instance) {
			std::cerr << "Error: [CommonData] Not get instance" << std::endl;
			SDL_Quit();
			exit(1);
		}
	}

public:
	static CommonData *getInstance() {
		if (!instance) {
			instance = new CommonData();
		}

		return instance;
	}

	static void Destroy() {
		if (instance) {
			delete instance;
			instance = nullptr;
		}
	}

	static int getScore() {
		checkInstance();

		return score;
	}

	static void changeScore(int up) {
		checkInstance();

		if (up > 0) {
			score += up;
		}
	}

	static int getWindowWidth() {
		checkInstance();

		return windowWidth;
	}

	static int getWindowHeight() {
		checkInstance();

		return windowHeight;
	}

	static int getMainSceanWidth() {
		checkInstance();

		return mainSceanWidth;
	}

	static int getMainSceanHeight() {
		checkInstance();

		return mainSceanHeight;
	}
};

