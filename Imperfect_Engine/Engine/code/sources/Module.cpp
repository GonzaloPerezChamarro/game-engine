/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Module.hpp"

namespace imeng
{
	void Module::register_module(const string& name, Factory* factory)
	{
		if (factory == nullptr)
		{
			std::cout << "Register Module %s error. Factory is null" << name.c_str() << std::endl;
			return;
		}

		factories[name] = factory;
	}

	Module::Factories_Map & Module::get_factories_map() { return factories; }

	Module::Factory* Module::get_factory(std::string & s)
	{
		return factories[s];
	}
}