#pragma once

#include <map>
#include <string>

#include "Task.hpp"
#include "Scene.hpp"
#include <rapidxml.hpp>
#include "Component.hpp"

using std::map;
using std::string;


namespace imeng {

	class Scene;
	class Task;
	class Component;
	class Entity;

	class Module {

	public:
		typedef rapidxml::xml_node<> xml_node;
		typedef rapidxml::xml_attribute<> xml_attribute;

	public:
		class Factory
		{
		public:
			virtual std::shared_ptr<Module> create_module() = 0;
		};
	public:
		virtual Task * get_task() const = 0;
		virtual std::shared_ptr<Component> create_component(Entity &, rapidxml::xml_node<> *) = 0;

	
		typedef map <string, Module::Factory *> Module_Map;
		static Module_Map modules;

	protected:
		
		const Scene * scene;

	public:

		Module(Scene * owner);
		virtual ~Module();

		static void register_module(string name, Module::Factory* factory)
		{
			modules[name] = factory;
		}

	};

}
