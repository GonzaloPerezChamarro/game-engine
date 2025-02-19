/**
 * @file My_Player_Controller.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase que controla al jugador
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include "Behaviour.h"

namespace imeng
{
	class Scene;

	class My_Player_Controller : public Behaviour
	{
	private:
		
		typedef Transform_Module::Transform_Component Transform;
		
		/**
		 * @brief Puntero al transform de la entidad
		 * 
		 */
		Transform * transform;
		
		/**
		 * @brief Puntero al transform numero 1
		 * 
		 */
		Transform * tr1;
		/**
		 * @brief Puntero al transform numero 2
		 * 
		 */
		Transform * tr2;
		/**
		 * @brief Puntero al transform numero 3
		 * 
		 */
		Transform * tr3;
		/**
		 * @brief Puntero al transform numero 4
		 *
		 */
		Transform * tr4;
		/**
		 * @brief Puntero al transform numero 5
		 *
		 */
		Transform * tr5;
		/**
		 * @brief Puntero al transform de los muros
		 *
		 */
		Transform * walls_tr;
		/**
		 * @brief Indice del siguiente numero a coger
		 *
		 */
		int next_number;
		
	public:
		
		/**
		 * @brief Constructor
		 * 
		 */
		My_Player_Controller();

		/**
		 * @brief Se llama al iniciar el juego
		 * 
		 * @param entity Entidad del script
		 */
		void start(Entity* entity) override;

		/**
		 * @brief Se llama una vez por frame
		 * 
		 * @param entity Entidad del script
		 * @param deltaTime Tiempo delta
		 */
		void update(Entity* entity, float deltaTime) override;

	private:

		/**
		 * @brief Gestiona las colisiones con el resto de objetos
		 * 
		 * @param entity Entidad del script
		 */
		void check_collisions(Entity* entity);

		/**
		 * @brief Get the distance object 
		 * 
		 * @param point_a Punto uno
		 * @param point_b Punto dos
		 * @return float Distancia entre puntos
		 */
		float get_distance(glm::vec3 point_a, glm::vec3 point_b);
	};
}




