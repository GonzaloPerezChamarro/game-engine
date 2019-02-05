#pragma once

#include <rapidxml.hpp>
#include "Entity.hpp"

namespace imeng {
	class Entity;

	class Component {

	protected:

		typedef rapidxml::xml_node<> xmlNode;
		typedef rapidxml::xml_attribute<> xmlAttrib;

		Entity * parent;

	public:
		Component(Entity * parent);

		virtual ~Component() {}

		virtual bool initialize() = 0;
		virtual bool parse_property(xmlNode * data) = 0;
		virtual void finalize() = 0;
		virtual void run(float deltaTime) = 0;

		Entity & get_entity();
	};


}

