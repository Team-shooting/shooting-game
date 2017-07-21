#pragma once

class Game {
	private:

	public:
		Game() = default;
		~Game() = default;

		bool initialize();
		void update();
		void draw();
		void finalize();
};

