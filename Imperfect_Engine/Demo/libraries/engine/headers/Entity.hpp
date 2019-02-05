#pragma once



#include <map>
#include <string>


using std::map;
using std::string;

namespace imeng {

	class Scene;
	class Component;
	class Transform_Module;
	//class Transform_Module::Transform_Component;
	class Entity {

		
		map<string, std::shared_ptr<Component>> components;
		map < string, std::shared_ptr<Entity>> children;
	private:
		//Transform_Module::Transform_Component * transform;

	private:
		Scene * scene_parent;
		bool have_component(const string & name);

	public:

		Entity(Scene*);
		bool initialize();
		bool add_component(const string&, std::shared_ptr<Component>);
		std::shared_ptr<Component> get_component(const string & name);

		//Transform_Module::Transform_Component & get_transform();
		//std::shared_ptr<Entity> get_child(string& name) { return children[name]; }
	};

}

