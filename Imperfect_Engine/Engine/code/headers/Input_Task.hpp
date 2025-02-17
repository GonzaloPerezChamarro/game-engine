/**
 * @file Input_Task.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase que gestiona los eventos de la ventana
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include "Task.hpp"


namespace imeng
{
	class Input_Task :public Task
	{
	public:
		/**
		 * @brief Construct a new Input_Task object
		 * 
		 */
		Input_Task(Scene* scene , bool = false);

		bool initialize() override;
		void run(float delta_Time) override;
		bool finalize() override;
	};

}
