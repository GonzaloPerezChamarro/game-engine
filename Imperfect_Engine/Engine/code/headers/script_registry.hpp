/**
 * @file script_registry.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Comtiene un mapa de scripts y el registro de scripts en este
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#ifndef GLOBAL_VAR_IMENG
#define GLOBAL_VAR_IMENG

#include "Behaviour.hpp"
#include <map>
#include <string>

namespace imeng
{
	/**
	* @brief Mapa de scripts registrados
	*/
	extern map<string, Behaviour*> scripts;

	/**
	 * @brief Registra un script
	 * 
	 * @param id Identificador del script
	 * @param script Puntero al script
	 */
	inline void register_script(std::string & id, Behaviour *script)
	{
		//scripts.emplace(std::make_pair(id, script));
		scripts.insert(std::make_pair(id, script));
	}
}

#endif // !GLOBAL_VAR_IMENG

