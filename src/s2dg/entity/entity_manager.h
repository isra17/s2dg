#ifndef S2DG_ENTITY_MANAGER_H
#define S2DG_ENTITY_MANAGER_H

#include "../core/engine.h"

#include <set>
#include <memory>

namespace s2dg {

	class Entity;
	typedef std::set< std::shared_ptr<Entity> > EntitySet;

	class EntityManager :
		public Engine {
	public:
		static const int CID = 0xD97149EC;

		EntityManager();
		virtual ~EntityManager();

		void process(const sf::Time& elapsed) override;

		EntitySet& entity_set(){ return _entity_set; };

	private:
		EntitySet _entity_set;
	};

}

#endif
