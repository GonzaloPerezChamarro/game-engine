/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gráficos y Plugins

*********************************
*/
#include "Task.hpp"
#include "Kernel.hpp"

namespace imeng
{

	Task::Task(Scene & scene,int given_priority, bool finished) 
		:scene(&scene), priority(given_priority) , finished(finished){}

	int Task::get_priority()const { return priority; }

}

