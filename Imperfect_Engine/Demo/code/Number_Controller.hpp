/**
 * @file My_Player_Controller.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase que controla la rotacion de los numeros
 * @version 0.1
 * @date 2019-01-31
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once


#include <Behaviour.hpp>

namespace imeng
{

	class Number_Controller :public Behaviour
	{
	public:


		Number_Controller();

		void start(Entity* entity) override;

		void update(Entity* entity, float deltaTime) override;
	};
}

