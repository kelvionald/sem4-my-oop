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
		Program program;
		istringstream input("triangle 1.0 1.0 1.0 2.0 2.0 1.0 ffffff 000000\n"
							"lineSegment 1.0 1.0 1.0 2.0 ffffff");
		program.ReadShapes(input);
		SECTION("lineSegment reading")
		{
			shared_ptr<CLineSegment> lineSegment = dynamic_pointer_cast<CLineSegment>(program.GetShapeByIndex(1));
			REQUIRE(lineSegment->GetStartPoint() == CPoint(1, 1));
			REQUIRE(lineSegment->GetEndPoint() == CPoint(1, 2));
			REQUIRE(lineSegment->GetOutlineColor() == 16777215);
		}
	}
	SECTION("ReadLineSegment should reads lineSegment")
	{
		Program program;
		stringstream input("1.0 1.0 1.0 2.0 ffffff");
		shared_ptr<CLineSegment> lineSegment = program.ReadLineSegment(input);
		REQUIRE(lineSegment->GetStartPoint() == CPoint(1, 1));
		REQUIRE(lineSegment->GetEndPoint() == CPoint(1, 2));
		REQUIRE(lineSegment->GetOutlineColor() == 16777215);
	}
	SECTION("ReadTriangle should reads triangle")
	{
		Program program;
		stringstream input("1.0 1.0 1.0 2.0 2.0 1.0 ffffff 000000");
		shared_ptr<CTriangle> lineSegment = program.ReadTriangle(input);
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
		shared_ptr<CRectangle> lineSegment = program.ReadRectangle(input);
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
		shared_ptr<CCircle> lineSegment = program.ReadCircle(input);
		REQUIRE(lineSegment->GetCenter() == CPoint(1, 1));
		REQUIRE(lineSegment->GetRadius() == 2);
		REQUIRE(lineSegment->GetOutlineColor() == 16777215);
		REQUIRE(lineSegment->GetFillColor() == 0);
	}
	SECTION("FindWithMaxArea should returns shape with max area")
	{
		Program program;
		istringstream input("rectangle 1.0 1.0 2.0 2.0 ffffff 000000\n"
							"rectangle 1.0 1.0 2.0 3.0 ffffff 000000");
		program.ReadShapes(input);
		SECTION("lineSegment reading")
		{
			shared_ptr<CRectangle> rectangle = dynamic_pointer_cast<CRectangle>(program.FindWithMaxArea());
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
			shared_ptr<CRectangle> rectangle = dynamic_pointer_cast<CRectangle>(program.FindWithMinPerimeter());
			REQUIRE(rectangle->GetHeight() == 2);
		}
	}
}