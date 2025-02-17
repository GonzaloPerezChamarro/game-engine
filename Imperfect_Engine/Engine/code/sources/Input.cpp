/********************************

Author: Gonzalo Perez Chamarro
Date: 27/12/2018

*********************************
*/


#include "Input.hpp"
#include <SDL_keyboard.h>

namespace imeng
{
	const uint8_t Input::SDL_Keys[] =
	{
		SDL_SCANCODE_A,
		SDL_SCANCODE_B,
		SDL_SCANCODE_C,
		SDL_SCANCODE_D,
		SDL_SCANCODE_E,
		SDL_SCANCODE_F,
		SDL_SCANCODE_G,
		SDL_SCANCODE_H,
		SDL_SCANCODE_I,
		SDL_SCANCODE_J,
		SDL_SCANCODE_K,
		SDL_SCANCODE_L,
		SDL_SCANCODE_M,
		SDL_SCANCODE_N,
		SDL_SCANCODE_O,
		SDL_SCANCODE_P,
		SDL_SCANCODE_Q,
		SDL_SCANCODE_R,
		SDL_SCANCODE_S,
		SDL_SCANCODE_T,
		SDL_SCANCODE_U,
		SDL_SCANCODE_V,
		SDL_SCANCODE_W,
		SDL_SCANCODE_X,
		SDL_SCANCODE_Y,
		SDL_SCANCODE_Z,

		SDL_SCANCODE_0,
		SDL_SCANCODE_1,
		SDL_SCANCODE_2,
		SDL_SCANCODE_3,
		SDL_SCANCODE_4,
		SDL_SCANCODE_5,
		SDL_SCANCODE_6,
		SDL_SCANCODE_7,
		SDL_SCANCODE_8,
		SDL_SCANCODE_9,

		SDL_SCANCODE_LEFT,
		SDL_SCANCODE_RIGHT,
		SDL_SCANCODE_UP,
		SDL_SCANCODE_DOWN,

		SDL_SCANCODE_SPACE,
		SDL_SCANCODE_BACKSPACE,

		SDL_SCANCODE_ESCAPE,
		SDL_SCANCODE_TAB,

		SDL_SCANCODE_LSHIFT,
		SDL_SCANCODE_RSHIFT,

		SDL_SCANCODE_LALT,
		SDL_SCANCODE_RALT,

		SDL_SCANCODE_LCTRL,
		SDL_SCANCODE_RCTRL
	};


	Input::Input()
		: state(SDL_GetKeyboardState(nullptr))
	{
	}

	uint8_t Input::get_key_SDL(Key key) const
	{
		return state[SDL_Keys[key]];
	}

}