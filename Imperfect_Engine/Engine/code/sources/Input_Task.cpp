/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/

#include "Input_Task.h"
#include "Kernel.h"
#include "Scene.h"

#include <SDL.h>


namespace imeng
{
	Input_Task::Input_Task(Scene* scene, bool finished)
		: Task(scene, 2, finished)
	{}

	bool Input_Task::initialize() { return true; }

	bool Input_Task::finalize() { return true; }

	void Input_Task::run(float deltaTime)
	{
		SDL_Event event;
		while (scene->get_window()->poll(event))
		{
			if (event.type == SDL_WINDOWEVENT)
			{
				switch (event.window.event)
				{
				case SDL_WINDOWEVENT_CLOSE:
					scene->get_kernel()->stop();
				}
			}
		}
	}
}
