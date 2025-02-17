/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gr�ficos y Plugins

*********************************
*/
#include "Transform_Module.hpp"
#include "Scene.hpp"
#include "Task.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

using namespace rapidxml;

namespace imeng
{
	Transform_Module::Transform_Component::Transform_Component(Entity* entity)
		:Component(entity), local_transform(glm::mat4(1.f)), transform(glm::mat4(1.f)),
		position(glm::vec3()), rotation(glm::vec3()), scale(glm::vec3()),
		updated(false)
	{
		
	}

	Transform_Module::Transform_Module_Factory transform_factory;

	Transform_Module::Transform_Module_Factory::Transform_Module_Factory()
	{
		Module::register_module((string)"transform", this);
	}

	std::shared_ptr<Module> Transform_Module::Transform_Module_Factory::create_module(Scene* scene)
	{
		return std::shared_ptr<Transform_Module>(new Transform_Module(scene));
	}
	//----------------------------------------------------------------------------------------------

	/**
	 * @brief Actualiza el transform local segun la posicion, rotacion y escala
	 * 
	 * @return true 
	 * @return false 
	 */
	bool Transform_Module::Transform_Component::initialize()
	{
		local_transform = glm::translate(glm::mat4(), position);
		local_transform = glm::scale(local_transform, scale);
		local_transform = glm::rotate(local_transform, rotation.x, glm::vec3(1.f, 0.f, 0.f));
		local_transform = glm::rotate(local_transform, rotation.y, glm::vec3(0.f, 1.f, 0.f));
		local_transform = glm::rotate(local_transform, rotation.z, glm::vec3(0.f, 0.f, 1.f));


		return true;
	}

	/**
	 * @brief Toma los valores de los atributos del xml
	 * 
	 * @param data nodo de xml
	 * @return true 
	 * @return false 
	 */
	bool Transform_Module::Transform_Component::parse_property(xmlNode * data)
	{
		string type;

		for (xmlNode * data_node = data->first_node();
			data_node;
			data_node = data_node->next_sibling())
		{
			type = data_node->value();


			string name = data_node->name();
			if (name == "position")
			{
				size_t num_comas = std::count(type.begin(), type.end(), ',');
				size_t coma_pos = 0;
				string data_string;

				std::vector<float> nums;
				for (size_t i = 0; i <= num_comas; ++i)
				{
					coma_pos = type.find(',');
					data_string = type.substr(0, coma_pos);

					nums.push_back(std::stof(data_string));
					type.erase(0, coma_pos + 1);
				}
				position.x = nums[0];
				position.y = nums[1];
				position.z = nums[2];
				set_position(position);

			}
			else if (name == "rotation")
			{
				size_t num_comas = std::count(type.begin(), type.end(), ',');
				size_t coma_pos = 0;
				string data_string;

				std::vector<float> nums;
				for (size_t i = 0; i <= num_comas; ++i)
				{
					coma_pos = type.find(',');
					data_string = type.substr(0, coma_pos);

					nums.push_back(std::stof(data_string));
					type.erase(0, coma_pos + 1);
				}
				rotation.x = nums[0];
				rotation.y = nums[1];
				rotation.z = nums[2];
				//set_rotation(rotation);
			}
			else if (name == "scale")
			{
				size_t num_comas = std::count(type.begin(), type.end(), ',');
				size_t coma_pos = 0;
				string data_string;

				std::vector<float> nums;
				for (size_t i = 0; i <= num_comas; ++i)
				{
					coma_pos = type.find(',');
					data_string = type.substr(0, coma_pos);

					nums.push_back(std::stof(data_string));
					type.erase(0, coma_pos + 1);
				}
				scale.x = nums[0];
				scale.y = nums[1];
				scale.z = nums[2];
				//set_scale(scale);
			}
		}

		return true;
	}

	void Transform_Module::Transform_Component::finalize()
	{

	}

	void Transform_Module::Transform_Component::run(float deltaTime)
	{
		updated = false;
	}

	void Transform_Module::Transform_Component::move(glm::vec3 movement)
	{
		position += movement;
		local_transform = glm::translate(glm::mat4(), position);
	}

	void Transform_Module::Transform_Component::set_position(glm::vec3 pos)
	{
		position = pos;
		local_transform = glm::translate(glm::mat4(), position);
	}

	void Transform_Module::Transform_Component::set_rotation(glm::vec3 rot)
	{
		rotation = rot;

		local_transform = glm::rotate(local_transform, rotation.x, glm::vec3(1.f, 0.f, 0.f));
		local_transform = glm::rotate(local_transform, rotation.y, glm::vec3(0.f, 1.f, 0.f));
		local_transform = glm::rotate(local_transform, rotation.z, glm::vec3(0.f, 0.f, 1.f));
	}

	void Transform_Module::Transform_Component::set_scale(glm::vec3 scl)
	{
		scale = scl;
		local_transform = glm::scale(local_transform, scale);
	}

	glm::mat4 & Transform_Module::Transform_Component::get_matrix()
	{
		if (updated) return transform;

		Entity * parent_entity = entity->get_parent();
		if (parent_entity != nullptr)
		{
			transform = parent_entity->get_transform()->get_matrix() * local_transform;

		}
		else
		{
			transform = local_transform;
		}
		updated = true;
		return transform;
	}

	//-----------------------------------------------------------------------------
	Transform_Module::Transform_Task::Transform_Task(Transform_Module* module, Scene* scene, bool finished)
		:Task(scene, 2, finished), module(module)
	{
		//do nothing
	}

	/**
	 * @brief Inicializa todos los componentes transform
	 * 
	 * @return true 
	 * @return false 
	 */
	bool Transform_Module::Transform_Task::initialize()
	{
		for (auto tr : module->transform_components)
		{
			if (!tr->initialize())
				return false;
		}

		return true;
	}

	/**
	 * @brief Actualiza todos los componentes transform
	 * 
	 * @param deltaTime 
	 */
	void Transform_Module::Transform_Task::run(float deltaTime)
	{
		for (auto tr : module->transform_components)
		{
			tr->run(deltaTime);
		}

	}

	/**
	 * @brief Finaliza todos los componentes transform
	 * 
	 * @return true 
	 * @return false 
	 */
	bool Transform_Module::Transform_Task::finalize()
	{
		for (auto tr : module->transform_components)
		{
			tr->finalize();
		}

		return true;
	}

	std::shared_ptr<Component> Transform_Module::create_component(Entity & entity, rapidxml::xml_node<> * data)
	{
		std::cout << "Creando comp transform" << std::endl;

		std::shared_ptr< Transform_Component> transform_component{ new Transform_Component(&entity) };
		transform_component->parse_property(data);
		entity.add_component("transform", transform_component);
		entity.set_transform(transform_component);
		transform_components.push_back(transform_component);

		return transform_component;
	}
}