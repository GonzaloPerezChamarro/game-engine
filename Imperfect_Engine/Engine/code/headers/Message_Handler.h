/**
 * @file Message_Handler.h
 * @author Gonzalo Perez Chamarro
 * @brief Class that manages the messages
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
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
		struct Listener
		{
			/**
			 * @brief Virtual pure method. It handles the messages
			 * @param message Mensaje recibido
			 */
			virtual void handle_message(Message & message) = 0;
		};

	private:
		/* Map of listeners by id */
		std::map<std::string, std::list<Listener*>> listeners;

	public:

		/**
		 * @brief Registers a new listener
		 * @param listener id
		 * @param reference to listener
		 */
		void register_listener(const std::string&, Listener&);

		/**
		 * @brief Removes a listener
		 */
		void unregister_listener(Listener&);

		/**
		 * @brief Sends a message
		 * @param message to send
		 */
		void send(Message &);

	};
}
