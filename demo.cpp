#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <stdio.h>

using namespace std;

SDL_Surface *load_image( std::string filename);
void apply_surface(int x, int y, SDL_Surface* src, SDL_Surface* dest);
int rectContains(int,int,int,int,int,int);

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Event event;

double x=200,y=220;
double xc1 = 4, yc1 = 5;
int main(int argc, char * args[]) {

	if (SDL_Init( SDL_INIT_EVERYTHING ) == -1)
		return 1;

	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
	
	if (screen==NULL)
		return 1;
	
	
	SDL_WM_SetCaption( "Hello World", NULL );
	if (SDL_Flip(screen)== -1)
		return 1;
	bool quit = false;
	double xvel = 0; double yvel = 0;
	double x1vel =0; double y1vel = 1;
	while(!quit) {
		SDL_Event keyevent;    //The SDL event that we will poll to get events.
 
		while (SDL_PollEvent(&keyevent))   //Poll our SDL key event for any keystrokes.
		{
    			if (keyevent.type == SDL_KEYDOWN) {
      				switch(keyevent.key.keysym.sym){
        				case SDLK_LEFT:
						xvel += -3;
          					break;
        				case SDLK_RIGHT:
						xvel += 3;
          					break;
        				case SDLK_UP:
						yvel += -3;
          					break;
        				case SDLK_DOWN:
						yvel += 3;
          					break;
        				default:
          					break;
      				}
    			} else if (keyevent.type == SDL_KEYUP) {
				switch(keyevent.key.keysym.sym){
        				case SDLK_LEFT:
						xvel +=3;
          					break;
        				case SDLK_RIGHT:
						xvel += -3;
          					break;
        				case SDLK_UP:
						yvel += 3;
          					break;
        				case SDLK_DOWN:
						yvel += -3;
          					break;
        				default:
          					break;
      				}
			} else if (keyevent.type == SDL_QUIT) {
				quit = true;
			}
  			
			
		}	
	}	
	SDL_Quit();
}

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
