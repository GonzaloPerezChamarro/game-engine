/**
 * @file Entity.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase que representa una entidad en el juego
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Transform_Module.hpp"
#include "rapidxml.hpp"

using std::map;
using std::string;

namespace imeng {

	class Scene;
	class Component;


	class Entity {

		/**
		* @brief Mapa de componentes de la entidad
		*/
		map<string, std::shared_ptr<Component>> components;
	private:
		typedef std::shared_ptr<Transform_Module::Transform_Component> Shared_Transform;

		/**
		* @brief Puntero al transform de la entidad
		*/
		Shared_Transform transform;

	private:
		/**
		* @brief Puntero a la escena en la que se encuentra la entidad
		*/
		Scene * scene_parent;

		/**
		* @brief Puntero al padre. Nullptr en caso nulo
		*/
		Entity * parent;

		/**
		 * @brief Comprueba si la entidad tiene el componente
		 * 
		 * @param name Nombre del componente
		 * @return true Afirmativo
		 * @return false Negativo
		 */
		bool have_component(const string & name);

	public:

		/**
		 * @brief Construct a new Entity object
		 * 
		 * @param scene Escena principal
		 */
		Entity(Scene* scene);

		bool initialize();

		/**
		 * @brief Añade un componente a la entidad
		 * 
		 * @return true 
		 * @return false 
		 */
		bool add_component(const string&, std::shared_ptr<Component>);

		/**
		 * @brief Get the component object
		 * 
		 * @param name Nombre del componente
		 * @return std::shared_ptr<Component> 
		 */
		std::shared_ptr<Component> get_component(const string & name);

		/**
		 * @brief Get the transform object
		 * 
		 * @return Shared_Transform 
		 */
		Shared_Transform get_transform() { return transform; }

		/**
		 * @brief Set the transform object
		 * 
		 * @param tr 
		 */
		void set_transform(Shared_Transform tr) { transform = tr; }

		/**
		 * @brief Get the parent entity
		 * 
		 * @return Entity* 
		 */
		Entity * get_parent()const { return parent; }

		/**
		 * @brief Set the parent entity
		 * 
		 * @param parent 
		 */
		void set_parent(Entity & parent) { parent = parent; }

		/**
		 * @brief Get the scene
		 * 
		 * @return Scene* 
		 */
		Scene * get_scene() const { return scene_parent; }

		/**
		 * @brief Activa o desactiva la entidad
		 * 
		 * @param visibility Visibilidad
		 */
		void enabled(bool visibility);
	};

}

