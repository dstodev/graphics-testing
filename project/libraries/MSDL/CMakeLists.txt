cmake_minimum_required(VERSION 3.5.x)
project(libMSDL VERSION 0.1.0)

find_package(SDL2 REQUIRED)

add_library(msdl SHARED
	source/msdl_surface.cpp
	source/msdl_window.cpp
)

target_include_directories(msdl
	PUBLIC
		include
	PRIVATE
		source
		include/SDL2
)

target_link_libraries(${TARGET_MAIN}
	PRIVATE
		sdl2
		sdl2main
)
