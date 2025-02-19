/**
 * @file Transform_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Module class for creating Transforms
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
#include <glm/glm.hpp>

namespace imeng {

	class Entity;
	class Scene;

	class Transform_Module :public Module
	{
	public:
		class Transform_Module_Factory :public Factory
		{
		public:
			/* Constructor */
			Transform_Module_Factory();

			/* Creates the transform module */
			std::shared_ptr<Module> create_module(Scene*) override;
		};
	public:
		class Transform_Component : public Component
		{
		private:
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;

		private:

			/* Local transform matrix */
			glm::mat4 local_transform;

			/* Global transform matrix */
			glm::mat4 transform;

			/* Flag that indicates if it is updated respect to the graph */
			bool updated;

		public:
			/* Constructor */
			Transform_Component(Entity*);

			/* Default constructor removed */
			Transform_Component() = delete;

			/* Overriden methods */
			bool initialize() override;
			bool parse_property(xmlNode * data) override;
			void finalize() override;
			void run(float deltaTime) override;

		public:
			/* Returns the position */
			glm::vec3 get_position() const { return position; }

			/* Returns the rotation */
			glm::vec3 get_rotation() const { return rotation; }

			/* Returns the scale */
			glm::vec3 get_scale() const { return scale; }

			/* Set a new position of the transform */
			void set_position(glm::vec3 pos);

			/* Set a new rotation of the transform */
			void set_rotation(glm::vec3 rot);

			/* Set a new scale of the transform */
			void set_scale(glm::vec3 scl);

			/**
			 * @brief Moves the transform position
			 * @param movement Vector de desplazamiento
			 */
			void move(glm::vec3 movement);

			/* Returns the transform matrix */
			glm::mat4 & get_matrix();

			/* Set a new transform matrix */
			void set_matrix_transform(glm::mat4 & tr) { transform = tr; }
		};

		class Transform_Task : public Task
		{
		private:

			/* Pointer to the module */
			Transform_Module * module;

		public:
			/* Constructor */
			Transform_Task(Transform_Module*, Scene*, bool = false);

			/* Overriden methods */
			bool initialize() override;
			void run(float deltaTime) override;                              
			bool finalize() override;
		};

		/* Factory of transform modules */
		static Transform_Module_Factory transform_factory;

	private:
		/* Task */
		Transform_Task task;

		/* List of components of the transform module */
		std::list<std::shared_ptr<Transform_Component>> transform_components;

	public:
		/**
		 * @brief Construct a new Transform_Module object
		 * @param scene main scene
		 */
		Transform_Module(Scene * scene) :Module(scene), task(this, scene) {}

		/**
		 * @brief Crea un nuevo componente transform
		 * 
		 * @param entity Entidad del componente
		 * @param data Nodo de datos
		 * @return std::shared_ptr<Component> Componente creado
		 */
		std::shared_ptr<Component> create_component(Entity & entity, rapidxml::xml_node<> * data) override;

		/* Returns the task object */
		Task* get_task() override { return &task; }
	};

}

