#include "catch2\catch.hpp"
#include "lab4\lab4\CCircle.h"
#include "lab4\lab4\CLineSegment.h"
#include "lab4\lab4\CPoint.h"
#include "lab4\lab4\CRectangle.h"
#include "lab4\lab4\CTriangle.h"
#include "lab4\lab4\Program.h"
#include <memory>

using namespace std;

TEST_CASE("Program")
{
	SECTION("ReadShapes should reads shapes")
	{
		SECTION("lineSegment reading, last is lineSegment")
		{
			Program program;
			istringstream input("triangle 1.0 1.0 1.0 2.0 2.0 1.0 ffffff 000000\n"
								"lineSegment 1.0 1.0 1.0 2.0 ffffff");
			program.ReadShapes(input);
			shared_ptr<CLineSegment> lineSegment = static_pointer_cast<CLineSegment>(program.GetShapeByIndex(1));
			REQUIRE(lineSegment->GetStartPoint() == CPoint(1, 1));
			REQUIRE(lineSegment->GetEndPoint() == CPoint(1, 2));
			REQUIRE(lineSegment->GetOutlineColor() == 16777215);
		}
		SECTION("triangle reading")
		{
			Program program;
			istringstream input("triangle 1.0 1.0 1.0 2.0 2.0 1.0 ffffff 000000");
			program.ReadShapes(input);
			shared_ptr<CTriangle> triangle = static_pointer_cast<CTriangle>(program.GetShapeByIndex(0));
			REQUIRE(triangle->GetVertex1() == CPoint(1, 1));
			REQUIRE(triangle->GetVertex2() == CPoint(1, 2));
			REQUIRE(triangle->GetVertex3() == CPoint(2, 1));
			REQUIRE(triangle->GetOutlineColor() == 16777215);
			REQUIRE(triangle->GetFillColor() == 0);
		}
		SECTION("rectangle reading")
		{
			Program program;
			istringstream input("rectangle 1.0 1.0 2.0 3.0 ffffff 000000");
			program.ReadShapes(input);
			shared_ptr<CRectangle> rectangle = static_pointer_cast<CRectangle>(program.GetShapeByIndex(0));
			REQUIRE(rectangle->GetLeftTop() == CPoint(1, 1));
			REQUIRE(rectangle->GetRightBottom() == CPoint(3, 4));
			REQUIRE(rectangle->GetWidth() == 2);
			REQUIRE(rectangle->GetHeight() == 3);
			REQUIRE(rectangle->GetOutlineColor() == 16777215);
			REQUIRE(rectangle->GetFillColor() == 0);
		}
		SECTION("circle reading")
		{
			Program program;
			istringstream input("circle 1.0 1.0 2.0 ffffff 000000");
			program.ReadShapes(input);
			shared_ptr<CCircle> circle = static_pointer_cast<CCircle>(program.GetShapeByIndex(0));
			REQUIRE(circle->GetCenter() == CPoint(1, 1));
			REQUIRE(circle->GetRadius() == 2);
			REQUIRE(circle->GetOutlineColor() == 16777215);
			REQUIRE(circle->GetFillColor() == 0);
		}
	}
	SECTION("FindWithMaxArea should returns shape with max area")
	{
		Program program;
		istringstream input("rectangle 1.0 1.0 2.0 2.0 ffffff 000000\n"
							"rectangle 1.0 1.0 2.0 3.0 ffffff 000000");
		program.ReadShapes(input);
		SECTION("lineSegment reading")
		{
			shared_ptr<CRectangle> rectangle = static_pointer_cast<CRectangle>(program.FindWithMaxArea());
			REQUIRE(rectangle->GetHeight() == 3);
		}
	}
	SECTION("FindWithMinPerimeter should returns shape with min perimeter")
	{
		Program program;
		istringstream input("rectangle 1.0 1.0 2.0 2.0 ffffff 000000\n"
							"rectangle 1.0 1.0 2.0 3.0 ffffff 000000");
		program.ReadShapes(input);
		SECTION("lineSegment reading")
		{
			shared_ptr<CRectangle> rectangle = static_pointer_cast<CRectangle>(program.FindWithMinPerimeter());
			REQUIRE(rectangle->GetHeight() == 2);
		}
	}
}