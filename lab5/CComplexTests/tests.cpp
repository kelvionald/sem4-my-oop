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
	CComplex a(2, 2);
	CComplex b(1, 1);
	SECTION("binary operator +")
	{
		SECTION("2 complex sum")
		{
			CComplex c = a + b;
			REQUIRE(c.Re() == 3);
			REQUIRE(c.Im() == 3);
		}
		SECTION("complex + real")
		{
			CComplex d = a + 1;
			REQUIRE(d.Re() == 3);
			REQUIRE(d.Im() == 2);
		}
		SECTION("real + complex")
		{
			CComplex e = 1 + a;
			REQUIRE(e.Re() == 3);
			REQUIRE(e.Im() == 2);
		}
	}
	SECTION("binary operator -")
	{
		SECTION("2 complex substract")
		{
			CComplex c = a - b;
			REQUIRE(c.Re() == 1);
			REQUIRE(c.Im() == 1);
		}
		SECTION("complex - real")
		{
			CComplex d = a - 1;
			REQUIRE(d.Re() == 1);
			REQUIRE(d.Im() == 2);
		}
		SECTION("real - complex")
		{
			CComplex e = 1 - a;
			REQUIRE(e.Re() == -1);
			REQUIRE(e.Im() == -2);
		}
	}
}