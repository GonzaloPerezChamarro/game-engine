
/**
 * @file Behaviour.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase a partir de la cual se hereda para agregar scripts
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
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
		/**
		 * @brief Constructor
		 * 
		 */
		Behaviour() {}

	public:
		/**
		 * @brief Metodo virtual llamado al inicio
		 * 
		 * @param Entidad del script
		 */
		virtual void start(Entity*) = 0;

		/**
		 * @brief Metodo virtual llamado una vez cada frame
		 * 
		 * @param Entidad del script
		 * @param Tiempo delta
		 */
		virtual void update(Entity*, float) = 0;


	};

	


}






