#ifndef S2DG_MATH_H
#define S2DG_MATH_H

#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace s2dg {
	namespace vector {

		template<typename T>
		double norm(const sf::Vector2<T>& v) {
			return std::sqrt(v.x * v.x + v.y * v.y);
		}

		template<typename T>
		sf::Vector2<T> unit(const sf::Vector2<T>& v) {
			float n = static_cast<float>(norm(v));
			return sf::Vector2<T>(v.x / n, v.y / n);
		}

		template<typename T>
		bool is_zero(const sf::Vector2<T>& v) {
			return v.x == 0 && v.y == 0;
		}
	}
}

#endif
