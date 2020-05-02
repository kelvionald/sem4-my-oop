#include "catch2\catch.hpp"
#include "lab4\lab4\CPoint.h"
#include "lab4\lab4\CLineSegment.h"

using namespace std;

TEST_CASE("CLineSegment")
{
	CPoint start(0, 0);
	CPoint end(1, 1);
	CLineSegment lineSegment(start, end, 0);
	SECTION("GetArea should returns area")
	{
		REQUIRE(lineSegment.GetArea() == 0);
	}
	SECTION("GetPerimeter should returns perimeter")
	{
		REQUIRE(lineSegment.GetPerimeter() == sqrt(2));
	}
	SECTION("ToString should returns string value")
	{
		string expected = "LineSegment(Point(x:0.000000; y:0.000000); Point(x:1.000000; y:1.000000); outlineColor:0; area:0.000000; perimeter:1.414214)";
		REQUIRE(lineSegment.ToString() == expected);
	}
	SECTION("GetOutlineColor should returns outline color")
	{
		REQUIRE(lineSegment.GetOutlineColor() == 0);
	}
	SECTION("GetStartPoint should returns start point")
	{
		REQUIRE(lineSegment.GetStartPoint() == start);
	}
	SECTION("GetEndPoint should returns end point")
	{
		REQUIRE(lineSegment.GetEndPoint() == end);
	}
}