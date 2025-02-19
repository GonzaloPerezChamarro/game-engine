/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Component.h"
#include "Entity.h"

namespace imeng
{
	Component::Component(Entity * parent) : entity(parent) {}

	Entity * Component::get_entity() const { return entity; }
}

