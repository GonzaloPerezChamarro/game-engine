/**
 * @file Component.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase base de un componente
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include <rapidxml.hpp>

namespace imeng {
	class Entity;

	class Component {

	public:

		typedef rapidxml::xml_node<> xmlNode;
		typedef rapidxml::xml_attribute<> xmlAttrib;
	protected:
		/**
		* @brief Puntero a la entidad a la que pertenece
		*/
		Entity * entity;

	public:
		/**
		 * @brief Construct a new Component object
		 * 
		 * @param parent Entidad del componente
		 */
		Component(Entity * parent);

		/**
		 * @brief Destroy the Component object
		 * 
		 */
		virtual ~Component() {}

		virtual bool initialize() = 0;
		virtual bool parse_property(xmlNode * data) = 0;
		virtual void finalize() = 0;
		virtual void run(float deltaTime) = 0;

		/**
		 * @brief Get the entity object
		 * 
		 * @return Entity* Entidad a la que pertenece
		 */
		Entity * get_entity();
	};


}

