#pragma once




#include <string>
#include <assert.h>
#include "Keyboard.hpp"

//#include <SDL.h>


struct SDL_Window;
typedef void * SDL_GLContext;

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

		SDL_Window * window;
		int screen_width;
		int screen_height;
		SDL_GLContext gl_context;


	public:

		Window(const string&, int, int, bool);
		~Window();

		void set_fullscreen();

		void set_windowed();

		void set_position(int new_left_x, int new_top_y);

		void set_size(int new_width, int new_height);

		unsigned get_width() const;

		unsigned get_height() const;

		bool poll(Event & event) const;

		void clear() const;

	};

	bool initialize(int subsystem);
	void finalize();

}
