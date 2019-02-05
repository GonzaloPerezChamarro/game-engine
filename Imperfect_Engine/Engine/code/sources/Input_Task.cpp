/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Graficos y Plugins

*********************************
*/

#include "Input_Task.hpp"
#include "Kernel.hpp"
#include "Scene.hpp"

#include <SDL.h>


namespace imeng
{

	Input_Task::Input_Task(Scene & scene, bool finished)
		:Task(scene, 2, finished)
	{}


	bool Input_Task::initialize() { return true; }

	bool Input_Task::finalize() { return true; }

	/**
	 * @brief Comprueba los eventos de ventana
	 * 
	 * @param deltaTime 
	 */
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