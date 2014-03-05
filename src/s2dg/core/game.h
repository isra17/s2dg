#ifndef S2DG_GAME_H
#define S2DG_GAME_H

#include <vector>
#include <memory>

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

		bool is_running() { return _running; };

		int run();
		void stop();
	private:
		std::vector< Engine* > _engines;
		bool _running;
	};

}

#endif
