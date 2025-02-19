/**
 * @file Script_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Module class for creating Scripts
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


#include "Task.h"
#include "Module.h"
#include "Component.h"

namespace imeng
{
	class Behaviour;

	class Script_Module : public Module
	{
	public:
		class Script_Module_Factory : public Factory
		{
		public:
			Script_Module_Factory();
			std::shared_ptr<Module> create_module(Scene*) override;
		};

	public:
		class Script_Component :public Component
		{
		private:
			/* Pointer to the script */
			Behaviour* script;

		public:
			/**
			 * @brief Constructor
			 * 
			 * @param entity Owner entity
			 * @param id Id of the script
			 */
			Script_Component(Entity* entity, string & id);

			/* Default constructor removed */
			Script_Component() = delete;

			/* Overriden methods */
			bool initialize() override;
			bool parse_property(xmlNode * data) override;
			void finalize() override;
			void run(float deltaTime) override;
		};

		class Script_Task : public Task
		{
		private:
			/* Pointer to the module */
			Script_Module* module;

		public:
			/* Constructor */
			Script_Task(Script_Module*, Scene*, bool = false);

			/* Overriden methods */
			bool initialize() override;
			void run(float deltaTime) override;
			bool finalize() override;
		};

		/* Factory of script modules */
		static Script_Module_Factory script_factory;

	private:
		/* Task*/
		Script_Task task;

		/* List of components of the script module */
		std::list<std::shared_ptr<Script_Component>> script_components;

	public:
		/**
		 * @brief Construct a new Script_Module object
		 * @param scene main scene
		 */
		Script_Module(Scene* scene) : Module(scene), task(this, scene) {}
		/**
		 * @brief Create a component object
		 * @param entity Owner
		 * @param data Data node
		 * @return std::shared_ptr<Component> Component created
		 */
		std::shared_ptr<Component> create_component(Entity & entity, rapidxml::xml_node<> * data) override;

		/* Returns the task object */
		Task* get_task() override { return &task; }
	};
}