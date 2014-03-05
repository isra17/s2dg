#include "game.h"
#include "engine.h"

using namespace s2dg;

// Singleton implementation
Game& Game::get_instance() {
	static Game game;
	return game;
}

Game::Game() {
}


Game::~Game() {
}

int Game::run() {
	// Trigger on_start handler of engines
	for (Engine* engine : _engines) {
		engine->on_start();
	}

	_running = true;
	
	_game_clock.restart();

	// Game loop
	while (_running) {
		sf::Time elapsed = _game_clock.restart();

		for (Engine* engine : _engines) {
			// Process each engines
			engine->process(elapsed);
		}
	}

	// Trigger on_stop handler of engines
	for (Engine* engine : _engines) {
		engine->on_stop();
	}

	return 0;
}

void Game::stop() {
	_running = false;
}

void Game::add_engine(Engine* engine) {
	if (engine) {
		_engines.push_back(engine);
	}
}