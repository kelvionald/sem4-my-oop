#include "catch2\catch.hpp"
#include "lab4\lab4\CTriangle.h"
#include "lab4\lab4\CPoint.h"
#include "lab4\lab4\CUtils.h"
#include "TestsGeneratorSolidShape.h"

using namespace std;

TEST_CASE("CTriangle")
{
	CPoint a(0, 0);
	CPoint b(5, 0);
	CPoint c(0, 4);
	CTriangle triangle(a, b, c, 1, 1);
	string expectedStr = "Triangle(Point(x:0.000000; y:0.000000); Point(x:5.000000; y:0.000000); Point(x:0.000000; y:4.000000); outlineColor:1; fillColor:1; area:10.000000; perimeter:15.403124)";
	double perimeter = 4 + 5 + Utils::GetDistance(b, c);
	TestsGeneratorSolidShape(triangle, 10, perimeter, expectedStr, 1, 1);
	SECTION("GetVertex1 should returns vertex A")
	{
		REQUIRE(triangle.GetVertex1() == a);
	}
	SECTION("GetVertex1 should returns vertex B")
	{
		REQUIRE(triangle.GetVertex2() == b);
	}
	SECTION("GetVertex1 should returns vertex C")
	{
		REQUIRE(triangle.GetVertex3() == c);
	}
}