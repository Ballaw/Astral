#ifndef _Astral_H_
#define _ASTRAL_H_

#include "SDL/SDL.h"
#include "Display.hpp"
class Astral {
	private:
	
	bool Running;
	SDL_Surface* Display_Surf;
	Display display;
	public:

	Astral();
	int OnExecute();

	public:

	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnLoop();
	void OnRender();
	void OnCleanup();
};

#endif
