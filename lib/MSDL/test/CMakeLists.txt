# Tests
include(test_util)

util_add_test(test_msdl
	FILES
		test_msdl_surface.cxx
	LIBRARIES
		msdl
)
