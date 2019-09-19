# 2019 Daniel Stotts

add_library(SDL2::sdl2 SHARED IMPORTED GLOBAL)
set(version 2.0.10)
set_target_properties(SDL2::sdl2 PROPERTIES
	IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/SDL2-${version}/lib/x64/SDL2.dll"
	IMPORTED_IMPLIB "${CMAKE_CURRENT_LIST_DIR}/SDL2-${version}/lib/x64/SDL2.lib"
	INTERFACE_INCLUDE_DIRECTORIES
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/SDL2-${version}/include>;$<INSTALL_INTERFACE:include/SDL2>"
)
add_library(SDL2::sdl2main STATIC IMPORTED)
set_target_properties(SDL2::sdl2main PROPERTIES
	IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/SDL2-${version}/lib/x64/SDL2main.lib"
)
file(GLOB public_headers "${CMAKE_CURRENT_LIST_DIR}/SDL2-${version}/include/*.h*")
install(FILES ${public_headers} DESTINATION include/SDL2)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/SDL2-${version}/lib/x64/SDL2.dll" DESTINATION bin)
