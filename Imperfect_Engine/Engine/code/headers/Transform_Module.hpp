/**
 * @file Transform_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Componente Transform. Modulo de creacion. Factoria de modulo
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
			/**
			 * @brief Constructor de la factoria
			 * 
			 */
			Transform_Module_Factory();

			/**
			 * @brief Crea un modulo transform
			 * 
			 * @return std::shared_ptr<Module> Modulo creado
			 */
			std::shared_ptr<Module> create_module(Scene*) override;
		};
	public:
		class Transform_Component : public Component
		{
		private:

			/**
			* @brief Vector de posicion
			*/
			glm::vec3 position;
			/**
			* @brief Vector de rotacion
			*/
			glm::vec3 rotation;

			/**
			* @brief Vector de escala
			*/
			glm::vec3 scale;

		private:

			/**
			* @brief Matriz de transformacion local
			*/
			glm::mat4 local_transform;

			/**
			* @brief Matriz de transformacion global
			*/
			glm::mat4 transform;

			/**
			* @brief Indica si se ha actualizado respecto al grafo
			*/
			bool updated;

		public:
			/**
			 * @brief Constructor
			 * 
			 */
			Transform_Component(Entity*);

			/**
			 * @brief Constructor por defecto eliminado
			 * 
			 */
			Transform_Component() = delete;

			bool initialize() override;
			bool parse_property(xmlNode * data) override;
			void finalize() override;
			void run(float deltaTime) override;

		public:
			/**
			 * @brief Devuelve la posicion
			 * 
			 * @return glm::vec3 
			 */
			glm::vec3 get_position() { return position; }

			/**
			 * @brief Devuelve la rotacion
			 * 
			 * @return glm::vec3 
			 */
			glm::vec3 get_rotation() { return rotation; }

			/**
			 * @brief Devuelve la escala
			 * 
			 * @return glm::vec3 
			 */
			glm::vec3 get_scale() { return scale; }

			/**
			 * @brief Set the position object
			 * 
			 * @param pos 
			 */
			void set_position(glm::vec3 pos);

			/**
			 * @brief Set the rotation object
			 * 
			 * @param rot 
			 */
			void set_rotation(glm::vec3 rot);

			/**
			 * @brief Set the scale object
			 * 
			 * @param scl 
			 */
			void set_scale(glm::vec3 scl);

			/**
			 * @brief Desplaza la entidad
			 * 
			 * @param movement Vector de desplazamiento
			 */
			void move(glm::vec3 movement);

			/**
			 * @brief Devuelve la matriz transformacion
			 * 
			 * @return glm::mat4& 
			 */
			glm::mat4 & get_matrix();

			/**
			 * @brief Set the matrix transform object
			 * 
			 * @param tr Nueva matriz
			 */
			void set_matrix_transform(glm::mat4 & tr) { transform = tr; }
		};

		class Transform_Task : public Task
		{
		private:

			/**
			* @brief Puntero al modulo
			*/
			Transform_Module * module;

		public:
			/**
			 * @brief Constructor
			 * 
			 */
			Transform_Task(Transform_Module*, Scene&, bool = false);

			bool initialize() override;
			void run(float deltaTime) override;                              
			bool finalize() override;


		};
		/**
		 * @brief Factoria de modulo transform
		 * 
		 */
		static Transform_Module_Factory transform_factory;

	private:

		/**
		* @brief Puntero a la tarea
		*/
		Transform_Task task;

		/**
		* @brief Lista de componentes creados del modulo
		*/
		std::list<std::shared_ptr<Transform_Component>> transform_components;
	public:
		/**
		 * @brief Constructor del modulo
		 * 
		 * @param scene Escena del modulo
		 */
		Transform_Module(Scene * scene) :Module(scene), task(this, *scene) {}

		/**
		 * @brief Get the task object
		 * 
		 * @return Task* 
		 */
		Task * get_task() override { return &task; }

		/**
		 * @brief Crea un nuevo componente transform
		 * 
		 * @param entity Entidad del componente
		 * @param data Nodo de datos
		 * @return std::shared_ptr<Component> Componente creado
		 */
		std::shared_ptr<Component> create_component(Entity & entity, rapidxml::xml_node<> * data) override;

	};

}

