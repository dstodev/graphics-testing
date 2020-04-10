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

	first.create_rgb(10, 10, MSDL::ColorDepth::RGB);
	// first.fill_rect(0, 0xFF, 0xFF, 0);

	second = first;

	ASSERT_FALSE(second.is_empty());
}

TEST(MSDL_Surface, CreateRGBSurface)
{
	MSDL::Surface s;

	ASSERT_TRUE(s.is_empty());
	s.create_rgb(10, 10, MSDL::ColorDepth::RGB);
	ASSERT_FALSE(s.is_empty());
}
