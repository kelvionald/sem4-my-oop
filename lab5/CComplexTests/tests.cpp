#include "catch2/catch.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "lab5/lab5/CComplex.h"

using namespace std;

TEST_CASE("CComplex")
{
	CComplex complex(-1, 2);
	SECTION("Re should returns real number")
	{
		REQUIRE(complex.Re() == -1);
	}
	SECTION("Im should returns imaginary number")
	{
		REQUIRE(complex.Im() == 2);
	}
	SECTION("GetMagnitude should returns magnitude")
	{
		REQUIRE(complex.GetMagnitude() == sqrt(5));
	}
	SECTION("GetArgument should returns argument")
	{
		SECTION("I coordinate quarter")
		{
			CComplex complex(1, 2);
			REQUIRE(complex.GetArgument() == atan(2));
		}
		SECTION("II coordinate quarter")
		{
			REQUIRE(complex.GetArgument() == M_PI + atan(-2));
		}
		SECTION("III coordinate quarter")
		{
			CComplex complex(-1, -2);
			REQUIRE(complex.GetArgument() == - M_PI + atan(2));
		}
		SECTION("IV coordinate quarter")
		{
			CComplex complex(1, -2);
			REQUIRE(complex.GetArgument() == atan(-2));
		}
	}
}