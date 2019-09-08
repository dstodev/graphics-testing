cmake_minimum_required(VERSION 3.5.x)
project(libMSDL VERSION 0.1.0 LANGUAGES CXX)

add_library(msdl SHARED
	src/msdl_surface.cpp
	src/msdl_window.cpp
)

target_include_directories(msdl
	PUBLIC
		include
		lib/SDL2-2.0.10/include
		${CMAKE_BINARY_DIR}/exports
	PRIVATE
		src
)

target_link_libraries(msdl
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/lib/SDL2-2.0.10/lib/x64/SDL2.lib
		${CMAKE_CURRENT_LIST_DIR}/lib/SDL2-2.0.10/lib/x64/SDL2main.lib
)

export(
	TARGETS
		msdl
	FILE
		${CMAKE_BINARY_DIR}/exports/msdl_targets.cmake
	NAMESPACE
		MSDL::
)

include(GenerateExportHeader)
generate_export_header(msdl EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/msdl_export.h)
