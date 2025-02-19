/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/
#include "Task.h"
#include "Kernel.h"

namespace imeng
{
	Task::Task(Scene* scene, int given_priority, bool finished)
		:scene(scene), priority(given_priority) , finished(finished){}

	int Task::get_priority() const { return priority; }
}

