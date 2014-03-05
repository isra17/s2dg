#ifndef S2DG_SFML_INPUT_H
#define S2DG_SFML_INPUT_H

#include <memory>
#include <SFML/Window.hpp>

#include "../core/engine.h"

namespace s2dg {

	class SfmlInput :
		public Engine {
	public:
		SfmlInput(std::shared_ptr<sf::Window> window);
		virtual ~SfmlInput();

		void process();

		void on_stop();
	private:
		std::shared_ptr<sf::Window> _window;
	};

}

#endif