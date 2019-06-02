cmake_minimum_required(VERSION 3.0.0)
project(test-03 VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
include_directories(include/SDL2)

link_directories(libraries)

file(GLOB SOURCES "source/*.cpp")
add_executable(test-03 WIN32 ${SOURCES})
target_link_libraries(test-03 sdl2main sdl2)

add_custom_command(TARGET test-03 POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:test-03>)

if (MSVC)
	target_compile_options(test-03 PRIVATE /W4 /WX)
endif()
