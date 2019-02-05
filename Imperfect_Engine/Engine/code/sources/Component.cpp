/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gráficos y Plugins

*********************************
*/

#include "Component.hpp"
#include "Entity.hpp"

namespace imeng
{
	Component::Component(Entity * parent) :entity(parent) {}

	Entity * Component::get_entity() { return entity; }
}

