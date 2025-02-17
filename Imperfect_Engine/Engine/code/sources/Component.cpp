/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Component.hpp"
#include "Entity.hpp"

namespace imeng
{
	Component::Component(Entity * parent) : entity(parent) {}

	Entity * Component::get_entity() const { return entity; }
}

