#include "TestsGeneratorSolidShape.h"
#include "catch2\catch.hpp"
#include "lab4\lab4\CPoint.h"
#include "lab4\lab4\CRectangle.h"

using namespace std;

TEST_CASE("CRectangle")
{
	CPoint leftTop(0, 0);
	CRectangle rectangle(leftTop, 10, 8, 1, 1);
	string expectedStr = "Rectangle(Point(x:0.000000; y:0.000000); width:10.000000; height:8.000000; outlineColor:1; fillColor:1; area:80.000000; perimeter:36.000000)";
	TestsGeneratorSolidShape(rectangle, 80, 36, expectedStr, 1, 1);
	SECTION("GetLeftTop should returns left top point")
	{
		REQUIRE(rectangle.GetLeftTop() == leftTop);
	}
	SECTION("GetRightBottom should returns right bottom point")
	{
		CPoint rightBottom(10, 8);
		REQUIRE(rectangle.GetRightBottom() == rightBottom);
	}
	SECTION("GetWidth should returns width")
	{
		REQUIRE(rectangle.GetWidth() == 10);
	}
	SECTION("GetHeight should returns height")
	{
		REQUIRE(rectangle.GetHeight() == 8);
	}
}