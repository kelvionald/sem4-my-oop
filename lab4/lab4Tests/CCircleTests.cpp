#include "catch2\catch.hpp"
#include "lab4\lab4\CCircle.h"
#include "lab4\lab4\CPoint.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "TestsGeneratorSolidShape.h"

using namespace std;

TEST_CASE("CCircle")
{
	CPoint center = CPoint(0, 0);
	CCircle circle(center, 2, 1, 1);
	string expectedStr = "Circle(Point(x:0.000000; y:0.000000); radius:2.000000; outlineColor:1; fillColor:1; area:12.566371; perimeter:12.566371)";
	TestsGeneratorSolidShape(circle, M_PI * 4, 2 * M_PI * 2, expectedStr, 1, 1);
	SECTION("GetCenter should returns center")
	{
		REQUIRE(circle.GetCenter() == center);
	}
	SECTION("GetRadius should returns radius")
	{
		REQUIRE(circle.GetRadius() == 2);
	}
}