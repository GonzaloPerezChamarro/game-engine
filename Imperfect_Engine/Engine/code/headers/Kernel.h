/**
 * @file Kernel.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Main engine kernel
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


#include <list>
#include <chrono>
#include <set>

namespace imeng 
{

	class Task;

	class Kernel 
	{
		typedef std::set<Task * > Task_List;
		typedef std::chrono::high_resolution_clock high_res_clock;
		typedef std::chrono::time_point<high_res_clock> time_point;
		typedef std::chrono::duration<float> duration;

	public:
		/* Returns the singleton kernel */
		static Kernel& instance()
		{
			static Kernel kernel;
			return kernel;
		}

		/* Destructor */
		~Kernel()
		{
			tasks.clear();
		}

		/* Initializes all tasks*/
		void initialize();

		/* Adds a task to the list */
		void add_task(Task&);

		/* Runs all tasks */
		void execute();

		/* Stops the kernel */
		void stop();

		// TODO
		//void pause();
		//void resume();

	private:
		/* Private constructor */
		Kernel() :exit(false), paused(false),
			last_frame(high_res_clock::now()),
			time(high_res_clock::now()),
			deltaTime(time - last_frame) {}

	private:
		/* Tasks set */
		Task_List tasks;

		/* Flag that indicates if kernel has finished */
		bool exit;

		/* FLag that indicates if kernel is paused */
		bool paused;

		/* Time variables */
		time_point last_frame, time;

		/* Delta time */
		duration deltaTime;
	};
}

