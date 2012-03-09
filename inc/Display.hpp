#include "SDLFunctions.hpp"
#include <vector>

using namespace std;

class Display {
	private:
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		int SCREEN_BPP;
		vector<SDL_Surface> objects;	
	public:
		Display ();
		
};
