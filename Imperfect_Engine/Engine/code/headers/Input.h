/**
 * @file Input.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Class that manages keyboard input
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once
#include <cstdint>

namespace imeng 
{
	/* Enum of keys */
	enum Key
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,

		NUM_0,
		NUM_1,
		NUM_2,
		NUM_3,
		NUM_4,
		NUM_5,
		NUM_6,
		NUM_7,
		NUM_8,
		NUM_9,

		ARROW_LEFT,
		ARROW_RIGHT,
		ARROW_UP,
		ARROW_DOWN,

		SPACE,
		BACK_SPACE,
		ESC,
		TAB,

		LEFT_SHIFT,
		RIGHT_SHIFT,

		LEFT_ATL,
		RIGHT_ALT,

		LEFT_CONTROL,
		RIGHT_CONTROL
	};

	class Input
	{
	public:
		/* Constructor */
		Input();
		
		/* Get the key SDL object */
		uint8_t get_key_SDL(Key key) const;

	private:
		/* Array of SDL keys */
		static const uint8_t SDL_Keys[];

		/* Pointer to the current state*/
		const uint8_t* state;
	};


}