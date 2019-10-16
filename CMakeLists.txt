# 2019 Daniel Stotts

cmake_minimum_required(VERSION 3.15.x)
project(test-03 VERSION 0.2.0)

# Set global runtime output directory so .dll files are placed adjacent to .exe files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Enable testing for all subsequent subdirectories
include(CTest)

add_subdirectory(src)
add_subdirectory(lib)
