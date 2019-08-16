/*
        2019 Daniel Stotts
 */

#include <iostream>
using std::cout;
using std::endl;

#include <SDL.h>

#include "msdl_surface.h"
#include "msdl_window.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char * argv[])
{
	if (argc > 1) {
		cout << "Parameters:\n";
		for (int i = 1; i < argc; ++i) {
			cout << i << ". " << argv[i] << '\n';
		}
		cout << endl;
	}

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << SDL_GetError() << endl;
		return 1;
	}

	MSDL_Surface screen_surface;
	MSDL_Window window("First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
	                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (!(screen_surface = window.get_surface()).is_empty()) {
		screen_surface.fill_rect(0, 0x00, 0xFF, 0xFF);
		screen_surface.blit_from("images/test.bmp", 0, 0);

		window.update();
		SDL_Delay(5000);
	}

	SDL_Quit();

	return 0;
}
