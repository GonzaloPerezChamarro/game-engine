/**
 * @file Scene.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Escena del juego
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include "Window.hpp"
#include "Entity.hpp"
#include "Message_Handler.h"

#include <rapidxml.hpp>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::map;

namespace imeng {
	class Module;
	class Task;
	class Kernel;
	class Render_Module;
	class Render_Transform;
	class Scripting_Module;
	class Transform_Module;

	class Scene {

		typedef map < std::string, std::shared_ptr<Module>> Modules_Map;
		typedef map<std::string, std::shared_ptr<Entity>> Entity_Map;

		typedef rapidxml::xml_node<> xml_node;
		typedef rapidxml::xml_attribute<> xml_attrib;

	private:
		/**
		* @brief Puntero a la ventana principal
		*/
		Window * window;

		/**
		* @brief Puntero al kernel
		*/
		Kernel * kernel;

		/**
		* @brief Mapa de modulos de la escena
		*/
		Modules_Map modules_map;

		/**
		* @brief Mapa de entidades de la escena
		*/
		Entity_Map entities_map;

		/**
		* @brief Puntero al dispatcher
		*/
		Message_Handler * message_handler;

	public:

		/**
		 * @brief Constructor. Ruta del XML. Ventana
		 * 
		 */
		Scene(const string &, Window *);

		/**
		 * @brief Destructor por defecto
		 * 
		 */
		~Scene() = default;

		/**
		 * @brief Ejecuta el Kernel
		 * 
		 */
		void execute();

		/**
		 * 
		 * 
		 * @return Window* Ventana principal
		 */
		Window * get_window()const { return window; }

		/**
		 * @brief Devuelve el Kernel
		 * 
		 * @return Kernel* 
		 */
		Kernel * get_kernel() { return kernel; }

		/**
		 * @brief Busca una entidad por nombre
		 * 
		 * @param id Nombre de la entidad en escena
		 * @return std::shared_ptr<Entity> Entidad requerida
		 */
		std::shared_ptr<Entity> get_entity(string id) { return entities_map.find(id)->second; }

		/**
		 * @brief Get the message handler object
		 * 
		 * @return Message_Handler* 
		 */
		Message_Handler * get_message_handler()const { return message_handler; }

	private:

		/**
		 * @brief Carga la escena. Recibe la ruta relativa
		 * 
		 * @return true Carga correcta
		 * @return false Carga incorrecta
		 */
		bool load(const string &);

		/**
		 * @brief Inicializa el kernel
		 * 
		 */
		void init_kernel();

		/**
		 * @brief Inicializa el mapa de entidades
		 * 
		 * @return true Inicializacion correcta
		 * @return false Inicializacion incorrecta
		 */
		bool init_entities();

		/**
		 * @brief Parsea la escena a partir de un xml
		 * 
		 * @return true Correcto
		 * @return false Error
		 */
		bool parse_scene(xml_node *);

		/**
		 * @brief Parsea las entidades
		 * 
		 * @return true Correcto
		 * @return false Error
		 */
		bool parse_entities(xml_node *);

		/**
		 * @brief Parsea los componentes de una entidad
		 * 
		 * @return true Correcto
		 * @return false Error
		 */
		bool parse_components(xml_node *, Entity & );
		
	};

}
