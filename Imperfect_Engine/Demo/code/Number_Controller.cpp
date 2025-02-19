
/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#pragma once


#include "Number_Controller.h"
#include "script_registry.h"

#include <iostream>

namespace imeng
{
	Number_Controller::Number_Controller() : Behaviour()
	{
		std::string script_id("number");
		register_script(script_id, this);
	}

	void Number_Controller::update(Entity* entity, float deltaTime)
	{
		entity->get_transform()->set_rotation(glm::vec3(0.f, 1.f, 0.f) * deltaTime);
	}
}