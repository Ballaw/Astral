#include "Astral.h"

bool Astral::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	
	return true;
}
