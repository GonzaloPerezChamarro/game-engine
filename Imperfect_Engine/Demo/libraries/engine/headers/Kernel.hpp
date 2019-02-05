#pragma once

#include "Task.hpp"
#include <list>
#include <chrono>


class Task;
namespace imeng {

	class Kernel {

		typedef std::list<Task * > Task_List;
		typedef std::chrono::high_resolution_clock high_res_clock;
		typedef std::chrono::time_point<high_res_clock> time_point;
		typedef std::chrono::duration<float> duration;

	private:
		Task_List tasks;

		bool exit;
		bool paused;

		time_point last_frame, time;
		duration deltaTime;

	public:

		static Kernel & instance()
		{
			static Kernel kernel;
			return kernel;
		}

		~Kernel()
		{
			tasks.clear();
		}

	private:

		Kernel() :paused(false),
			last_frame(high_res_clock::now()),
			time(high_res_clock::now()),
			deltaTime(time - last_frame) {}

		
	public:
		
		void add_task(Task &);
		void initialize();
		void execute();
		void stop();
		//void pause();
		//void resume();


	};

}

