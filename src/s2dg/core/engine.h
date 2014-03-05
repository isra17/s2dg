#ifndef S2DG_ENGINE_H
#define S2DG_ENGINE_H

#include <SFML/System.hpp>

namespace s2dg {

	class Game;

	class Engine {
	public:
		Engine(int cid);
		virtual ~Engine();

		virtual void process(const sf::Time& elapsed) = 0;

		virtual void on_start() {};
		virtual void on_stop() {};

		int cid() const { return _cid; };
	private:
		int _cid;
	};

}

#endif
