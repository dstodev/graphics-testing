/*
	2019 Daniel Stotts
*/

#include <iostream>
using std::cout;
using std::endl;

#include <SDL.h>
#include <msdl_surface.hxx>
#include <msdl_window.hxx>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void print_parameters(int argc, char * argv[]);

int main(int argc, char * argv[])
{
	print_parameters(argc, argv);

	// TODO: Wrap in RAII class constructor
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << SDL_GetError() << endl;
		return 1;
	}

	MSDL::Window window("First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
	                    SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window) {
		window.fill_rect(0, 0x00, 0xFF, 0xFF);
		window.blit_from("img/test.bmp", 0, 0);

		window.update();
		SDL_Delay(5000);
	}

	// TODO: Wrap in RAII class destructor
	SDL_Quit();

	return 0;
}

void print_parameters(int argc, char * argv[])
{
	if (argc > 1) {
		cout << "Parameters:\n";
		for (int i = 1; i < argc; ++i) {
			cout << i << ". " << argv[i] << '\n';
		}
		cout << endl;
	}
}
