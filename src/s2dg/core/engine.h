#ifndef S2DG_ENGINE_H
#define S2DG_ENGINE_H

namespace s2dg {

	class Game;

	class Engine {
	public:
		Engine();
		virtual ~Engine();

		virtual void process() = 0;

		virtual void on_start() {};
		virtual void on_stop() {};
	};

}

#endif
