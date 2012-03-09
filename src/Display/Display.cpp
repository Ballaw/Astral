#include "Display.hpp"

Display::Display () {
	if (SDL_Init( SDL_INIT_EVERYTHING ) == -1)
		return;
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
	for (unsigned i=0; i < objects.size(); i++) {
    		apply_surface (0, 0, objects[i], screen);
}
	SDL_Flip(screen);
}
void Display::quit() {
	SDL_Quit();
}
