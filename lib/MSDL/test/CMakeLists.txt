# Tests
add_executable(test_msdl
	test_msdl_surface.cxx
)

target_link_libraries(test_msdl
	PRIVATE
		msdl
		gtest
		gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_msdl)
