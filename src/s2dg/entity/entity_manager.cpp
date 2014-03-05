#include "entity_manager.h"
#include "entity.h"

using namespace s2dg;

EntityManager::EntityManager() {}


EntityManager::~EntityManager() {}


void EntityManager::process() {
	for (auto entity : _entity_set) {
		entity->update();
	}
}
