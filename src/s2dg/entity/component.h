#ifndef S2DG_COMPONENT_H
#define S2DG_COMPONENT_H

#include <memory>
#include <cassert>
#include <string>

#include <SFML/Graphics.hpp>

#include "entity.h"

namespace s2dg {

	class Entity;

	class Component : sf::Drawable {
	public:
		Component(int cid, std::string name);
		virtual ~Component() {};

		int cid() const { return _cid; };
		std::string name() const { return _name; };
		std::shared_ptr<Entity> owner() const { return _owner; };
		sf::Transformable& transform() { return _owner->transform(); };

		virtual void init() {};
		virtual void update(const sf::Time& elapsed) {};
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {};
	private:
		friend Entity;
		void on_owned(std::shared_ptr<Entity> owner);
		void disown();

		int _cid;
		std::string _name;

		std::shared_ptr<Entity> _owner;
	};

}

#endif
