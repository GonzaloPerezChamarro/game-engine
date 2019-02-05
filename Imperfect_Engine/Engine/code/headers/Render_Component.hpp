/**
 * @file Render_Component.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Componente de renderizado (Mesh, Camara o Light)
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Component.hpp"
#include <string>
#include <Model_Obj.hpp>
#include <Camera.hpp>
#include <Light.hpp>

namespace imeng
{
	class Render_Component :public Component
	{

	public:
		/*!
		 * @brief Constructor
		 * 
		 * \param parent Entidad del componente
		 */
		Render_Component(Entity * parent)
			:Component(parent) {}

		bool initialize() override;
		virtual bool parse_property(xmlNode * data) override;
		void finalize() override;
		virtual void run(float deltaTime) override;

	};

	class Mesh_Component :public Render_Component
	{

	private:
		/**
		* @brief Nodo del modelo
		*/
		std::shared_ptr<glt::Model_Obj> model_node;

	public:
		/**
		 * @brief Constructor de Mesh
		 * 
		 * @param parent Entidad del componente
		 * @param path Ruta relativa del modelo
		 */
		Mesh_Component(Entity * parent, const std::string & path)
			:Render_Component(parent)
		{
			
		}

		/**
		 * @brief Constructor de Mesh sin ruta
		 * 
		 * @param parent Entidad del componente
		 */
		Mesh_Component(Entity * parent)
			:Render_Component(parent)
		{
			model_node = nullptr;
		}

		bool parse_property(xmlNode * data) override;
		void run(float deltaTime) override;

		/**
		 * 
		 * 
		 * @return Devuelve el nodo del modelo
		 */
		std::shared_ptr<glt::Model_Obj> get_mesh();
	};

	class Camera_Component :public Render_Component
	{
	private:
		/**
		* @brief Nodo de la camara
		*/
		std::shared_ptr<glt::Camera> camera_node;

	public:
		/**
		 * @brief Constructor de la camara
		 * 
		 * @param parent Entidad del componente
		 */
		Camera_Component(Entity * parent)
			:Render_Component(parent), camera_node(new glt::Camera(90.f, 0.3f, 1000.f, 1.f))
		{
			
		}

		/**
		 * 
		 * 
		 * @return Devuelve el nodo de la camara
		 */
		std::shared_ptr<glt::Camera> get_camera();

		void run(float deltaTime) override;
	};

	class Light_Component :public Render_Component
	{
	private:
		/**
		* @brief Nodo de la luz
		*/
		std::shared_ptr<glt::Light> light_node;

	public:
		/**
		 * @brief Construct a new Light_Component object
		 * 
		 * @param parent Entidad a la que pertenece
		 */
		Light_Component(Entity * parent)
			:Render_Component(parent), light_node(new glt::Light())
		{
			
		}
		
		/**
		 * @brief Devuelve el nodo de Luz
		 * 
		 * @return std::shared_ptr<glt::Light> 
		 */
		std::shared_ptr<glt::Light> get_light();
		
		void run(float deltaTime) override;
	};

}

