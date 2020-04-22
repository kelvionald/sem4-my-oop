#include "catch2/catch.hpp"
#include <iostream>
#include <sstream>
#include <lab4\lab4\CPoint.h>
#include <lab4\lab4\CUtils.h>
#include <lab4\lab4\CLineSegment.h>
#include <lab4\lab4\CCircle.h>
#define _USE_MATH_DEFINES
#include <math.h>

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
		REQUIRE(point.ToString() == "Point(1.000000; 2.000000)");
	}
}

TEST_CASE("CUtils")
{
	CPoint point(1, 2);
	SECTION("GetDistance should returns distance between two points")
	{
		double distance = CUtils::GetDistance(CPoint(0, 0), CPoint(1, 1));
		REQUIRE(distance == sqrt(2));
	}
}

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
		string expected = "LineSegment(Point(0.000000; 0.000000); Point(1.000000; 1.000000))";
		REQUIRE(lineSegment.ToString() == expected);
	}
	SECTION("GetOutlineColor should returns outline color")
	{
		REQUIRE(lineSegment.GetOutlineColor() == 0);
	}
	SECTION("SetOutlineColor should set outline color")
	{
		lineSegment.SetOutlineColor(1);
		REQUIRE(lineSegment.GetOutlineColor() == 1);
	}
	SECTION("GetStartPoint should returns start point")
	{
		REQUIRE(lineSegment.GetStartPoint() == start);
	}
	SECTION("GetEndPoint should returns end point")
	{
		REQUIRE(lineSegment.GetEndPoint() == end);
	}
	CPoint newPoint(2, 2);
	SECTION("SetStartPoint should set start point")
	{
		lineSegment.SetStartPoint(newPoint);
		REQUIRE(lineSegment.GetStartPoint() == newPoint);
	}
	SECTION("SetEndPoint should set end point")
	{
		lineSegment.SetEndPoint(newPoint);
		REQUIRE(lineSegment.GetEndPoint() == newPoint);
	}
}

void testsGeneratorSolidShape(ISolidShape& solidShape, double area, double perimeter, string str, uint32_t outlineColor)
{
	SECTION("GetArea should returns area")
	{
		REQUIRE(solidShape.GetArea() == area);
	}
	SECTION("GetPerimeter should returns perimeter")
	{
		REQUIRE(solidShape.GetPerimeter() == perimeter);
	}
	SECTION("ToString should returns string value")
	{
		REQUIRE(solidShape.ToString() == str);
	}
	SECTION("GetOutlineColor should returns outline color")
	{
		REQUIRE(solidShape.GetOutlineColor() == outlineColor);
	}
	SECTION("SetOutlineColor should set outline color")
	{
		solidShape.SetOutlineColor(2);
		REQUIRE(solidShape.GetOutlineColor() == 2);
	}
}

TEST_CASE("CCircle")
{
	CCircle circle(CPoint(0, 0), 2, 1, 1);
	testsGeneratorSolidShape(circle, M_PI * 4, 2 * M_PI * 2, "Circle(Point(0.000000; 0.000000), 2.000000)", 1);
	SECTION("GetFillColor should returns fill color")
	{
		REQUIRE(circle.GetFillColor() == 1);
	}
	SECTION("SetFillColor should set fill color")
	{
		circle.SetFillColor(2);
		REQUIRE(circle.GetFillColor() == 2);
	}
}
