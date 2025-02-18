/**
 * @file Render_Component.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Class of a render component (Mesh, camera or light)
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
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
		/* Constructor*/
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
		/* Pointer to obj model */
		std::shared_ptr<glt::Model_Obj> model_node;

	public:
		/**
		 * @brief Constructor
		 * @param parent owner entity
		 * @param path Relative path of the model
		 */
		Mesh_Component(Entity * parent, const std::string & path)
			:Render_Component(parent) 
		{}

		/**
		 * @brief Constructor
		 * @param parent owner entity
		 */
		Mesh_Component(Entity * parent)
			:Render_Component(parent)
		{
			model_node = nullptr;
		}

		bool parse_property(xmlNode * data) override;
		void run(float deltaTime) override;

		/* Returns the obj model */
		std::shared_ptr<glt::Model_Obj> get_mesh() const
		{
			return model_node;
		}
	};

	class Camera_Component :public Render_Component
	{
	private:
		/* Pointer to camera node */
		std::shared_ptr<glt::Camera> camera_node;

	public:
		/**
		 * @brief Constructor
		 * @param parent owner entity
		 */
		Camera_Component(Entity * parent)
			:Render_Component(parent), camera_node(new glt::Camera(90.f, 0.3f, 1000.f, 1.f)) 
		{}

		void run(float deltaTime) override;

		/* Returns the camera */
		std::shared_ptr<glt::Camera> get_camera() const
		{
			return camera_node;
		}
	};

	class Light_Component :public Render_Component
	{
	private:
		/* Pointer to light node */
		std::shared_ptr<glt::Light> light_node;

	public:
		/**
		 * @brief Constructor
		 * @param parent owner entity
		 */
		Light_Component(Entity * parent)
			:Render_Component(parent), light_node(new glt::Light())
		{}
		
		void run(float deltaTime) override;

		/* Returns the light */
		std::shared_ptr<glt::Light> get_light() const
		{
			return light_node;
		}
	};
}
