
/**
 * @file My_Player_Controller.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Class that controls a number
 * @version 1.0
 * @date 2019-01-31
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once


#include "Behaviour.h"

namespace imeng
{
	class Number_Controller : public Behaviour
	{
	public:
		/* Constructor*/
		Number_Controller();

		/* Do nothing */
		void start(Entity* entity) override {}

		/* Rotates the number */
		void update(Entity* entity, float deltaTime) override;
	};
}

