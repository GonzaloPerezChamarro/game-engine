/**
 * @file Character_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase de modulo de creacion de componentes Character
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include "Module.hpp"
#include "Task.hpp"
#include "Character_Component.hpp"

namespace imeng
{

	class Character_Module :public Module
	{
	public:
		class Character_Module_Factory :public Factory
		{
		public:
		/**
		 * @brief Construct a new Character_Module_Factory object
		 * 
		 */
			Character_Module_Factory();

			/**
			 * @brief Create a module object
			 * 
			 * @return std::shared_ptr<Module> Modulo creado
			 */
			std::shared_ptr<Module> create_module(Scene*) override;
		};

	public:

		class Character_Task :public Task
		{
		private:

			/**
			* @brief puntero al modulo 
			*/
			Character_Module * module;

		public:
		/**
		 * @brief Construct a new Character_Task object
		 * 
		 */
			Character_Task(Character_Module*, Scene*, bool = false);

			bool initialize() override;
			void run(float deltaTime) override;
			bool finalize() override;
		};

		/**
		 * @brief Factoria de modulos character
		 * 
		 */
		static Character_Module_Factory character_factory;

	private:
		/**
		* @brief Tarea
		*/
		Character_Task task;

		/**
		* @brief lista de componentes del modulo
		*/
		std::list<std::shared_ptr<Character_Component>> character_components;

	public:
		/**
		 * @brief Construct a new Character_Module object
		 * 
		 * @param scene Escena principal
		 */
		Character_Module(Scene* scene): Module(scene), task(this, scene){}

		/**
		 * @brief Get the task object
		 * 
		 * @return Task* Tarea del modulo
		 */
		Task * get_task() override { return &task; }

		/**
		 * @brief Create a component object
		 * 
		 * @param entity Entidad a la que se añade
		 * @param data Nodo de datos
		 * @return std::shared_ptr<Component> Componente creado
		 */
		std::shared_ptr<Component> create_component(Entity & entity, rapidxml::xml_node<> * data) override;
	};
}
