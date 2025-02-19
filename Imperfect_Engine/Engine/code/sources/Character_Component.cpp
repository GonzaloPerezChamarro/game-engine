
/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/


#include "Character_Component.h"
#include "Transform_Module.h"
#include "Scene.h"


namespace imeng
{
	Character_Component::Character_Component(Entity * entity)
		:Component(entity),
		input(new Input), current_speed(0.f), velocity(3.f),
		move_up("up"),
		move_down("down"),
		move_right("right"),
		move_left("left")
	{
		entity->get_scene()->get_message_handler()->register_listener("up", *this);
		entity->get_scene()->get_message_handler()->register_listener("down", *this);
		entity->get_scene()->get_message_handler()->register_listener("right", *this);
		entity->get_scene()->get_message_handler()->register_listener("left", *this);
	}

	Character_Component::~Character_Component()
	{
		delete input;
	}

	bool Character_Component::initialize()
	{
	
		return true;
	}

	void Character_Component::run(float deltaTime)
	{
		current_speed = velocity.as_float() * deltaTime;

		if (input->get_key_SDL(Key::W) || input->get_key_SDL(Key::ARROW_UP))
		{
			move_up["up"] = current_speed;
			entity->get_scene()->get_message_handler()->send(move_up);
		}
		else if (input->get_key_SDL(Key::S) || input->get_key_SDL(Key::ARROW_DOWN))
		{
			move_down["down"] = current_speed;
			entity->get_scene()->get_message_handler()->send(move_down);
		}
		else if (input->get_key_SDL(Key::D) || input->get_key_SDL(Key::ARROW_RIGHT))
		{
			move_right["right"] = current_speed;
			entity->get_scene()->get_message_handler()->send(move_right);
		}
		else if (input->get_key_SDL(Key::A) || input->get_key_SDL(Key::ARROW_LEFT))
		{
			move_left["left"] = current_speed;
			entity->get_scene()->get_message_handler()->send(move_left);
		}
	}

	void Character_Component::finalize() {}

	bool Character_Component::parse_property(xmlNode * data) { return true; }

	void Character_Component::handle_message(Message & message)
	{
		std::shared_ptr<Transform_Module::Transform_Component>  transform = entity->get_transform();

		if (message.get_id() == "up") {
			transform->move(glm::vec3(0.f, 1.f, 0.f) * message.get(message.get_id()).as_float());
		}
		else if (message.get_id() == "down") {
			transform->move(glm::vec3(0.f, -1.f, 0.f) * message.get(message.get_id()).as_float());
		}
		else if (message.get_id() == "left") {
			transform->move(glm::vec3(-1.f, 0.f, 0.f) * message.get(message.get_id()).as_float());
		}
		else if (message.get_id() == "right") {
			transform->move(glm::vec3(1.f, 0.f, 0.f) * message.get(message.get_id()).as_float());
		}
	}
}
