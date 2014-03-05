#include "sfml_input.h"

#include "../core/game.h"

using namespace s2dg;

SfmlInput::SfmlInput(std::shared_ptr<sf::Window> window)
 : Engine(SfmlInput::CID), _window(window) 
{
	
}


SfmlInput::~SfmlInput() { }

void SfmlInput::process() {
	sf::Event event;
	while (_window->pollEvent(event)) {
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed) {
			Game::get_instance().stop();
		}
	}
}


void SfmlInput::on_stop() {
	_window->close();
}
