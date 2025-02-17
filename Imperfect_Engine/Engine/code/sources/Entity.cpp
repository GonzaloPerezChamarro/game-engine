/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gr�ficos y Plugins

*********************************
*/
#include "Entity.hpp"
#include "Render_Component.hpp"

namespace imeng
{
	Entity::Entity(Scene * scene)
		:scene_parent(scene), transform(nullptr), parent(nullptr)
	{

	}

	bool Entity::initialize() 
	{
		bool result = true;

		for (auto c : components)
		{
			if (!c.second->initialize())
			{
				result = false;
			}
		}
		return result;
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