/**
 * @file Window.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Main game window
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
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

	class Window 
	{
	public:
		/* Struct that represents an event of the window */
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

	public:
		/* Constructor */
		Window(const string&, int, int, bool);

		/* Destructor */
		~Window();

		/* Set fullscreen mode */
		void set_fullscreen();

		/* Set windowed mode */
		void set_windowed();

		/**
		 * @brief Sets a new position for the window
		 * @param new_left_x Value of X axis from left to right
		 * @param new_top_y Value of Y axis from top to down
		 */
		void set_position(int new_left_x, int new_top_y);

		/**
		 * @brief Sets a new size for the window
		 * @param new_width width
		 * @param new_height height
		 */
		void set_size(int new_width, int new_height);

		/* Returns the window width */
		unsigned get_width() const;

		/* Returns the window height */
		unsigned get_height() const;

		/**
		 * @brief For sending window events
		 * @param event Event to send
		 * @return int 1 if there are any pending events, or 0 if there are none available.
		 */
		int poll(SDL_Event & event);

		/* Clear the window */
		void clear() const;

		/* Swap buffers */
		void swapBuffers();

		/* Enables the vertical sync */
		void enable_vsync();

		/* Disables the vertical sync */
		void disable_vsync();

	private:
		/* Pointer to the SDL window */
		SDL_Window* window;

		/* SDL_GL context */
		SDL_GLContext gl_context;
	};
	
	bool initialize(int subsystem);
	void finalize();
}
