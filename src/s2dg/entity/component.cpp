#include "component.h"

#include <cassert>
#include <string>

using namespace s2dg;

Component::Component(int cid, std::string name)
: _cid(cid), _name(name)
{

}

void Component::on_owned(std::shared_ptr<Entity> owner) {
	// Must not be already assigned to an entity
	assert(!_owner);

	_owner = owner;
}

void Component::disown() {
	_owner.reset();
}