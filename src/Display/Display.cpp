#include "Display.hpp"

Display::Display () {
	screenWidth = 640;
	screenHeight = 480;
	screenBpp = 32;
	screen = SDL_SetVideoMode(screenWidth,screenHeight,screenBpp,SDL_SWSURFACE);
	
	if (screen==NULL)
		return;
	
	
	SDL_WM_SetCaption( "Astral", NULL );
	if (SDL_Flip(screen)== -1)
		return;
}
int Display::update() {
	
	BOOST_FOREACH( SDL_Surface * t, objects )
   	{
        	apply_surface (0, 0, t, screen);
   	}
	SDL_Flip(screen);
}
void Display::quit() {
	
}
