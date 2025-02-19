#pragma once


// It is created forward declarations of some identifiers of external libraries
// which are used in engine headers in order to projects that include them
// do not have to add their headers.

///////////////////////////////////////// SDL /////////////////////////////////////////

typedef struct SDL_Window   SDL_Window;
typedef void              * SDL_GLContext;

/////////////////////////////////// OPENGL TOOLKIT ////////////////////////////////////

namespace glt
{

	class Render_Node;

}
