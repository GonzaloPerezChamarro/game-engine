#pragma once

#include <map>
#include <string>
#include <unordered_map>

#include "Variant.hpp"

namespace imeng {


	class Message {

		std::string id;
		std::unordered_map<std::string, Variant> parameters;

		Message(const std::string& id) :id(id) {}

		void add_parameter(const std::string & name, const int & value)
		{
			parameters[name] = value;
		}

	public:

		std::string get_id()const { return id; }

		operator std::string() const
		{
			return id;
		}

		bool operator == (const Message & m) const
		{
			return this->id == m.id;
		}

		bool operator != (const Message & m) const
		{
			return this->id != m.id;
		}

		Variant & operator [](string s)
		{
			return parameters[s];
		}

	};
}
