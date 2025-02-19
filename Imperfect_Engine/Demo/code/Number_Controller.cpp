/**
 * @file Number_Controller.cpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase de control de un Numero
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include "Number_Controller.h"
#include "script_registry.h"

#include <iostream>

namespace imeng
{
	Number_Controller::Number_Controller() :Behaviour()
	{
		std::string script_id("number");
		register_script(script_id, this);
	}

	void Number_Controller::start(Entity*)
	{
		
	}

	/**
	 * @brief Realiza la rotacion del Numero
	 * 
	 * @param entity Entidad del script
	 * @param deltaTime tiempo delta
	 */
	void Number_Controller::update(Entity* entity, float deltaTime)
	{
		entity->get_transform()->set_rotation(glm::vec3(0.f, 1.f, 0.f) * deltaTime);
	}
}