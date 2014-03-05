#ifndef S2DG_ENTITY_H
#define S2DG_ENTITY_H

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

namespace s2dg {

	class Component;

	class Entity {
	public:
		Entity();

		// Component management
		void add_component(std::shared_ptr<Component> component);

		/** Return a pointer to the component with the type of cid or null if none were found **/
		std::shared_ptr<Component> get_component(int cid) const;

		template<class C>
		std::shared_ptr<Component> get_component() const {
			return get_component(C::CID);
		};

		const sf::Transformable& transform() const { return _transform; };

		// Init components
		void init();

		// Entity logic
		void update();

		// Free entity ressource
		void deinit();
		
		// Render entity
		void render(sf::RenderTarget& target) const;
	private:
		sf::Transformable _transform;
		std::map< int, std::shared_ptr<Component> > _components;
	};

}

#endif
