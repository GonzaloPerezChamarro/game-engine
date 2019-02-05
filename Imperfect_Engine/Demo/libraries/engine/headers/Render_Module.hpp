#pragma once

#include "Task.hpp"
#include "Module.hpp"
#include <Render_Node.hpp>
#include "Mesh_Component.hpp"
#include <list>

namespace imeng
{
	class Entity;
	class Render_Module :public Module
	{
		class Render_Module_Factory : public Factory
		{
			Render_Module_Factory();
			std::shared_ptr<Module> create_module() override;
		};

		class Render_Component :public Component
		{
			//Mesh_Component * mesh;
				/*Mesh * mesh;
				Material * mat;*/
			std::list<std::shared_ptr<Mesh_Component>> render_items;

		public:
			Render_Component(Entity * parent) :Component(parent) {}

			bool initialize() override;
			bool parse_property(xmlNode * data) override;
			void finalize() override;
			void run(float deltaTime) override;

			void add_item(std::shared_ptr<Mesh_Component>);
		};

		class Render_Task :public Task
		{
			typedef glt::Render_Node Render_Node;
			typedef std::shared_ptr<Render_Node> shared_render_node;

		private:
			shared_render_node render_node;
			std::list<std::shared_ptr<Component>> render_components;

		public:

			Render_Task(Scene&, Render_Node*, int = 0, bool = false);
			shared_render_node get_render_node() { return render_node; }

			void run(float) override;
			bool initialize() override;
			bool finalize() override;

			void add_component(const std::shared_ptr<Component> render) { render_components.push_back(render); }
		};
			

	public:
		Render_Module();

		std::shared_ptr<Component> create_component(Entity & entity, xml_node * data) override;
		Task * get_task() const override { return task; }
	private:
		Render_Task * task;

		

	};
}
