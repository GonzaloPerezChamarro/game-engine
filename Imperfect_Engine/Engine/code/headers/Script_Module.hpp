/**
 * @file Script_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase de creacion de componentes Script
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include "Task.hpp"
#include "Module.hpp"
#include "Component.hpp"

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
			/**
			* @brief Puntero al script
			*/
			Behaviour* script;

		public:
			/**
			 * @brief Constructor
			 * 
			 * @param entity Entidad del componente
			 * @param id Identificador de script
			 */
			Script_Component(Entity* entity, string & id);
			/**
			 * @brief Constructor por defecto eliminado
			 * 
			 */
			Script_Component() = delete;

			bool initialize() override;
			bool parse_property(xmlNode * data) override;
			void finalize() override;
			void run(float deltaTime) override;
		};

		class Script_Task : public Task
		{
		private:
			/**
			* @brief Puntero al modulo
			*/
			Script_Module * module;

		public:
			/**
			 * @brief Constructor
			 * 
			 */
			Script_Task(Script_Module*, Scene&, bool = false);

			bool initialize() override;
			void run(float deltaTime) override;
			bool finalize() override;
		};

		/**
		 * @brief Factoria de modulo script
		 * 
		 */
		static Script_Module_Factory script_factory;

	private:
		/**
		* @brief Tarea del modulo
		*/
		Script_Task task;

		/**
		* @brief Lista de componentes creados del modulo
		*/
		std::list<std::shared_ptr<Script_Component>> script_components;

	public:
		/**
		 * @brief Constructor
		 * 
		 * @param scene Escena del modulo
		 */
		Script_Module(Scene* scene) : Module(scene), task(this, *scene) {}

		/**
		 * @brief Get the task object
		 * 
		 * @return Task* 
		 */
		Task* get_task() override { return &task; }

		/**
		 * @brief Crea un nuevo componente script
		 * 
		 * @param entity Entidad del componente
		 * @param data Nodo de datos
		 * @return std::shared_ptr<Component> Componente creado
		 */
		std::shared_ptr<Component> create_component(Entity & entity, rapidxml::xml_node<> * data) override;
	};
}