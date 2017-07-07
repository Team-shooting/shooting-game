#pragma once

class Camera {
public:
	Camera() = delete;
	~Camera() = delete;
	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;
	Camera(Camera&&) = delete;
	Camera& operator=(Camera&&) = delete;

	static void create() {
		if (inst == nullptr) {
			inst = new Camera;
		}
	}

	static Camera& get_instance() {
		if (inst != nullptr) {
			return *inst;
		} else {
			create();
		}
	}

	static void destroy() {
		if (inst != nullptr) {
			delete inst;
			inst = nullptr;
		}
	}

private:
	static Camera* inst = nullptr;
};
