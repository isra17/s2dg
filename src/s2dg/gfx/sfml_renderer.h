#ifndef S2DG_SFML_RENDERER_H
#define S2DG_SFML_RENDERER_H

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../core/engine.h"

namespace s2dg {

	class EntityManager;

	class SfmlRenderer :
		public Engine {
	public:
		static const int CID = 0xA49A11E3;

		SfmlRenderer();
		virtual ~SfmlRenderer();

		std::shared_ptr<sf::Window> window() { return _window; };

		void on_start() override;
		void process() override;

	private:
		std::shared_ptr<sf::RenderWindow> _window;

		EntityManager* _entity_manager;
	};

}

#endif
