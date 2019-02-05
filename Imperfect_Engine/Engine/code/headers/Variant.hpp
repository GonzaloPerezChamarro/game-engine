/**
 * @file Variant.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase Variant para alojar diferentes tipos de variable
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include <string>


using std::string;
namespace imeng
{

	class Variant
	{
	public:
		/**
		 * @brief Constructor por defecto
		 * 
		 */
		Variant():type(NONE) {}
		/**
		 * @brief Constructor booleano
		 * 
		 */
		Variant(bool b) :type(BOOL) { data.b_value = b; }
		/**
		 * @brief Constructor entero
		 * 
		 */
		Variant(int i) :type(INT) { data.n_value = i; }
		/**
		 * @brief Constructor float
		 * 
		 */
		Variant(float f) :type(FLOAT) { data.f_value = f; }
		/**
		 * @brief Constructor string
		 * 
		 */
		Variant(string s) :type(STRING) { data.s_value = new string(s); }

		/**
		 * @brief Destructor
		 * 
		 */
		~Variant() 
		{ 
			if (type == STRING) 
				delete data.s_value; 

			type = NONE;
		}

	private:

		/**
		* @brief Dato principal
		*/
		union Data
		{
			bool b_value;
			int n_value;
			float f_value;
			string * s_value;
		}data;

		/**
		* @brief Enumeracion de tipo de dato
		*/
		enum Type
		{
			BOOL = 0, 
			INT = 1,
			FLOAT = 2,
			STRING = 3,
			NONE = 4
		}type;


	public:

		/**
		 * @brief Devuelve el valor como booleano
		 * 
		 */
		bool as_bool() const {
			switch (type) {
			case BOOL: return data.b_value;
			case INT: return data.n_value != 0;
			case FLOAT: return data.f_value != 0.f;
			case STRING: return *data.s_value == "true" ? true : false;
			case NONE: return false;
			}

			return false;
		}

		/**
		 * @brief Devuelve el valor como entero
		 * 
		 */
		int as_int() const {
			switch (type) {
			case BOOL: return data.b_value ? 1 : 0;
			case INT: return data.n_value != 0;
			case FLOAT: return int(data.f_value);
			case STRING: return std::stoi(*data.s_value);
			case NONE: return 0;
			}
			return 0;
		}

		/**
		 * @brief Devuelve el valor como float
		 * 
		 */
		float as_float() const {
			switch (type) {
			case BOOL: return data.b_value ? 1.f : 0.f;
			case INT: return float(data.n_value);
			case FLOAT: return data.f_value;
			case STRING: return std::stof(*data.s_value);
			case NONE: return 0.f;
			}
			return 0.f;
		}

		/**
		 * @brief Devuelve el valor como string
		 * 
		 */
		std::string as_string() const {
			switch (type) {
			case BOOL: return data.b_value == true ? "true" : "false";
			case INT: return std::to_string(data.n_value);
			case FLOAT: return std::to_string(data.f_value);
			case STRING: return *data.s_value;
			case NONE: return std::string();
			}
			return std::string();
		}

		

	};
}