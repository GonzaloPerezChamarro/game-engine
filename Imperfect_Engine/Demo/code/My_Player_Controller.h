/**
 * @file My_Player_Controller.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Class that controls the player
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


#include "Behaviour.h"
#include <vector>

namespace imeng
{
	class Scene;

	class My_Player_Controller : public Behaviour
	{
	private:
		
		typedef Transform_Module::Transform_Component Transform;
		
		/* Transform of the player */
		std::weak_ptr<Transform> transform;
		
		/* Vector of pointers to transforms */
		std::vector<std::weak_ptr<Transform>> numbers;

		/* Pointer to walls */
		std::weak_ptr<Transform> walls_tr;
		
		/* Next number */
		int next_number;
		
	public:
		
		/* Constructor */
		My_Player_Controller();

		/* Initialize the player */
		void start(Entity* entity) override;

		/* Updates the player */
		void update(Entity* entity, float deltaTime) override;

	private:

		/* Manages the collision with other objects */
		void check_collisions(Entity* entity);

		// TODO: remove this function. Use glm::distance instead
		/* Returns the distance between two points */
		static float get_distance(glm::vec3 point_a, glm::vec3 point_b);
	};
}




