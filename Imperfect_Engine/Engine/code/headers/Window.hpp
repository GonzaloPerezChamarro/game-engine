/**
 * @file Window.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Ventana principal del juego
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once




#include <string>
#include <assert.h>
#include "Keyboard.hpp"
#include "declarations.hpp"


struct SDL_Window;
typedef void * SDL_GLContext;
union SDL_Event;

using std::string;


namespace imeng {

	class Window {

	public:

		struct Event
		{
			enum Type
			{
				CLOSE,
				KEY_PRESSED,
				KEY_RELEASED
			}
			type;

			union Data
			{
				struct { int key_code; } keyboard;

				struct
				{
					float x, y;
					int   buttons;
				}
				mouse;
			}
			data;
		};

	private:

		/**
		* @brief Puntero a la ventana SDL
		*/
		SDL_Window * window;

		/**
		* @brief Ancho de la ventana
		*/
		int screen_width;

		/**
		* @brief Altura de la ventana
		*/
		int screen_height;

		/**
		* @brief Contexto SDL_GL
		*/
		SDL_GLContext gl_context;


	public:

		/**
		 * @brief Constructor
		 * 
		 */
		Window(const string&, int, int, bool);

		/**
		 * @brief Destructor
		 * 
		 */
		~Window();

		/**
		 * @brief Set fullscreen 
		 * 
		 */
		void set_fullscreen();

		/**
		 * @brief Set windowed 
		 * 
		 */
		void set_windowed();

		/**
		 * @brief Settea la posicion de la ventana
		 * 
		 * @param new_left_x 
		 * @param new_top_y 
		 */
		void set_position(int new_left_x, int new_top_y);

		/**
		 * @brief Settea el tamaño de la ventana
		 * 
		 * @param new_width 
		 * @param new_height 
		 */
		void set_size(int new_width, int new_height);

		/**
		 * @brief Devuelve el ancho de la ventana
		 * 
		 * @return unsigned 
		 */
		unsigned get_width() const;

		/**
		 * @brief Devuelve el alto de la ventana
		 * 
		 * @return unsigned 
		 */
		unsigned get_height() const;

		/**
		 * @brief Eventos de ventana
		 * 
		 * @param event 
		 * @return int 
		 */
		int poll(SDL_Event & event);

		/**
		 * @brief Limpia la ventana SDL
		 * 
		 */
		void clear() const;

		/**
		 * @brief swap buffers
		 * 
		 */
		void swapBuffers();

		/**
		 * @brief Activa la sincronizacion vertical
		 * 
		 */
		void enable_vsync();

		/**
		 * @brief Desactiva la sincronizacion vertical
		 * 
		 */
		void disable_vsync();

	};
	
	bool initialize(int subsystem);
	void finalize();

}
