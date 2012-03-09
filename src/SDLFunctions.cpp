#include "SDLFunctions.hpp"

SDL_Surface *load_image(std::string filename) {
	SDL_Surface* loadedImage = NULL;

	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load( filename.c_str() );
	if (loadedImage != NULL ) {
		optimizedImage = SDL_DisplayFormat(loadedImage );

		SDL_FreeSurface(loadedImage);
	}
	return optimizedImage;
}
int rectContains(int x, int y, int width, int height, int px, int py) {
	if (abs(x-px) < width && abs(y-py) < height) 
		return 1;
	return 0;
}
void apply_surface (int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}
