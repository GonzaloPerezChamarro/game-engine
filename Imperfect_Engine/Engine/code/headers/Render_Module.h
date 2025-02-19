/**
 * @file Render_Module.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Modulo de componentes Render
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Task.h"
#include "Module.h"
#include "Render_Component.h"

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
			/* Constructor*/
			Render_Module_Factory();

			/* Creates the render module */
			std::shared_ptr<Module> create_module(Scene*) override;
		};
	public:

		class Render_Task :public Task
		{
		private:
			/* Pointer to the render module */
			Render_Module * module;
			
			/**
			* @brief Nodo de renderizado de OpenGL
			*/
			/* Node of OpenGl render */
			shared_render_node render_node;
			
		public:

			/* Constructor */
			Render_Task(Render_Module *,Scene* , Render_Node *, bool = false);
			
			/* Overriden methods */
			void run(float) override;
			bool initialize() override;
			bool finalize() override;

			/**
			 * @brief Añade un nodo al nodo de renderizado
			 * @brief Adds a node to the render node
			 * @param s Node name
			 * @param comp Node
			 */
			void add_item_to_render(string& s, std::shared_ptr<glt::Node> comp)
			{
				render_node->add(s, comp);
			}

			/* returns the render node */
			shared_render_node get_render_node() const { return render_node; }
		};

		/* Factory of render modules */
		static Render_Module_Factory render_factory;
			
	private:
		/* Task */
		Render_Task render_task;
		
		/* List of components of the module */
		std::list<std::shared_ptr<Render_Component>> render_components;
		

	public:
		/**
		 * @brief Construct a new Render_Module object
		 * @param scene main scene
		 */
		Render_Module(Scene * scene): Module(scene), render_task(this, scene, new Render_Node){}

		/**
		 * @brief Create a component object
		 *
		 * @param entity Owner
		 * @param data Data node
		 * @return std::shared_ptr<Component> Component created
		 */
		std::shared_ptr<Component> create_component(Entity & entity, xml_node * data) override;

		/* Returns the task object */
		Task * get_task() override { return &render_task; }

		/* Return all created components */
		std::list<std::shared_ptr<Render_Component>> get_components() { return render_components; }
	};
}
