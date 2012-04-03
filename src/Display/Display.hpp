#include "SDLFunctions.hpp"
#include <vector>
#include <boost/foreach.hpp>

using namespace std;

class Display {
	public:
		int screenWidth;
		int screenHeight;
		int screenBpp;
		SDL_Surface * screen;
		vector<SDL_Surface*> objects;	
	
		Display ();
		int update();
		void quit();
		
};
