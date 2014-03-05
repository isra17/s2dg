#include "entity.h"
#include "component.h"

#include <cassert>

using namespace s2dg;

Entity::Entity() {}


void Entity::add_component(std::shared_ptr<Component> component) {
	assert(_components.find(component->cid()) == _components.end());

	_components[component->cid()] = component;
}

std::shared_ptr<Component> Entity::get_component(int cid) const {
	std::shared_ptr<Component> c;
	auto c_it = _components.find(cid);
	if (c_it != _components.end()) {
		c = c_it->second;
	}

	return c;
}

void Entity::init() {
	for (auto c : _components) {
		c.second->init();
	}
}

void Entity::update() {
	for (auto c : _components) {
		c.second->update();
	}
}

void Entity::deinit() {
	for (auto c : _components) {
		c.second->disown();
	}
}

void Entity::render(sf::RenderTarget& target) const {
	for (auto c : _components) {
		c.second->draw(target, _transform.getTransform());
	}
}
