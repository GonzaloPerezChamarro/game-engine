/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Graficos y Plugins

*********************************
*/


#include "Render_Component.hpp"
#include "Entity.hpp"

namespace imeng
{

	bool Render_Component::initialize()
	{

		return true;
	}

	bool Render_Component::parse_property(xmlNode * data)
	{
		return true;
	}

	void Render_Component::finalize()
	{

	}

	void Render_Component::run(float deltaTime)
	{
		
	}

	//-------------------------------------------------------------------------

	/**
	 * @brief Crea un nuevo modelo a partir de una ruta
	 * 
	 * @param data Nodo de datos xml
	 * @return true 
	 * @return false 
	 */
	bool Mesh_Component::parse_property(xmlNode * data)
	{
		std::string relative_path = "resources//";
		std::string asset_file = data->value();

		if (asset_file.empty()) return false;

		relative_path += asset_file;
		model_node.reset(new glt::Model_Obj(relative_path));

		return true;
	}

	std::shared_ptr<glt::Model_Obj> Mesh_Component::get_mesh()
	{
		return model_node;
	}

	/**
	 * @brief Actualiza el transform
	 * 
	 * @param deltaTime 
	 */
	void Mesh_Component::run(float deltaTime) 
	{
		auto transform = entity->get_transform()->get_matrix();
		model_node->set_transformation(transform);
	}

	//-------------------------------------------------------------------------

	std::shared_ptr<glt::Camera> Camera_Component::get_camera()
	{
		return camera_node;
	}

	/**
	 * @brief Actualiza el transform
	 * 
	 * @param deltaTime 
	 */
	void Camera_Component::run(float deltaTime)
	{
		auto transform = entity->get_transform()->get_matrix();
		camera_node->set_transformation(transform);
	}

	//-------------------------------------------------------------------------

	std::shared_ptr<glt::Light> Light_Component::get_light()
	{
		return light_node;
	}

	/**
	 * @brief Actualiza el transform
	 * 
	 * @param deltaTime 
	 */
	void Light_Component::run(float deltaTime)
	{
		auto transform = entity->get_transform()->get_matrix();
		light_node->set_transformation(transform);
	}

}
