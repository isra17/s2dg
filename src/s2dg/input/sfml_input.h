#ifndef S2DG_SFML_INPUT_H
#define S2DG_SFML_INPUT_H

#include <memory>
#include <SFML/Window.hpp>

#include "../core/engine.h"

namespace s2dg {

	class SfmlInput :
		public Engine {
	public:
		static const int CID = 0x84D88C2F;

		SfmlInput(std::shared_ptr<sf::Window> window);
		virtual ~SfmlInput();

		std::shared_ptr<sf::Window> window() const { return _window; };

		void process(const sf::Time& elapsed) override;
		void on_stop();
	private:
		std::shared_ptr<sf::Window> _window;
	};

}

#endif
