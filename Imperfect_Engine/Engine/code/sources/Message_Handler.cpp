/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Message_Handler.h"

namespace imeng
{
	void Message_Handler::register_listener(const std::string& id, Listener& listener)
	{
		listeners[id].push_back (&listener);
	}

	void Message_Handler::unregister_listener(Listener & listener)
	{
		for (auto map_item = listeners.begin(), map_end = listeners.end(); map_item != map_end; ++map_item)
		{
			for (auto list_item = map_item->second.begin(), list_end = map_item->second.end(); list_item != list_end; ++list_item)
			{
				if (*list_item == &listener)
				{
					map_item->second.erase(list_item);
					return;
				}
			}
		}
	}

	void Message_Handler::send(Message & message)
	{
		if (listeners.count(message))
		{
			for (auto listener : listeners[message.get_id()])
			{
				listener->handle_message(message);
			}
		}
	}
}
