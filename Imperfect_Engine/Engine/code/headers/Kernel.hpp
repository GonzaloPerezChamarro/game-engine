/**
 * @file Kernel.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Kernel principal del motor
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include <list>
#include <chrono>
#include <set>



namespace imeng {

	class Task;

	class Kernel {

		typedef std::set<Task * > Task_List;
		typedef std::chrono::high_resolution_clock high_res_clock;
		typedef std::chrono::time_point<high_res_clock> time_point;
		typedef std::chrono::duration<float> duration;

	private:
		/**
		* @brief Set de tareas
		*/
		Task_List tasks;

		/**
		* @brief booleano de finalizacion
		*/
		bool exit;

		/**
		* @brief booleano de pausa
		*/
		bool paused;

		/**
		* @brief Variable de tiempo
		*/
		time_point last_frame, time;

		/**
		* @brief deltaTime del juego
		*/
		duration deltaTime;

	public:

		/**
		 * @brief Singleton
		 * 
		 * @return Kernel& 
		 */
		static Kernel & instance()
		{
			static Kernel kernel;
			return kernel;
		}

		/**
		 * @brief Destroy the Kernel object
		 * 
		 */
		~Kernel()
		{
			tasks.clear();
		}

	private:

		/**
		 * @brief Construct a new Kernel object
		 * 
		 */
		Kernel() :paused(false),
			last_frame(high_res_clock::now()),
			time(high_res_clock::now()),
			deltaTime(time - last_frame) {}

		
	public:
		
		/**
		 * @brief Añade una tarea a la lista
		 * 
		 */
		void add_task(Task &);

		/**
		 * @brief Inicializa todas las tareas
		 * 
		 */
		void initialize();

		/**
		 * @brief Llama al metodo run de todas las tareas
		 * 
		 */
		void execute();

		/**
		 * @brief Finaliza todas las tareas
		 * 
		 */
		void stop();
		//void pause();
		//void resume();


	};

}

