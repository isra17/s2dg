#include "entity_manager.h"
#include "entity.h"

using namespace s2dg;

EntityManager::EntityManager() 
: Engine(EntityManager::CID)
{}


EntityManager::~EntityManager() {}


void EntityManager::process(const sf::Time& elapsed) {
	for (auto entity : _entity_set) {
		entity->update(elapsed);
	}
}
