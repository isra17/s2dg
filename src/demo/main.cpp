#include <s2dg/core/game.h>
#include <s2dg/gfx/sfml_renderer.h>
#include <s2dg/input/sfml_input.h>
#include <s2dg/entity/entity_manager.h>
#include <s2dg/entity/entity.h>
#include <s2dg/entity/component/debug.h>
#include <s2dg/entity/component/player_controller.h>

using namespace s2dg;

int main () {
	Game& game = Game::get_instance();
	SfmlRenderer *renderer = new SfmlRenderer();
	SfmlInput *input = new SfmlInput(renderer->window());
	EntityManager* entity_manager = new EntityManager();
	
	game.add_engine(renderer);
	game.add_engine(input);
	game.add_engine(entity_manager);

	std::shared_ptr<Entity> test_entity(new Entity());
	test_entity->add_component(std::make_shared<com::Debug>());
	test_entity->add_component(std::make_shared<com::PlayerController>(100.f));

	entity_manager->entity_set().insert(test_entity);

	return game.run();
};