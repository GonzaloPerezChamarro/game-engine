/**
 * @file Character_Component.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Componente que emula el movimiento de un personaje (2D)
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
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

		/**
		 * @brief Puntero al input
		 * 
		 */
		Input * input;

		/**
		* @brief Velocidad actual del character
		*/
		Variant current_speed;

		/**
		* @brief velocidad del character
		*/
		Variant velocity;

		/**
		* @brief mensaje de movimiento
		*/
		Message move_up, move_down, move_right, move_left;

	public:
		/*!
		 * @brief Constructor del character
		 * 
		 * @param Entidad propia del componente
		 */
		Character_Component(Entity *);

		/**
		 * @brief destructor 
		 * 
		 */
		~Character_Component();

	private:

		/**
		 * @brief Metodo que recibe los mensajes
		 * 
		 * @param message Mensaje captado
		 */
		void handle_message(Message & message) override;

	public:


		bool initialize() override;
		void run(float deltaTime) override;
		bool parse_property(xmlNode * data) override;
		void finalize() override;

		/**
		 * @brief Modifica la velocidad actual
		 * 
		 * @param s Velocidad
		 */
		void set_speed(Variant & s) { current_speed = s; }

	};
}