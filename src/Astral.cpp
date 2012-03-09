#include "Astral.h"

Astral::Astral() {
	Display_Surf = NULL;
	Running = true;
}

int Astral::OnExecute() {
	if(OnInit() == false) {
		return -1;
	}

	SDL_Event Event;

	while(Running) {
		while(SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}
		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

int main(int argc, char * argv[]) {
	Astral AstralEnv;

	return AstralEnv.OnExecute();
}
