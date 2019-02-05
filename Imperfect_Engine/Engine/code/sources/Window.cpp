/********************************

Autor: Gonzalo Perez Chamarro
Fecha: 27/12/2018
Motores Gr�ficos y Plugins

*********************************
*/
#include <SDL.h>
#include <cassert>
#include <Window.hpp>
#include <OpenGL.hpp>

namespace imeng
{
	Window::Window(const std::string & title, int width, int height, bool fullscreen = false)
	{
		window = nullptr;
		gl_context = nullptr;

		if (initialize(SDL_INIT_VIDEO))
		{

			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow
			(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			assert(window != nullptr);
			//Creacion del contexto open_gl
			gl_context = SDL_GL_CreateContext(window);

			if (window)
			{
				gl_context = SDL_GL_CreateContext(window);

				assert(gl_context != nullptr);

				if (gl_context && glt::initialize_opengl_extensions())
				{
					if (fullscreen)
					{
						//Hacer fullscreen en caso de indicarlo
						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
				}
			}
		}

	}

	Window::~Window()
	{
		SDL_GL_DeleteContext(gl_context);
		SDL_DestroyWindow(window);
	}

	void Window::set_fullscreen()
	{
		
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}

	void Window::set_windowed()
	{
		SDL_SetWindowFullscreen(window, 0);
	}

	void Window::set_position(int new_left_x, int new_top_y)
	{
		SDL_SetWindowPosition(window, new_left_x, new_top_y);
	}

	void Window::set_size(int new_width, int new_height)
	{
		if (window) SDL_SetWindowSize(window, new_width, new_height);
	}

	unsigned Window::get_width() const
	{
		int width = 0, height;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(width);
	}

	unsigned Window::get_height() const
	{
		int width, height = 0;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(height);
	}

	void Window::swapBuffers()
	{
		SDL_GL_SwapWindow(window);
	}


	bool initialize(int subsystem)
	{

		static bool finalize_is_not_set = true;

		if (finalize_is_not_set)
		{
			finalize_is_not_set = false;

			std::atexit(finalize);
		}

		// Se inicializa el subsistema si no estaba inicializado:

		if (!SDL_WasInit(subsystem))
		{
			return SDL_Init(subsystem) == 0;
		}

		return true;
	}

	void finalize()
	{
		SDL_Quit();
	}

	int Window::poll(SDL_Event & event)
	{
		return SDL_PollEvent(&event);
	}

	void Window::clear() const
	{
		
		if (gl_context)
		{
			glClearColor(0.9f, 0.6f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
			
	}

	void Window::enable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(1);
	}

	void Window::disable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(0);
	}

}