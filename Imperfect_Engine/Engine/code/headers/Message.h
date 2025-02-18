/**
 * @file Message.h
 * @author Gonzalo Perez Chamarro
 * @brief Class that represent a message
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <map>
#include <string>
#include <unordered_map>

#include "Variant.hpp"

namespace imeng {


	class Message {

		/* Message id */
		std::string id;

		/* Message parameters */
		std::unordered_map<std::string, Variant> parameters;

	public:
		/**
		 * @brief Construct a new Message object
		 * @param id Message id
		 */
		Message(const std::string& id) :id(id) {}

		/**
		 * @brief Adds a parameter to the message
		 * @param name Parameter name
		 * @param value Parameter value
		 */
		void add_parameter(const std::string & name, const int & value)
		{
			parameters[name] = value;
		}

	public:
		/* Returns the message id */
		std::string get_id() const { return id; }

		/* -- Operators overloading -- */

		operator std::string() const
		{
			return id;
		}

		bool operator== (const Message& m) const
		{
			return this->id == m.id;
		}

		bool operator!= (const Message& m) const
		{
			return this->id != m.id;
		}

		Variant & operator [](string s)
		{
			return parameters[s];
		}

		Variant & get(string s)
		{
			return parameters[s];
		}
	};
}
