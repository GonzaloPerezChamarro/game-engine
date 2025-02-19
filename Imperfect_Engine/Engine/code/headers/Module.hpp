/**
 * @file Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Base class of a module
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <map>
#include <string>
#include <rapidxml.hpp>

#include <iostream>

using std::map;
using std::string;


namespace imeng 
{
	class Scene;
	class Task;
	class Component;
	class Entity;

	class Module 
	{
	public:
		class Factory
		{
		public:
			/**
			 * @brief Create a module object
			 * @return std::shared_ptr<Module> Module created
			 */
			virtual std::shared_ptr<Module> create_module(Scene*) = 0;
		};

		typedef map <string, Factory*> Factories_Map;

		typedef rapidxml::xml_node<> xml_node;
		typedef rapidxml::xml_attribute<> xml_attribute;

	public:
		/**
		 * @brief Construct a new module object
		 * @param owner scene
		 */
		Module(Scene* owner) : scene(owner) {}

		/* Destructor*/
		virtual ~Module() = default;

		/**
		 * @brief Registers a factory of a kind of module
		 * @param name name of the module
		 * @param factory Pointer to the factory
		 */
		static void register_module(const string& name, Factory* factory);

		/* Returns the factories map */
		static Factories_Map& get_factories_map();

		/* Returns a factory by the name of the module */
		static Factory* get_factory(std::string&);

		/* Pure virtual. Returns a pointer to the task of the module */
		virtual Task* get_task() = 0;

		/* Creates a component for an entity */
		virtual std::shared_ptr<Component> create_component(Entity&, rapidxml::xml_node<>*) = 0;

		/* Returns the owner scene */
		Scene* get_scene() const { return scene; }

	protected:
		/* Pointer to the scene */
		Scene * scene;

	private:
		/* Factories map */
		static inline Factories_Map factories;
	};
	
}
