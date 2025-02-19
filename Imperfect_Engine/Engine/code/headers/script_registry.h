
/**
 * @file script_registry.hpp
 * @author Gonzalo Perez Chamarro
 * @brief It registers each script by id
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#ifndef GLOBAL_VAR_IMENG
#define GLOBAL_VAR_IMENG

#include "Behaviour.h"
#include <map>
#include <string>

namespace imeng
{
	/* Map of registered scripts by id */
	extern map<string, Behaviour*> scripts;

	/**
	 * @brief Registers a script
	 * 
	 * @param id Id of the script
	 * @param script Pointer to the script
	 */
	inline void register_script(std::string& id, Behaviour* script)
	{
		scripts.insert(std::make_pair(id, script));
	}
}

#endif // !GLOBAL_VAR_IMENG

