#pragma once

#include "Component.hpp"
#include "Model_Obj.hpp"
#include <Material.hpp>

namespace imeng
{
	class Mesh_Component :public Component
	{
	private:
		typedef glt::Model_Obj Model_Obj;
		typedef std::shared_ptr<glt::Model> Shared_Model;

		Shared_Model model;
		std::string relative_path = "..//..//resources//";

	public:
		Mesh_Component(Entity*);
		Mesh_Component(Entity*, std::string &);

		bool initialize() override;
		bool parse_property(xmlNode * component_data) override;
		void run(float deltaTime) override;
		void finalize() override;
		

		Shared_Model get_model() { return model; }
	};
}
