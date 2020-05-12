#include "lab7/ArrayTools.h"
#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("ArraySum")
{
	SECTION("integer array")
	{
		vector<int> arr = { 1, 2, 3, 4 };
		REQUIRE(10 == ArraySum(arr));
	}
	SECTION("empty integer array")
	{
		vector<int> arr = {};
		REQUIRE(0 == ArraySum(arr));
	}

	SECTION("double array")
	{
		vector<double> arr = { 1.5, 2.5, 6 };
		REQUIRE(10.0 == ArraySum(arr));
	}
	SECTION("empty double array")
	{
		vector<double> arr = {};
		REQUIRE(0.0 == ArraySum(arr));
	}

	SECTION("string array")
	{
		vector<string> arr = { "Hello ", "world ", "!" };
		REQUIRE("Hello world !" == ArraySum(arr));
	}

	SECTION("empty string array")
	{
		vector<string> arr = {};
		REQUIRE("" == ArraySum(arr));
	}
}