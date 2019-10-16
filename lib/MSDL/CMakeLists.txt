# 2019 Daniel Stotts

cmake_minimum_required(VERSION 3.15.x)
project(libMSDL VERSION 0.1.0 LANGUAGES CXX)

# MSDL
add_library(msdl SHARED)
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(lib)

if("${BUILD_TESTING}")
	add_subdirectory(test)
endif()

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
