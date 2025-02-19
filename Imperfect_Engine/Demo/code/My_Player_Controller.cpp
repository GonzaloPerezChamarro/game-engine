
/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#pragma once

#include "My_Player_Controller.h"
#include "script_registry.h"

#include "Scene.h"

#include <iostream>
#include <math.h>
#include <array>

namespace imeng
{
	My_Player_Controller::My_Player_Controller() :Behaviour()
	{
		std::string script_id("controller");
		register_script(script_id, this);

		next_number = 1;
	}

	void My_Player_Controller::start(Entity* entity)
	{
		static std::array<std::string, 5> numbersNames = { "numberOne", "numberTwo" , "numberThree" , "numberFour" , "numberFive" };

		Scene* scene = entity->get_scene();

		transform = scene->get_entity("Head")->get_transform();

		for (int i = 0; i < numbersNames.size(); ++i)
		{
			numbers.emplace_back((scene->get_entity(numbersNames[i])->get_transform()));
		}

		walls_tr = scene->get_entity("wall")->get_transform();
	}

	void My_Player_Controller::update(Entity* entity, float deltaTime)
	{
		if (next_number <= numbers.size())
		{
			check_collisions(entity);

			auto tr = transform.lock();
			if (tr->get_position().y < -3)
				tr->set_position(glm::vec3(tr->get_position().x, -3, tr->get_position().z));
			if (tr->get_position().y > 3)
				tr->set_position(glm::vec3(tr->get_position().x, 3, tr->get_position().z));
			if (tr->get_position().x < -3)
				tr->set_position(glm::vec3(-3, tr->get_position().y, tr->get_position().z));
			if (tr->get_position().x > 3)
				tr->set_position(glm::vec3(3, tr->get_position().y, tr->get_position().z));
		}
	}

	void My_Player_Controller::check_collisions(Entity* entity)
	{
		static float collider_radio = 0.5f;

		auto tr = transform.lock();
		auto number = numbers[next_number - 1].lock();
		if (distance(tr->get_position(), number->get_position()) < collider_radio)
		{
			number->get_entity()->enabled(false);
			++next_number;

			if (next_number > numbers.size())
			{
				walls_tr.lock()->get_entity()->enabled(false);
			}
		}
	}

	float My_Player_Controller::get_distance(glm::vec3 a, glm::vec3 b) 
	{
		float distance = std::sqrtf(std::powf((b.x - a.x),2) + 
									std::powf((b.y - a.y),2) +
									std::powf((b.z - a.z),2));
		return distance;
	}

}

