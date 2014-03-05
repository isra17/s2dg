#ifndef S2DG_ENTITY_H
#define S2DG_ENTITY_H

#include <map>
#include <memory>

namespace s2dg {

	class Component;

	class Entity {
	public:
		Entity();

		// Component management
		void add_component(std::shared_ptr<Component> component);

		/** Return a pointer to the component with the type of cid or null if none were found **/
		std::shared_ptr<Component> get_component(int cid);

		template<class C>
		std::shared_ptr<Component> get_component() {
			return get_component(C::CID);
		};

		// Init components
		void init();

		// Entity logic
		void update();

		// Free entity ressource
		void deinit();
	private:
		std::map< int, std::shared_ptr<Component> > _components;
	};

}

#endif
