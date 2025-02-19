/**
 * @file Task.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Base class of a task
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


#include <list>

namespace imeng 
{

	class Scene;
	class Component;

	class Task 
	{
	public:
		/* Constructor */
		Task(Scene* scene, int given_priority, bool finished);

		/* Virtual pure function. Initialize the task */
		virtual bool initialize() = 0;

		/* Virtual pure function. Finalize the task */
		virtual bool finalize() = 0;

		/* Virtual pure function. Executes the task */
		virtual void run(float) = 0;

		/* Returns the task priority */
		int get_priority() const;

		/* Indicates if the task has finished */
		bool is_finished() const { return finished; }

		/* Overloading of < operator. Compare a tasks by their priorities */
		bool operator<(const Task& a)
		{
			return priority < a.get_priority();
		}

	protected:

		/* Priority of a tasks */
		int priority;

		/* Pointer to game scene */
		Scene * scene;

		/* Flag that indicates if the task has finished */
		bool finished;
	};

}
