
/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Kernel.h"
#include "Task.h"

#include <iostream>

namespace imeng 
{
	std::string RESOURCES_PATH = "resources//";

	void Kernel::add_task(Task& task)
	{
		tasks.insert(&task);
	}

	void Kernel::initialize()
	{
		std::cout << "Init kernel" << std::endl;

		for (Task* task : tasks)
		{
			task->initialize();
		}
	}

	void Kernel::execute()
	{
		std::cout << "Executing kernel..." << std::endl;

		exit = false;

		do
		{
			time = high_res_clock::now();

			for (auto iterator = tasks.begin(), end = tasks.end();
				iterator != end && !exit;
				++iterator)
			{
				(*iterator)->run((float)deltaTime.count());

				if ((*iterator)->is_finished())
				{
					(*iterator)->finalize();
					tasks.erase(iterator);
				}
			}

			deltaTime = duration(time - last_frame);
			last_frame = time;

		} 
		while (!exit && !tasks.empty());
	}

	void Kernel::stop()
	{
		std::cout << "Kernel stopped" << std::endl;

		exit = true;
	}
}