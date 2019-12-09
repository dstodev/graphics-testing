#include <gtest/gtest.h>
#include <msdl_surface.hxx>


TEST(MSDL_Surface, InitializationFromDefault)
{
	MSDL::Surface s;

	ASSERT_TRUE(s.is_empty());
	ASSERT_EQ(s.get_format(), nullptr);
}

TEST(MSDL_Surface, InitializationByCopy)
{
	MSDL::Surface first;
	MSDL::Surface second(first);
}

TEST(MSDL_Surface, OperatorEquals)
{
	MSDL::Surface first;
	MSDL::Surface second;

	first.fill_rect(0, 0xFF, 0xFF, 0);

	second = first;

	ASSERT_FALSE(second.is_empty());
}
