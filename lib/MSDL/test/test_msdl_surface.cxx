#include <gtest/gtest.h>
#include <msdl_surface.hxx>

TEST(MSDL_Surface, Initialization)
{
	MSDL::Surface s;

	ASSERT_TRUE(s.is_empty());
}
