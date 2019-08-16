add_executable(testing-sdl2 WIN32 main.cpp)

target_link_libraries(testing-sdl2
	PRIVATE
		msdl
)
