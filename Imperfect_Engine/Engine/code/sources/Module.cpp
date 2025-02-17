/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gr�ficos y Plugins

*********************************
*/

#include "Module.hpp"


namespace imeng
{
	Module::Factories_Map Module::factories;

	Module::Module(Scene * owner): scene(owner)
	{

	}

	void Module ::register_module(const string& name, Factory* factory)
	{
		if (factory == nullptr) std::cout << "es nulo" << std::endl;
		factories[name] = factory;
	}

	Module::Factories_Map & Module::get_factories_map() { return factories; }

	Module::Factory* Module::get_factory(std::string & s)
	{
		return factories[s];
	}
}