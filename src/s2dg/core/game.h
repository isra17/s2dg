#ifndef S2DG_GAME_H
#define S2DG_GAME_H

#include <vector>
#include <memory>
#include <algorithm>
#include <cassert>

#include <SFML/System.hpp>

namespace s2dg {

	class Engine;

	class Game {
		// Singleton implementation
	public:
		static Game& get_instance();

	public:
		Game();
		~Game();

		void add_engine(Engine* engine);

		// Return an engine
		template<class T>
		T* get_engine() {
			auto engine = std::find_if(_engines.begin(), _engines.end(), [](Engine* e) { return e->cid() == T::CID; });
			assert(engine != _engines.end());
			T* typed_engine = dynamic_cast<T*>(*engine);
			assert(typed_engine);
			return typed_engine;
		}

		bool is_running() { return _running; };

		int run();
		void stop();
	private:
		std::vector< Engine* > _engines;
		sf::Clock _game_clock;
		bool _running;
	};

}

#endif
