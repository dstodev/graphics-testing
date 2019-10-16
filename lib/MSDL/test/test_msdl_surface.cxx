#include <gtest/gtest.h>
#include <msdl_surface.hxx>

TEST(MSDL_Surface, DefaultInitialization)
{
	MSDL::Surface s;

	ASSERT_TRUE(s.is_empty());
}
