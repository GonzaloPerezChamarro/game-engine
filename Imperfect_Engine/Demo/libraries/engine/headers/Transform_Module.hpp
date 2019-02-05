#pragma once


#include "Module.hpp"
#include <Node.hpp>


namespace imeng {

	class Entity;
	class Scene;
	class Module;
	class Task;
	class Component;

	class Transform_Module :public Module
	{
		class Transform_Module_Factory :public Factory
		{
			std::shared_ptr<Module> create_module() override;
			Transform_Module_Factory();
		};
	public:
		class Transform_Component : public Component
		{
		private:
			typedef glt::Node Node;
			typedef std::shared_ptr<Node> Shared_Node;
			Shared_Node transform;

			glt::Vector3 position;
			glt::Vector3 rotation;
			float scale;

		public:
			Transform_Component(Entity*) :Component(parent) {}

			bool initialize() override;
			bool parse_property(xmlNode * data) override;
			void finalize() override;
			void run(float deltaTime) override;

		public:
			glt::Vector3 get_position() { return position; }
			glt::Vector3 get_rotation() { return rotation; }
			float get_scale() { return scale; }

			void set_transform(Shared_Node node) { transform = node; }

			void set_position(glt::Vector3 pos) { position = pos; }
			void set_rotation(glt::Vector3 rot) { rotation = rot; }
			void set_scale(float scl) { scale = scl; }
		};

		class Transform_Task : public Task
		{
		private:
			std::shared_ptr<Transform_Component> component;

		public:
			Transform_Task(Scene&, int, bool);
			bool initialize() override;
			void run(float deltaTime) override;                              // Le pide a la escena la raíz del grafo (root) y lo recorre
			bool finalize() override;

			void add_component(const std::shared_ptr<Transform_Module::Transform_Component> transform) { component = transform; }
		};

		static Transform_Module factory;
	private:
		Transform_Task * task;
		Transform_Component component;

	public:
		Transform_Module();
		Task * get_task() const override { return task; }

		std::shared_ptr<Component> create_component(Entity & entity, rapidxml::xml_node<> * data) override;

	};

}

