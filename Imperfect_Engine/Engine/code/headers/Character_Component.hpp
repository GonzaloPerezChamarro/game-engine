/**
 * @file Character_Component.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Componente que emula el movimiento de un personaje (2D)
 * @brief Componentt that simulate the movement of a character (2D)
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Component.hpp"
#include "Message_Handler.h"
#include "Input.hpp"

namespace imeng
{
	class Character_Component :public Message_Handler::Listener, public Component
	{
	private:

		/* Pointer to the input */
		Input * input;

		/* Current character speed */
		Variant current_speed;

		/* Current character velocity */
		Variant velocity;

		/* Movement message */
		Message move_up, move_down, move_right, move_left;

	public:
		/* Constructor*/
		Character_Component(Entity *);

		/* Destructor */
		~Character_Component();

	public:
		bool initialize() override;
		void run(float deltaTime) override;
		bool parse_property(xmlNode * data) override;
		void finalize() override;

		/* Modifies the character speed */
		void set_speed(Variant & s) { current_speed = s; }

	private:
		void handle_message(Message & message) override;

	};
}