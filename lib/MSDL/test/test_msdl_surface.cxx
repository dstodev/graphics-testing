#include <gtest/gtest.h>
#include <msdl_surface.hxx>


TEST(MSDL_Surface, InitializationFromDefault)
{
	MSDL::Surface s;

	ASSERT_TRUE(s.is_empty());
}

TEST(MSDL_Surface, InitializationByCopy)
{
	MSDL::Surface first;
	MSDL::Surface second(first);
}
