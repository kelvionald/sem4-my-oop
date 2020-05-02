#include "catch2\catch.hpp"
#include "lab4\lab4\CPoint.h"
#include "lab4\lab4\Utils.h"

using namespace std;

TEST_CASE("Utils")
{
	SECTION("GetDistance should returns distance between two points")
	{
		CPoint point(1, 2);
		double distance = Utils::GetDistance(CPoint(0, 0), CPoint(1, 1));
		REQUIRE(distance == sqrt(2));
	}
	SECTION("Split should returns splitted array")
	{
		SECTION("with end space")
		{
			CPoint point(1, 2);
			auto arr = Utils::Split("1 2 3 4 ");
			REQUIRE(arr.size() == 4);
			REQUIRE(arr == vector<string>{ "1", "2", "3", "4" });
		}
		SECTION("without end space")
		{
			CPoint point(1, 2);
			auto arr = Utils::Split("1 2 3 4");
			REQUIRE(arr.size() == 4);
			REQUIRE(arr == vector<string>{ "1", "2", "3", "4" });
		}
		SECTION("few spaces")
		{
			CPoint point(1, 2);
			auto arr = Utils::Split("1 2 3  4   ");
			REQUIRE(arr.size() == 4);
			REQUIRE(arr == vector<string>{ "1", "2", "3", "4" });
		}
	}
	SECTION("IsValidHexColor should validate hex string")
	{
		SECTION("length should be 6 symbols")
		{
			REQUIRE(!Utils::IsValidHexColor("00000"));
			REQUIRE(!Utils::IsValidHexColor("0000000"));
			REQUIRE(Utils::IsValidHexColor("000000"));
		}
		SECTION("allows only hex chars")
		{
			REQUIRE(Utils::IsValidHexColor("abcdef"));
			REQUIRE(Utils::IsValidHexColor("ABCDEF"));
			REQUIRE(Utils::IsValidHexColor("123456"));
			REQUIRE(!Utils::IsValidHexColor("12315H"));
		}
	}
	SECTION("ParseColor should returns uint color")
	{
		REQUIRE(Utils::ParseColor("ffffff") == 16777215);
	}
}