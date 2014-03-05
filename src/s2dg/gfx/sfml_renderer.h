#ifndef S2DG_SFML_RENDERER_H
#define S2DG_SFML_RENDERER_H

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../core/engine.h"

namespace s2dg {

	class SfmlRenderer :
		public Engine {
	public:
		SfmlRenderer();
		virtual ~SfmlRenderer();

		std::shared_ptr<sf::Window> window() { return _window; };

		virtual void process();

	private:
		std::shared_ptr<sf::RenderWindow> _window;
	};

}

#endif
