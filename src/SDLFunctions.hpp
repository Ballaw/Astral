#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

using namespace std;

SDL_Surface *load_image( std::string filename);
void apply_surface(int x, int y, SDL_Surface* src, SDL_Surface* dest);
int rectContains(int,int,int,int,int,int);

