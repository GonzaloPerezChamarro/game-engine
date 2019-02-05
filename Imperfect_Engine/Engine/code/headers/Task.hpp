/**
 * @file Task.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Clase base de una tarea
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include <list>

namespace imeng {

	class Scene;
	class Component;

	class Task {

	protected:

		/**
		* @brief Prioridad de la tarea
		*/
		int priority;

		/**
		* @brief Puntero a la escena de la tarea
		*/
		Scene * scene;

		/**
		* @brief Booleano de finalizacion de la tarea
		*/
		bool finished;


	public:

		/**
		 * @brief Constructor
		 * 
		 */
		Task(Scene&, int, bool);

		/**
		 * @brief Devuelve la prioridad de la tarea
		 * 
		 * @return int 
		 */
		int get_priority()const;

		/**
		 * @brief Indica si la tarea ha finalizado
		 * 
		 * @return true 
		 * @return false 
		 */
		bool is_finished() const { return finished; }

		/**
		 * @brief Inicializa la tarea (Virtual)
		 * 
		 * @return true 
		 * @return false 
		 */
		virtual bool initialize() = 0;

		/**
		 * @brief Finaliza la tarea (Virtual)
		 * 
		 * @return true 
		 * @return false 
		 */
		virtual bool finalize() = 0;

		/**
		 * @brief Ejecuta la tarea (Virtual)
		 * 
		 */
		virtual void run(float) = 0;

		/**
		 * @brief Compara segun prioridad
		 * 
		 * @param a 
		 * @return true 
		 * @return false 
		 */
		bool operator<(const Task& a)
		{
			return priority < a.get_priority();
		}
	};

}
