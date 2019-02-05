/**
 * @file Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase base de un modulo
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include <map>
#include <string>
#include <rapidxml.hpp>

#include <iostream>

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
			/**
			 * @brief Create a module object
			 * 
			 * @return std::shared_ptr<Module> Modulo creado
			 */
			virtual std::shared_ptr<Module> create_module(Scene*) = 0;
		};
	public:
		/**
		 * @brief Get the task object
		 * 
		 * @return Task* Tarea
		 */
		virtual Task * get_task() = 0;

		/**
		 * @brief Create a component object
		 * 
		 * @return std::shared_ptr<Component> 
		 */
		virtual std::shared_ptr<Component> create_component(Entity &, rapidxml::xml_node<> *) = 0;

		typedef map <string,Factory*> Factories_Map;

	private:
		
		/**
		* @brief Mapa de factorias
		*/
		static Factories_Map factories;

	protected:
		
		/**
		* @brief Puntero a la escena
		*/
		Scene * scene;

	public:

		/**
		 * @brief Construct a new Module object
		 * 
		 * @param owner Escena 
		 */
		Module(Scene * owner);

		/**
		 * @brief Destructor virtual por defecto
		 * 
		 */
		virtual ~Module() = default;

		/**
		 * @brief Registra una factoria de modulo
		 * 
		 * @param name Nombre del modulo
		 * @param factory Puntero a la factoria
		 */
		static void register_module(string name,Factory* factory);

		/**
		 * @brief Devuelve un puntero a la escena del modulo
		 * 
		 * @return Scene* 
		 */
		Scene * get_scene() { return scene; }

		/**
		 * @brief Devuelve el mapa de factorias
		 * 
		 * @return Factories_Map& 
		 */
		static Factories_Map & get_factories_map();
		
		/**
		 * @brief Recibe el nombre de una factoria
		 * 
		 * @return Factory* Devuelve un puntero a la factoria pedida
		 */
		static Factory* get_factory(std::string &);

	};
	
}
