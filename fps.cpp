#include <SDL.h>
#include <cstdlib>
#include "fps.h"

double Fps::delay()
{
	now = SDL_GetTicks();

	Uint32 diff = now - preTime;
	if (diff < mspf) SDL_Delay(mspf - diff);

<<<<<<< HEAD

=======
>>>>>>> 692685d4f694990dad408ca44e13975bdee44cfc
	fps = 1.0 / static_cast<double>(SDL_GetTicks() - preTime) * 1000.0;

	preTime = now;

	return fps;
}
<<<<<<< HEAD

=======
>>>>>>> 692685d4f694990dad408ca44e13975bdee44cfc
