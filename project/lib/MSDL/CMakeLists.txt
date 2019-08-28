cmake_minimum_required(VERSION 3.5.x)
project(libMSDL VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
find_package(SDL2 REQUIRED)

add_library(msdl SHARED
	src/msdl_surface.cpp
	src/msdl_window.cpp
)

target_include_directories(msdl
	PUBLIC
		include
		${SDL2_INCLUDE_DIR}
	PRIVATE
		src
)

target_link_libraries(msdl
	PRIVATE
		${SDL2_LIBRARIES}
)
