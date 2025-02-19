/**
 * @file Scene.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Game scene
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


#include "Window.h"
#include "Entity.h"
#include "Message_Handler.h"

#include <rapidxml.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::map;

namespace imeng 
{
	class Module;
	class Task;
	class Kernel;
	class Render_Module;
	class Render_Transform;
	class Scripting_Module;
	class Transform_Module;

	class Scene 
	{
		typedef map < std::string, std::shared_ptr<Module>> Modules_Map;
		typedef map<std::string, std::shared_ptr<Entity>> Entity_Map;

		typedef rapidxml::xml_node<> xml_node;
		typedef rapidxml::xml_attribute<> xml_attrib;

	public:

		/**
		 * @brief Constructor
		 * @param XML path
		 * @param pointer to the window
		 */
		Scene(const string &, Window *);

		/* Destructor by default */
		~Scene() = default;

		/* Executes the kernel */
		void execute();

		/**
		 * @brief Tries to find an entity by name
		 * @param id Name of the entity on the scene
		 */
		std::shared_ptr<Entity> get_entity(const string& id) const { return entities_map.find(id)->second; }

		/* Returns a pointer to the window */
		Window* get_window() const { return window; }

		/* Returns a pointer to the kernel */
		Kernel* get_kernel() const { return kernel; }

		/* Returns a pointer to the message handler */
		Message_Handler * get_message_handler() const { return message_handler; }

	private:
		/**
		 * @brief Loads the scene
		 * @param relative path
		 * @return true if it was succesful
		 */
		bool load(const string&);

		/* Initialize the kernel */
		void init_kernel();

		/**
		 * @brief Initialize the entities map
		 * @return true if it was succesful
		 */
		bool init_entities();

		/**
		 * @brief Parse the scene from an XML
		 * @return true if it was succesful
		 */
		bool parse_scene(xml_node*);

		/**
		 * @brief Parse the entities from an XML
		 * @return true if it was succesful
		 */
		bool parse_entities(xml_node *);

		/**
		 * @brief Parse the components of an entity from an XML
		 * @return true if it was succesful
		 */
		bool parse_components(xml_node*, Entity& );

	private:
		/* Pointer to main window */
		Window* window;

		/* Pointer to the kernel */
		Kernel* kernel;

		/* Map of modules of the scene */
		Modules_Map modules_map;

		/* Entities map */
		Entity_Map entities_map;

		/* Pointer to message distpatcher */
		Message_Handler* message_handler;
	};
}
