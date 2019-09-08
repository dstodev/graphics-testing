add_executable(testing-sdl2 WIN32 main.cpp)

target_link_libraries(testing-sdl2
	msdl
)

add_custom_command(TARGET testing-sdl2 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/resrc
		$<TARGET_FILE_DIR:testing-sdl2>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${libMSDL_SOURCE_DIR}/lib/SDL2-2.0.10/lib/x64/SDL2.dll
		$<TARGET_FILE_DIR:testing-sdl2>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:msdl>
		$<TARGET_FILE_DIR:testing-sdl2>
)
