# Get SDL2 variables
include(sdl2-config.cmake)

target_link_libraries(msdl
	PUBLIC
		SDL2::sdl2
		SDL2::sdl2main
)
