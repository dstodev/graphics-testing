/*
        2019 Daniel Stotts
 */

#ifndef MSDL_HELPERS_H
#define MSDL_HELPERS_H

#include <iostream>
using std::cout;
using std::endl;

#include <SDL.h>


#define MSDL_ASSERT_ZERO(expression)                                                                                   \
	if (expression != 0) {                                                                                         \
		cout << "Expression resolved to non-zero value: " << expression << "\n";                               \
		cout << "SDL_Error: " << SDL_GetError() << endl;                                                       \
	}

#define MSDL_ASSERT_NOT_NULL(expression)                                                                               \
	if (expression == nullptr) {                                                                                   \
		cout << "Expression resolved to null value: " << expression << "\n";                                   \
		cout << "SDL_Error: " << SDL_GetError() << endl;                                                       \
	}

#endif
