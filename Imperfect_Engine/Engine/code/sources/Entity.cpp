/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/
#include "Entity.h"
#include "Render_Component.h"

namespace imeng
{
	Entity::Entity(Scene * scene)
		:scene_parent(scene), transform(nullptr), parent(nullptr)
	{

	}

	bool Entity::initialize() 
	{
		return true;
	}

	bool Entity::add_component(const string& name, std::shared_ptr<Component> component)
	{
		if (components.count(name) != 0)
			return false;
		
		components[name] = component;
		return true;
	}

	std::shared_ptr<Component> Entity::get_component(const string & name) const
	{
		return have_component(name) ? components.at(name) : nullptr;
	}
	
	bool Entity::have_component(const string & name) const
	{
		return components.find(name) != components.end();
	}

	void Entity::enabled(bool visibility)
	{
		dynamic_cast<Mesh_Component*>(get_component("mesh").get())->get_mesh()->set_visible(visibility);
	}


}