/**
 * @file Render_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Modulo de componentes Render
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Task.hpp"
#include "Module.hpp"
#include "Render_Component.hpp"

#include <Render_Node.hpp>
#include <Node.hpp>
#include <Light.hpp>
#include <Model_Obj.hpp>
#include <list>



namespace imeng
{
	class Entity;
	class Render_Module :public Module
	{
	public:
		typedef glt::Render_Node Render_Node;
		typedef std::shared_ptr<Render_Node> shared_render_node;
		typedef std::shared_ptr<glt::Node> shared_node;

	public:
		class Render_Module_Factory : public Factory
		{
		public:
			/**
			 * @brief Construct a new Render_Module_Factory object
			 * 
			 */
			Render_Module_Factory();

			/**
			 * @brief Crea un modulo
			 * 
			 * @return std::shared_ptr<Module> 
			 */
			std::shared_ptr<Module> create_module(Scene*) override;
		};
	public:

		class Render_Task :public Task
		{
		private:
		/**
		* @brief Puntero al modulo
		*/
			Render_Module * module;
			
			/**
			* @brief Nodo de renderizado de OpenGL
			*/
			shared_render_node render_node;
			
		public:

			/**
			 * @brief Constructor
			 * 
			 */
			Render_Task(Render_Module *,Scene* , Render_Node *, bool = false);
			
			void run(float) override;
			bool initialize() override;
			bool finalize() override;

			/**
			 * @brief Añade un nodo al nodo de renderizado
			 * 
			 * @param s Nombre del nodo
			 * @param comp Nodo
			 */
			void add_item_to_render(string& s, std::shared_ptr<glt::Node> comp)
			{
				render_node->add(s, comp);
			}

			/**
			 * @brief Devuelve el nodo de renderizado
			 * 
			 * @return shared_render_node 
			 */
			shared_render_node get_render_node() { return render_node; }
		};

		/**
		* @brief factoria del modulo
		*/
		static Render_Module_Factory render_factory;
			
	private:
		/**
		* @brief Tarea del modulo
		*/
		Render_Task render_task;
		
		/**
		* @brief Lista de componentes creados de este modulo
		*/
		std::list<std::shared_ptr<Render_Component>> render_components;
		

	public:
		/**
		 * @brief Constructor
		 * 
		 * @param scene Escena del modulo
		 */
		Render_Module(Scene * scene): Module(scene), render_task(this, scene, new Render_Node){}

		/**
		 * @brief Crea un componente
		 * 
		 * @param entity Entidad del componente
		 * @param data Nodo de datos
		 * @return std::shared_ptr<Component> Componente creado
		 */
		std::shared_ptr<Component> create_component(Entity & entity, xml_node * data) override;

		/**
		 * @brief Get the task object
		 * 
		 * @return Task* 
		 */
		Task * get_task() override { return &render_task; }

		/**
		 * @brief Devuelve todos los componentes creados
		 * 
		 * @return std::list<std::shared_ptr<Render_Component>> 
		 */
		std::list<std::shared_ptr<Render_Component>> get_components() { return render_components; }
	};
}
