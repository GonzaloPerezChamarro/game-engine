/**
 * @file Message.h
 * @author Gonzalo Perez Chamarro
 * @brief Clase que representa un mensaje
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include <map>
#include <string>
#include <unordered_map>

#include "Variant.hpp"

namespace imeng {


	class Message {

		/**
		* @brief Identificador del mensaje
		*/
		std::string id;

		/**
		* @brief Parametros del mensaje
		*/
		std::unordered_map<std::string, Variant> parameters;
	public:

		/**
		 * @brief Construct a new Message object
		 * 
		 * @param id Identificador del mensaje
		 */
		Message(const std::string& id) :id(id) {}

		/**
		 * @brief Añade parametros al mensaje
		 * 
		 * @param name Nombre del parametro
		 * @param value Valor del parametro
		 */
		void add_parameter(const std::string & name, const int & value)
		{
			parameters[name] = value;
		}

	public:

		/**
		 * @brief Get the id object
		 * 
		 * @return std::string Identificador
		 */
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

		Variant & get(string s)
		{
			return parameters[s];
		}


	};
}
