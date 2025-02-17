/**
 * @file Entity.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Class that represents an entity in a game
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Transform_Module.hpp"
#include "rapidxml.hpp"

using std::map;
using std::string;

namespace imeng 
{
	class Scene;
	class Component;

	class Entity 
	{
		typedef std::shared_ptr<Transform_Module::Transform_Component> Shared_Transform;

		/**
		* @brief Puntero al transform de la entidad
		*/
		Shared_Transform transform;

	public:
		/**
		 * @brief Construct a new Entity object
		 * @param scene Escena principal
		 */
		Entity(Scene* scene);

		/* Initialize the entity */
		bool initialize();

		/**
		 * @brief Add a component
		 * @return true if it was succesful
		 */
		bool add_component(const string&, std::shared_ptr<Component>);

		/**
		 * @brief Returns the component object 
		 * @param name Name of the component
		 */
		std::shared_ptr<Component> get_component(const string& name) const;

		/* Returns the transform */
		Shared_Transform get_transform() const { return transform; }

		/* Modifies the transoform*/
		void set_transform(Shared_Transform tr) { transform = tr; }
		 
		/* Returns the entity parent */
		Entity* get_parent() const { return parent; }

		/* Sets a parent */
		void set_parent(Entity& parent) { parent = parent; }

		/* Returns the parent scene */
		Scene* get_scene() const { return scene_parent; }

		/* It modifies the visibility of the entity */
		void enabled(bool visibility);

		/* Map of components by id */
		map<string, std::shared_ptr<Component>> components;

	private:
		/* Pointer to the scene where the entity is*/
		Scene* scene_parent;

		/* Pointer to parent */
		Entity* parent;

		/**
		 * @brief It checks if the entity has a component by its name
		 * @param name Name of the component
		 */
		bool have_component(const string & name) const;
	};

}

