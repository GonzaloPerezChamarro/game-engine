/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gr�ficos y Plugins

*********************************
*/

#include "Script_Module.hpp"
#include "Scene.hpp"
//#include "Behaviour.hpp"
#include "script_registry.hpp"

namespace imeng
{

	Script_Module::Script_Component::Script_Component(Entity* entity, string & id)
		:Component(entity)
	{
		script = scripts[id];
	}

	Script_Module::Script_Module_Factory script_factory;

	Script_Module::Script_Module_Factory::Script_Module_Factory()
	{
		Module::register_module((string)"script", this);
	}

	std::shared_ptr<Module> Script_Module::Script_Module_Factory::create_module(Scene* scene)
	{
		return std::shared_ptr<Script_Module>(new Script_Module(scene));
	}

	//----------------------------------------------------------------------------------------------

	/**
	 * @brief Llama al metodo start() del script
	 * 
	 * @return true 
	 * @return false 
	 */
	bool Script_Module::Script_Component::initialize()
	{
		script->start(entity);
		return true;
	}

	bool Script_Module::Script_Component::parse_property(xmlNode * data)
	{
		

		return true;
	}

	void Script_Module::Script_Component::finalize()
	{
		
	}

	/**
	 * @brief Llama al metodo run del script
	 * 
	 * @param deltaTime 
	 */
	void Script_Module::Script_Component::run(float deltaTime)
	{
		script->update(entity,deltaTime);
	}

	//----------------------------------------------------------------------------------------------

	Script_Module::Script_Task::Script_Task(Script_Module* module, Scene* scene, bool finished)
		:Task(scene,1, finished), module(module)
	{
		//do nothing
	}

	/**
	 * @brief Inicializa todos los componentes script
	 * 
	 * @return true 
	 * @return false 
	 */
	bool Script_Module::Script_Task::initialize()
	{
		for (auto s : module->script_components)
		{
			if (!s->initialize())
				return false;
		}

		return true;
	}

	/**
	 * @brief Actualiza todos los componentes script
	 * 
	 * @param deltaTime 
	 */
	void Script_Module::Script_Task::run(float deltaTime)
	{
		for (auto s : module->script_components)
		{
			s->run(deltaTime);
		}
	}

	bool Script_Module::Script_Task::finalize()
	{
		for (auto s : module->script_components)
		{
			s->finalize();
		}

		return true;
	}

	std::shared_ptr<Component> Script_Module::create_component(Entity & entity, rapidxml::xml_node<> * data)
	{
		std::cout << "      comp script" << std::endl;
		
		std::string id = data->first_node()->name();
		std::cout << "      script: " << id << std::endl;

		std::shared_ptr<Script_Component> script_comp{ new Script_Component(&entity,id) };
		entity.add_component(id, script_comp);
		script_components.push_back(script_comp);

		return script_comp;
	}

	
}