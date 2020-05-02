#include "TestsGeneratorSolidShape.h"

using namespace std;

void TestsGeneratorSolidShape(const ISolidShape& solidShape, const double area, const double perimeter,
	const string& str, const uint32_t outlineColor, const uint32_t fillColor)
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
