/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Module.hpp"
#include "Entity.hpp"
#include "Kernel.hpp"
#include "Render_Module.hpp"
#include "Transform_Module.hpp"
#include "Script_Module.hpp"
#include "Character_Module.hpp"
#include "Scene.hpp"
#include "Input_Task.hpp"

#include <rapidxml.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using std::fstream;

namespace imeng
{
	Scene::Scene(const string & file_path, Window * window)
		:window(window), kernel(&Kernel::instance()), message_handler(new Message_Handler)
	{
		// Load the scene
		load(file_path);

		// Add the tasks to the kernel
		for (auto it = modules_map.begin(), end = modules_map.end();
			it != end;
			++it)
		{
			kernel->add_task(*it->second->get_task());
		}

		// Add the input tasks
		Input_Task * task = new Input_Task(this);
		kernel->add_task(*task);

		// Initialize entities
		if(!init_entities()) std::cout << "Error" << std::endl;

		// Initialize the kernel
		std::cout << "Init kernel" << std::endl;
		init_kernel();
	}

	bool Scene::load(const string & file_path)
	{
		std::cout << "Loading scene.." << std::endl;

		fstream xml(file_path, fstream::in);
		rapidxml::xml_document<> document;

		if (xml.good())
		{
			std::vector<char> content;

			int character = 0;
			while (character != -1)
			{
				character = xml.get();
				if (character != -1)
					content.emplace_back((char)character);
			}

			xml.close();
			content.emplace_back(0);

			document.parse<0>(content.data());
			xml_node* root = document.first_node();

			if (root && string{ root->name() } == "scene")
			{
				if (!parse_scene(root))
				{
					return false;
				}
			}
			return true;
		}

		return false;
	}

	bool Scene::parse_scene(xml_node * scene_node)
	{
		for (xml_node * child_node = scene_node->first_node();
			child_node;
			child_node = child_node->next_sibling()
			)
		{
			if (child_node->type() == rapidxml::node_element)
			{
				if (string{ child_node->name() } == "entities")
				{
					if (!parse_entities(child_node))
					{
						std::cout << "Parse scene failed" << std::endl;
						return false;
					}
				}
			}
		}

		return true;

	}

	bool Scene::parse_entities(xml_node * entities)
	{
		std::cout << "Parsing entities" << std::endl;

		string name;
		for (xml_node * child_node = entities->first_node();
			child_node;
			child_node = child_node->next_sibling()
			)
		{
			if (child_node->type() == rapidxml::node_element &&
				string{ child_node->name() } != "entity")
			{
				std::cout << "Parse entities error: Child node is not an entity" << std::endl;
				return false;
			}

			for (xml_attrib* attrib = child_node->first_attribute();
				attrib;
				attrib = attrib->next_attribute()
				)
			{
				if (string{ attrib->name() } == "name")
				{
					name = attrib->value();
					std::cout << "<<Entity "<< name << std::endl;
				}
			}

			if (name.empty()) return false;

			std::shared_ptr<Entity> entity(new Entity(this));
			entities_map[name] = entity;
			
			for (xml_node * components = child_node->first_node();
				components;
				components = components->next_sibling()
				)
			{
				if (components->type() == rapidxml::node_element)
				{
					if (string(components->name()) == "components")
					{
						if (!parse_components(components, *entity))
						{
							std::cout << "Parse entities error: parse components failed" << std::endl;
							return false;
						}
					}
				}
			}
		}

		return true;
	}

	bool Scene::parse_components(xml_node * components, Entity & entity)
	{
		Module::Factories_Map& factories = Module::get_factories_map();

		string type;

		for (xml_node* child = components->first_node();
			child;
			child = child->next_sibling())
		{
			if (child->type() == rapidxml::node_element && string(child->name()) != "component")
				return false;

			for (xml_attrib * attrib = child->first_attribute();
				attrib;
				attrib = attrib->next_attribute())
			{
				if (string(attrib->name()) == "type")
				{
					type = attrib->value();
				}
			}
			

			if (type.empty()) 
			{
				std::cout << "Parse components error: type empty" << std::endl;
				return false;
			}

			
			if (modules_map.count(type) == 0)
			{

				if (factories.count(type) == 0)
				{
					std::cout << "Parse components log: factories count type 0" << std::endl;

					if (type == "render")
						Render_Module::Render_Module_Factory::Render_Module_Factory();
					else if (type == "transform")
						Transform_Module::Transform_Module_Factory::Transform_Module_Factory();
					else if (type == "script")
						Script_Module::Script_Module_Factory::Script_Module_Factory();
					else if (type == "character")
						Character_Module::Character_Module_Factory::Character_Module_Factory();
					
					//return false;
				}

				std::cout << "Creating module -->  " << type << std::endl;
				modules_map[type] = factories[type]->create_module(this);
			}

			Module* mod =  modules_map[type].get();

			if (!mod) return false;

			mod->create_component(entity, child);
		}

		return true;
	}

	bool Scene::init_entities()
	{
		for (auto ent : entities_map)
		{
			if (!ent.second->initialize())
				return false;
		}
		return true;
	}

	void Scene::init_kernel()
	{
		kernel->initialize();
	}

	void Scene::execute()
	{
		kernel->execute();
	}

}

