
/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/


#include "Render_Component.h"
#include "Entity.h"
#include "Kernel.h"

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

	bool Mesh_Component::parse_property(xmlNode * data)
	{
		std::string relative_path = RESOURCES_PATH;
		std::string asset_file = data->value();

		if (asset_file.empty()) return false;

		relative_path += asset_file;
		model_node.reset(new glt::Model_Obj(relative_path));

		return true;
	}

	void Mesh_Component::run(float deltaTime) 
	{
		auto transform = entity->get_transform()->get_matrix();
		model_node->set_transformation(transform);
	}

	//-------------------------------------------------------------------------

	void Camera_Component::run(float deltaTime)
	{
		auto transform = entity->get_transform()->get_matrix();
		camera_node->set_transformation(transform);
	}

	//-------------------------------------------------------------------------

	void Light_Component::run(float deltaTime)
	{
		auto transform = entity->get_transform()->get_matrix();
		light_node->set_transformation(transform);
	}
}
