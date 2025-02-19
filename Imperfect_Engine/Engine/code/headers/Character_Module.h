/**
 * @file Character_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Module class for creating Characters
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


#include "Module.h"
#include "Task.h"
#include "Character_Component.h"

namespace imeng
{
	class Character_Module : public Module
	{
	public:
		class Character_Module_Factory :public Factory
		{
		public:
			/* Constructor */
			Character_Module_Factory();

			/* Creates the character module */
			std::shared_ptr<Module> create_module(Scene*) override;
		};

	public:

		class Character_Task :public Task
		{
		private:

			/* Pointer to the character module */
			Character_Module* module;

		public:
			/* Constructor */
			Character_Task(Character_Module*, Scene*, bool = false);

			/* Overriden methods */
			bool initialize() override;
			void run(float deltaTime) override;
			bool finalize() override;
		};

		/* Factory of character modules */
		static Character_Module_Factory character_factory;

	private:
		/* Character task */
		Character_Task task;

		/* List of components of the character module */
		std::list<std::shared_ptr<Character_Component>> character_components;

	public:
		/**
		 * @brief Construct a new Character_Module object
		 * @param scene main scene
		 */
		Character_Module(Scene* scene): Module(scene), task(this, scene){}

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
