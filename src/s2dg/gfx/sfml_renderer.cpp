#include "sfml_renderer.h"

using namespace s2dg;

SfmlRenderer::SfmlRenderer() {
	_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Some 2D Game...");
}


SfmlRenderer::~SfmlRenderer() {}


void SfmlRenderer::process() {
	_window->clear(sf::Color::Black);
	_window->display();
}