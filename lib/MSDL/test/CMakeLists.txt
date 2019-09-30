add_executable(testgtest
	msdl_surface_test.cpp
)

target_link_libraries(testgtest
	PRIVATE
		msdl
		gtest
		gtest_main
)
