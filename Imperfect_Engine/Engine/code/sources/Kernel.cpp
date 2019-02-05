/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gráficos y Plugins

*********************************
*/
#include "Kernel.hpp"
#include "Task.hpp"

namespace imeng {

	void Kernel::add_task(Task & task)
	{
		tasks.insert(&task);
	}

	void Kernel::initialize()
	{
		for (Task * task : tasks)
		{
			task->initialize();
		}
	}

	void Kernel::execute()
	{
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

		} while (!exit && !tasks.empty());
	}

	void Kernel::stop()
	{
		exit = true;
	}



}