# 2019 Daniel Stotts

cmake_minimum_required(VERSION 3.5.x)
project(libMSDL VERSION 0.1.0 LANGUAGES CXX)

include(lib/sdl2-config.cmake)

add_library(msdl SHARED
	src/msdl_surface.cpp
	src/msdl_window.cpp
)

include(GenerateExportHeader)
generate_export_header(msdl EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/msdl_export.h)

target_include_directories(msdl
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
	PRIVATE
		src
)

target_link_libraries(msdl
	PUBLIC
		SDL2::sdl2
		SDL2::sdl2main
)

file(GLOB public_headers "${CMAKE_CURRENT_LIST_DIR}/include/*.h*")
list(APPEND public_headers "${CMAKE_BINARY_DIR}/include/msdl_export.h")
set_target_properties(msdl PROPERTIES
	PUBLIC_HEADER "${public_headers}"
)

install(TARGETS msdl EXPORT msdl
	PUBLIC_HEADER DESTINATION include  # Location to install headers in ${public_headers} defined above
	INCLUDES DESTINATION include/SDL2  # Adds this directory to INTERFACE_INCLUDE_DIRECTORIES upon install(export)
	                                   # Does not need "include" by itself, as it is added in the above
	                                   # target_include_directories $<INSTALL_INTERFACE:include> statement.
	ARCHIVE DESTINATION lib  # .a, .so
	LIBRARY DESTINATION lib  # .lib
	RUNTIME DESTINATION bin  # .exe, .dll
)

install(EXPORT msdl
	NAMESPACE MSDL::
	DESTINATION cmake
)

# export(EXPORT msdl
# 	NAMESPACE MSDL::
# )

add_subdirectory(test)
