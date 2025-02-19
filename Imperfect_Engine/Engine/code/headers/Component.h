
/**
 * @file Component.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Base class of a component
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <rapidxml.hpp>

namespace imeng 
{
	class Entity;

	class Component 
	{
	public:

		typedef rapidxml::xml_node<> xmlNode;
		typedef rapidxml::xml_attribute<> xmlAttrib;

	public:
		/* Constructor */
		Component(Entity * parent);

		/* Destructor */
		virtual ~Component() {}

		virtual bool initialize() = 0;
		virtual bool parse_property(xmlNode * data) = 0;
		virtual void finalize() = 0;
		virtual void run(float deltaTime) = 0;

		/* Returns the owner */
		Entity* get_entity() const;

	protected:
		/* Pointer to owner entity */
		Entity* entity;
	};


}

