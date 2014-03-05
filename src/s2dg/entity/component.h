#ifndef S2DG_COMPONENT_H
#define S2DG_COMPONENT_H

#include <memory>
#include <cassert>
#include <string>

#include <SFML/Graphics.hpp>

namespace s2dg {

	class Entity;

	class Component : sf::Drawable {
	public:
		Component(int cid, std::string name);
		virtual ~Component() {};

		int cid() const { return _cid; };
		std::string name() const { return _name; };
		std::shared_ptr<Entity> owner() const { return _owner; };

		virtual void init() {};
		virtual void update() {};
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
