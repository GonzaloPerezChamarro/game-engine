#pragma once

#include "My_Player_Controller.hpp"
#include "script_registry.hpp"

#include <Scene.hpp>
#include <iostream>
#include <math.h>

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
		Scene * scene = entity->get_scene();
		
		transform = dynamic_cast<Transform*>((entity->get_component("transform")).get());
		tr1 = dynamic_cast<Transform*>((scene->get_entity("numberOne")->get_transform()).get());
		tr2 = dynamic_cast<Transform*>((scene->get_entity("numberTwo")->get_transform()).get());
		tr3 = dynamic_cast<Transform*>((scene->get_entity("numberThree")->get_transform()).get());
		tr4 = dynamic_cast<Transform*>((scene->get_entity("numberFour")->get_transform()).get());
		tr5 = dynamic_cast<Transform*>((scene->get_entity("numberFive")->get_transform()).get());
		walls_tr = dynamic_cast<Transform*>((scene->get_entity("wall")->get_transform()).get());
	}

	void My_Player_Controller::update(Entity* entity, float deltaTime)
	{
		check_collisions(entity);
		
		if (next_number < 6)
		{
			if (transform->get_position().y < -3)
				transform->set_position(glm::vec3(transform->get_position().x, -3, transform->get_position().z));
			if (transform->get_position().y > 3)
				transform->set_position(glm::vec3(transform->get_position().x, 3, transform->get_position().z));
			if (transform->get_position().x < -3)
				transform->set_position(glm::vec3(-3, transform->get_position().y, transform->get_position().z));
			if (transform->get_position().x > 3)
				transform->set_position(glm::vec3(3, transform->get_position().y, transform->get_position().z));
		}
		
	}

	void My_Player_Controller::check_collisions(Entity* entity)
	{
		float collider_radio = 0.5f;
		
		if (next_number == 1)
		{
			if (distance(transform->get_position(), tr1->get_position()) < collider_radio)
			{
				tr1->get_entity()->enabled(false);
				next_number++;
			}
		}
		else if (next_number == 2)
		{
			if (distance(transform->get_position(), tr2->get_position()) < collider_radio)
			{
				tr2->get_entity()->enabled(false);
				next_number++;
			}
		}
		else if (next_number == 3)
		{
			if (distance(transform->get_position(), tr3->get_position()) < collider_radio)
			{
				tr3->get_entity()->enabled(false);
				next_number++;
			}
		}
		else if (next_number == 4)
		{
			if (distance(transform->get_position(), tr4->get_position()) < collider_radio)
			{
				tr4->get_entity()->enabled(false);
				next_number++;
			}
		}
		else if (next_number == 5)
		{
			if (distance(transform->get_position(), tr5->get_position()) < collider_radio)
			{
				tr5->get_entity()->enabled(false);
				walls_tr->get_entity()->enabled(false);
				next_number++;
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

