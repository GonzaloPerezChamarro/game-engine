/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Character_Module.h"
#include "Entity.h"

namespace imeng
{
	Character_Module::Character_Module_Factory character_factory;

	Character_Module::Character_Module_Factory::Character_Module_Factory()
	{
		Module::register_module("character", this);
	}

	std::shared_ptr<Module> Character_Module::Character_Module_Factory::create_module(Scene * scene)
	{
		return std::shared_ptr<Character_Module>(new Character_Module(scene));
	}

	Character_Module::Character_Task::Character_Task(Character_Module * module, Scene* scene, bool finished)
		:Task(scene, 2, finished), module(module)
	{

	}

	bool Character_Module::Character_Task::initialize()
	{
		for (auto c : module->character_components)
		{
			if (!c->initialize())
				return false;
		}

		return true;
	}

	void Character_Module::Character_Task::run(float deltaTime)
	{
		for (auto c : module->character_components)
		{
			c->run(deltaTime);
		}
	}

	bool Character_Module::Character_Task::finalize()
	{
		for (auto c : module->character_components)
		{
			c->finalize();
		}

		return true;
	}

	std::shared_ptr<Component> Character_Module::create_component(Entity & entity, rapidxml::xml_node<> * data)
	{
		std::cout << "Creating Component Character" << std::endl;

		std::shared_ptr<Character_Component> character_comp{ new Character_Component(&entity) };
		entity.add_component("character", character_comp);
		character_components.push_back(character_comp);

		return character_comp;
	}
}
