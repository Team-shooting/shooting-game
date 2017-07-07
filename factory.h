#pragma once

#include <memory>

template<typename T>
class Factory {
	public:
		Factory() = default;
		~Factory() = default;

		Factory(const Factory& other) = delete;
		Factory& operator=(const Factory& other) = delete;

		std::unique_ptr<T> create(int type) {
			return create_product(type);
		}

	protected:
		virtual std::unique_ptr<T> create_product(int type) = 0;
};
