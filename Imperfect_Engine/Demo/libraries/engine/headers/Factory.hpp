#pragma once

#include "Module.hpp"
#include "Scene.hpp"

#include <string>
#include <map>

using std::string;

//namespace imeng
//{
//	class Module_Factory
//	{
//	private:
//		typedef std::shared_ptr<Module> shared_module;
//		typedef shared_module(*module_factory_ptr) (Scene *);
//
//		std::map<string, module_factory_ptr> module_registry;
//
//	public:
//		static Module_Factory * instance()
//		{
//			static Module_Factory factory;
//			return &factory;
//		}
//
//		void add(const string & name, module_factory_ptr factory_ptr);
//
//		shared_module create(const string & name, Scene * scene)
//		{
//			return module_registry.count(name) ?
//				module_registry[name](scene) :
//				shared_module();
//		}
//		
//	protected:
//		Module_Factory();
//			   		 
//	};
//
//}
