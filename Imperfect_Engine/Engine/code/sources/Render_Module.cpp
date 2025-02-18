/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Entity.hpp"
#include "Render_Module.hpp"
#include "Transform_Module.hpp"
#include "Scene.hpp"

using namespace rapidxml;

namespace imeng
{
	Render_Module::Render_Module_Factory render_factory;

	Render_Module::Render_Module_Factory::Render_Module_Factory()
	{
		Module::register_module((string)"render", this);
	}

	std::shared_ptr<Module> Render_Module::Render_Module_Factory::create_module(Scene * scene)
	{
		return std::shared_ptr<Render_Module>(new Render_Module(scene));
	}

	//-------------------------------------------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------------------------------------------
	Render_Module::Render_Task::Render_Task(Render_Module* module,Scene* scene, Render_Node* render_node, bool finished)
		: Task(scene, 5, finished), module(module), render_node(render_node)
	{
		//do nothing
	}

	void Render_Module::Render_Task::run(float deltaTime)
	{
		for (auto & c : module->get_components())
		{
			c->run(deltaTime);
		}
		
		scene->get_window()->clear();
		render_node->render();
		scene->get_window()->swapBuffers();

	}

	bool Render_Module::Render_Task::initialize()
	{
		for (auto & c : module->get_components())
		{
			c->initialize();
		}
		return true;
	}

	bool Render_Module::Render_Task::finalize()
	{
		for (auto & c : module->get_components())
		{
			c->finalize();
		}
		return true;
	}

	std::shared_ptr<Component> Render_Module::create_component(Entity& entity, xml_node* component_data)
	{
		string tag, attrib;
		std::shared_ptr<Component> comp_to_return = nullptr;

		for (xml_node * data = component_data->first_node();
			data;
			data = data->next_sibling())
		{
			if (data->type() == node_element)
			{
				tag = data->name();

				if (tag.empty()) return nullptr;

				for (xml_attribute * attrib_data = data->first_attribute();
					attrib_data;
					attrib_data = attrib_data->next_attribute())
				{
					attrib = attrib_data->value();
					
					if (attrib.empty()) return nullptr;
				}

				if (tag == "model")
				{
					std::cout << "Creando comp mesh" << std::endl;
					std::shared_ptr<Mesh_Component> mesh(new Mesh_Component(&entity));
					comp_to_return = mesh;
					render_components.push_back(mesh);

					if (!mesh->parse_property(data)) return nullptr;
					
					//task.add_item_to_render(attrib, mesh->get_mesh());
					render_task.get_render_node()->add(attrib, mesh->get_mesh());

					entity.add_component("mesh", mesh);
					
				}
				else if (tag == "camera")
				{
					std::cout << "Creando comp camera" << std::endl;
					std::shared_ptr<Camera_Component> camera(new Camera_Component(&entity));
					comp_to_return = camera;
					render_components.push_back(camera);

					//if (!camera->parse_property(data)) return nullptr;

					render_task.add_item_to_render(attrib, camera->get_camera());
					render_task.get_render_node()->set_active_camera("camera");

					entity.add_component("camera", camera);
				}
				else if (tag == "light")
				{
					std::cout << "Creando comp light" << std::endl;
					std::shared_ptr<Light_Component> light(new Light_Component(&entity));
					comp_to_return = light;
					render_components.push_back(light);

					//if (!light->parse_property(data)) return nullptr;

					render_task.add_item_to_render(attrib, light->get_light());
					
					entity.add_component("light", light);
				}
			}
		}

		return comp_to_return;
	}
}
