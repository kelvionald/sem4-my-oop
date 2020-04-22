#include "catch2/catch.hpp"
#include <iostream>
#include <sstream>
#include <lab4\lab4\CPoint.h>
#include <lab4\lab4\CUtils.h>
#include <lab4\lab4\CLineSegment.h>
#include <lab4\lab4\CCircle.h>
#include <lab4\lab4\CTriangle.h>
#include <lab4\lab4\CRectangle.h>
#include <lab4\lab4\Program.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <sstream>

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
	SECTION("GetDistance should returns distance between two points")
	{
		CPoint point(1, 2);
		double distance = CUtils::GetDistance(CPoint(0, 0), CPoint(1, 1));
		REQUIRE(distance == sqrt(2));
	}
	SECTION("Split should returns splitted array")
	{
		SECTION("with end space")
		{
			CPoint point(1, 2);
			auto arr = CUtils::Split("1 2 3 4 ", " ");
			REQUIRE(arr.size() == 4);
			REQUIRE(arr == vector<string>{ "1", "2", "3", "4" });
		}
		SECTION("without end space")
		{
			CPoint point(1, 2);
			auto arr = CUtils::Split("1 2 3 4", " ");
			REQUIRE(arr.size() == 4);
			REQUIRE(arr == vector<string>{ "1", "2", "3", "4" });
		}
	}
	SECTION("IsValidHexColor should validate hex string")
	{
		SECTION("length should be 6 symbols")
		{
			REQUIRE(!CUtils::IsValidHexColor("00000"));
			REQUIRE(!CUtils::IsValidHexColor("0000000"));
			REQUIRE(CUtils::IsValidHexColor("000000"));
		}
		SECTION("allows only hex chars")
		{
			REQUIRE(CUtils::IsValidHexColor("abcdef"));
			REQUIRE(CUtils::IsValidHexColor("ABCDEF"));
			REQUIRE(CUtils::IsValidHexColor("123456"));
			REQUIRE(!CUtils::IsValidHexColor("12315H"));
		}
	}
	SECTION("ParseColor should returns uint color")
	{
		REQUIRE(CUtils::ParseColor("ffffff") == 16777215);
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
		string expected = "LineSegment(Point(0.000000; 0.000000); Point(1.000000; 1.000000); 0)";
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

void testsGeneratorSolidShape(ISolidShape& solidShape, double area, double perimeter, string str, uint32_t outlineColor, uint32_t fillColor)
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
	SECTION("GetFillColor should returns fill color")
	{
		REQUIRE(solidShape.GetFillColor() == fillColor);
	}
}

TEST_CASE("CCircle")
{
	CPoint center = CPoint(0, 0);
	CCircle circle(center, 2, 1, 1);
	string expectedStr = "Circle(Point(0.000000; 0.000000); 2.000000; 1; 1)";
	testsGeneratorSolidShape(circle, M_PI * 4, 2 * M_PI * 2, expectedStr, 1, 1);
	SECTION("GetCenter should returns center")
	{
		REQUIRE(circle.GetCenter() == center);
	}
	SECTION("GetRadius should returns radius")
	{
		REQUIRE(circle.GetRadius() == 2);
	}
}

TEST_CASE("CTriangle")
{
	CPoint a(0, 0);
	CPoint b(5, 0);
	CPoint c(0, 4);
	CTriangle triangle(a, b, c, 1, 1);
	string expectedStr = "Triangle(Point(0.000000; 0.000000); Point(5.000000; 0.000000); Point(0.000000; 4.000000); 1; 1)";
	double perimeter = 4 + 5 + CUtils::GetDistance(b, c);
	testsGeneratorSolidShape(triangle, 10, perimeter, expectedStr, 1, 1);
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

TEST_CASE("CRectangle")
{
	CPoint leftTop(0, 0);
	CRectangle rectangle(leftTop, 10, 8, 1, 1);
	string expectedStr = "Rectangle(Point(0.000000; 0.000000); 10.000000; 8.000000; 1; 1)";
	testsGeneratorSolidShape(rectangle, 80, 36, expectedStr, 1, 1);
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

TEST_CASE("Program")
{
	SECTION("ReadShapes should reads shapes")
	{
		Program program;
		istringstream input("triangle 1.0 1.0 1.0 2.0 2.0 1.0 ffffff 000000\n"
							"lineSegment 1.0 1.0 1.0 2.0 ffffff");
		program.ReadShapes(input);
		SECTION("lineSegment reading")
		{
			CLineSegment* lineSegment = dynamic_cast<CLineSegment*>(program.GetShapeByIndex(1));
			REQUIRE(lineSegment->GetStartPoint() == CPoint(1, 1));
			REQUIRE(lineSegment->GetEndPoint() == CPoint(1, 2));
			REQUIRE(lineSegment->GetOutlineColor() == 16777215);
		}
	}
	SECTION("ReadLineSegment should reads lineSegment")
	{
		Program program;
		stringstream input("1.0 1.0 1.0 2.0 ffffff");
		CLineSegment* lineSegment = program.ReadLineSegment(input);
		REQUIRE(lineSegment->GetStartPoint() == CPoint(1, 1));
		REQUIRE(lineSegment->GetEndPoint() == CPoint(1, 2));
		REQUIRE(lineSegment->GetOutlineColor() == 16777215);
	}
	SECTION("ReadTriangle should reads triangle")
	{
		Program program;
		stringstream input("1.0 1.0 1.0 2.0 2.0 1.0 ffffff 000000");
		CTriangle* lineSegment = program.ReadTriangle(input);
		REQUIRE(lineSegment->GetVertex1() == CPoint(1, 1));
		REQUIRE(lineSegment->GetVertex2() == CPoint(1, 2));
		REQUIRE(lineSegment->GetVertex3() == CPoint(2, 1));
		REQUIRE(lineSegment->GetOutlineColor() == 16777215);
		REQUIRE(lineSegment->GetFillColor() == 0);
	}
	SECTION("ReadRectangle should reads rectangle")
	{
		Program program;
		stringstream input("1.0 1.0 2.0 3.0 ffffff 000000");
		CRectangle* lineSegment = program.ReadRectangle(input);
		REQUIRE(lineSegment->GetLeftTop() == CPoint(1, 1));
		REQUIRE(lineSegment->GetRightBottom() == CPoint(3, 4));
		REQUIRE(lineSegment->GetWidth() == 2);
		REQUIRE(lineSegment->GetHeight() == 3);
		REQUIRE(lineSegment->GetOutlineColor() == 16777215);
		REQUIRE(lineSegment->GetFillColor() == 0);
	}
	SECTION("ReadCircle should reads rectangle")
	{
		Program program;
		stringstream input("1.0 1.0 2.0 ffffff 000000");
		CCircle* lineSegment = program.ReadCircle(input);
		REQUIRE(lineSegment->GetCenter() == CPoint(1, 1));
		REQUIRE(lineSegment->GetRadius() == 2);
		REQUIRE(lineSegment->GetOutlineColor() == 16777215);
		REQUIRE(lineSegment->GetFillColor() == 0);
	}
}
