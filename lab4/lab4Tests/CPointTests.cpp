#include "catch2\catch.hpp"
#include "lab4\lab4\CPoint.h"

using namespace std;

TEST_CASE("CPoint")
{
	CPoint point(1, 2);
	SECTION("GetX should returns x")
	{
		REQUIRE(point.GetX() == 1);
	}
	SECTION("GetY should returns y")
	{
		REQUIRE(point.GetY() == 2);
	}
	SECTION("GetString should returns y")
	{
		REQUIRE(point.ToString() == "Point(x:1.000000; y:2.000000)");
	}
}