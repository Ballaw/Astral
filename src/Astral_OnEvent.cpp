#include "Astral.h"

void Astral::OnEvent(SDL_Event* Event) {
	if(Event->type == SDL_QUIT) {
		Running = false;
	}
}
