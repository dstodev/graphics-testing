# 2019 Daniel Stotts

include(CPack)

add_executable(graphics-testing WIN32 main.cxx)

target_link_libraries(graphics-testing
	msdl
)

file(GLOB_RECURSE public_resources "${CMAKE_SOURCE_DIR}/resource/*.*")
set_target_properties(graphics-testing PROPERTIES
	RESOURCE "${public_resources}"
)

install(TARGETS graphics-testing
	RESOURCE DESTINATION bin/img
	RUNTIME DESTINATION bin
)

# Copy DLLs and assets
add_custom_command(TARGET graphics-testing PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory    "${CMAKE_SOURCE_DIR}/resource" "$<TARGET_FILE_DIR:graphics-testing>"
#	COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:msdl>"          "$<TARGET_FILE_DIR:graphics-testing>"
	COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:SDL2::sdl2>"    "$<TARGET_FILE_DIR:graphics-testing>"
)
