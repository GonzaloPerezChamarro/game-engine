
/**
 * @file Behaviour.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Base class of a script/behavior
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Entity.hpp"
#include <string>


namespace imeng
{
	class Behaviour
	{

	public:
		/* Constructor */
		Behaviour() {}

	public:
		/**
		 * @brief Virtual method called at the begining
		 * @param Owner entity
		 */
		virtual void start(Entity*) = 0;

		/**
		 * @brief Virtual method. Called every tick
		 * @param Owner entity
		 * @param delta time
		 */
		virtual void update(Entity*, float) = 0;
	};
}
