/**
 * @file Message_Handler.h
 * @author Gonzalo Perez Chamarro
 * @brief Clase que gestiona los mensajes
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include <map>
#include <list>
#include <string>
#include "Message.h"

namespace imeng {

	class Message_Handler {
	public:
		/**
		 * @brief Listener
		 * 
		 */
		struct Listener
		{
			/**
			 * @brief Metodo virtual que captura los mensajes
			 * 
			 * @param message Mensaje recibido
			 */
			virtual void handle_message(Message & message) = 0;
		};

	private:
		/**
		* @brief Mapa de listeners
		*/
		std::map<std::string, std::list<Listener*>> listeners;

	public:

		/**
		 * @brief Registra un Listener en el mapa
		 * 
		 */
		void register_listener(const std::string&, Listener&);

		/**
		 * @brief Elimina el listener recibido del mapa
		 * 
		 */
		void unregister_listener(Listener&);

		/**
		 * @brief Envia un mensaje
		 * 
		 */
		void send(Message &);

	};
}
