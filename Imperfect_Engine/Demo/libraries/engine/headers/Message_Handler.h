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
			virtual void handle_message(const Message & message) = 0;
		};

	private:
		std::map<std::string, Listener*> listeners;
		std::map<std::string, std::list<Listener*>> listener_list;

	public:

		void register_listener(const std::string&, Listener&);
		void unregister_listener(Listener&);

		void send(const Message &);
		void send_list(const Message &);
	};
}
