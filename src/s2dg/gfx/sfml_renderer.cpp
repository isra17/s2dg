#include "sfml_renderer.h"
#include "../core/game.h"
#include "../entity/entity.h"
#include "../entity/entity_manager.h"

using namespace s2dg;

SfmlRenderer::SfmlRenderer() 
: Engine(SfmlRenderer::CID)
{
	_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Some 2D Game...");
}


SfmlRenderer::~SfmlRenderer() {}

void SfmlRenderer::on_start() {
	_entity_manager = Game::get_instance().get_engine<EntityManager>();
}

void SfmlRenderer::process(const sf::Time& elapsed) {
	_window->clear(sf::Color::Black);

	for (auto entity : _entity_manager->entity_set()) {
		entity->render(*_window);
	}

	_window->display();
}