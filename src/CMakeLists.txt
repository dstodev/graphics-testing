# 2019 Daniel Stotts

include(CPack)

add_executable(testing-sdl2 WIN32 main.cpp)

target_link_libraries(testing-sdl2
	msdl
)

file(GLOB_RECURSE public_resources "${CMAKE_SOURCE_DIR}/resource/*.bmp")
set_target_properties(testing-sdl2 PROPERTIES
	RESOURCE "${public_resources}"
)

install(TARGETS testing-sdl2
	RESOURCE DESTINATION bin/img
	RUNTIME DESTINATION bin
)

add_custom_command(TARGET testing-sdl2 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/resource
		$<TARGET_FILE_DIR:testing-sdl2>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:msdl>
		$<TARGET_FILE_DIR:testing-sdl2>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:SDL2::sdl2>
		$<TARGET_FILE_DIR:testing-sdl2>
)
