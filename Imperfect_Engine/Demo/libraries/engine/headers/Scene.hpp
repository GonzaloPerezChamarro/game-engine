#pragma once


#include "Window.hpp"
#include "Kernel.hpp"
#include "Entity.hpp"
#include "Module.hpp"
#include <rapidxml.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::map;

namespace imeng {
	class Entity;
	class Module;
	class Task;
	class Kernel;

	class Scene {

		typedef map < std::string, std::shared_ptr<Module>> Module_Map;
		typedef map<std::string, std::shared_ptr<Entity>> Entity_Map;

		typedef rapidxml::xml_node<> xml_node;
		typedef rapidxml::xml_attribute<> xml_attrib;

	private:
		Window * window;
		Kernel * kernel;

		Module_Map modules_map;
		Entity_Map entities_map;

	public:

		Scene(const string &, Window *);
		~Scene() = default;

		void execute();

	private:

		bool load(const string &);
		void init_kernel();
		bool parse_scene(xml_node *);
		bool parse_entities(xml_node *);
		bool parse_components(xml_node *, Entity & );

		
	};

}
