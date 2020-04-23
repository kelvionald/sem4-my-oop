#include "catch2/catch.hpp"
#define _USE_MATH_DEFINES
#include "lab5/lab5/CComplex.h"
#include <iostream>
#include <math.h>

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
			REQUIRE(complex.GetArgument() == -M_PI + atan(2));
		}
		SECTION("IV coordinate quarter")
		{
			CComplex complex(1, -2);
			REQUIRE(complex.GetArgument() == atan(-2));
		}
	}
	const CComplex a(2, 2);
	const CComplex b(1, 1);
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
	SECTION("operator *")
	{
		SECTION("2 complex multiplication")
		{
			CComplex c = a * b;
			REQUIRE(c.Re() == 0);
			REQUIRE(c.Im() == 4);
		}
		SECTION("complex * real")
		{
			CComplex d = a * 1;
			REQUIRE(d.Re() == 2);
			REQUIRE(d.Im() == 2);
		}
		SECTION("real * complex")
		{
			CComplex e = 1 * a;
			REQUIRE(e.Re() == 2);
			REQUIRE(e.Im() == 2);
		}
		SECTION("real * complex")
		{
			CComplex e = 2 * a;
			REQUIRE(e.Re() == 4);
			REQUIRE(e.Im() == 4);
		}
	}
	SECTION("operator /")
	{
		SECTION("2 complex division")
		{
			CComplex c = a / b;
			REQUIRE(c.Re() == 2);
			REQUIRE(c.Im() == 0);
		}
		SECTION("complex / real")
		{
			CComplex d = a / 1;
			REQUIRE(d.Re() == 2);
			REQUIRE(d.Im() == 2);
		}
		SECTION("real / complex")
		{
			CComplex e = 1 / a;
			REQUIRE(e.Re() == 0.25);
			REQUIRE(e.Im() == -0.25);
		}
		SECTION("complex / 0")
		{
			REQUIRE_THROWS(a / 0);
		}
	}
	SECTION("unary operator +")
	{
		CComplex c = +a;
		REQUIRE(c.Re() == 2);
		REQUIRE(c.Im() == 2);
	}
	SECTION("unary operator -")
	{
		CComplex c = -a;
		REQUIRE(c.Re() == -2);
		REQUIRE(c.Im() == -2);
	}
	SECTION("operator +=")
	{
		SECTION("complex += complex")
		{
			CComplex c = a;
			c += b;
			REQUIRE(c.Re() == 3);
			REQUIRE(c.Im() == 3);
		}
		SECTION("complex += real")
		{
			CComplex c = a;
			c += 1;
			REQUIRE(c.Re() == 3);
			REQUIRE(c.Im() == 2);
		}
	}
	SECTION("operator -=")
	{
		SECTION("complex -= complex")
		{
			CComplex c = a;
			c -= b;
			REQUIRE(c.Re() == 1);
			REQUIRE(c.Im() == 1);
		}
		SECTION("complex -= real")
		{
			CComplex c = a;
			c -= 1;
			REQUIRE(c.Re() == 1);
			REQUIRE(c.Im() == 2);
		}
	}
	SECTION("operator *=")
	{
		SECTION("complex *= complex")
		{
			CComplex c = a;
			c *= b;
			REQUIRE(c.Re() == 0);
			REQUIRE(c.Im() == 4);
		}
		SECTION("complex *= real")
		{
			CComplex c = a;
			c *= 2;
			REQUIRE(c.Re() == 4);
			REQUIRE(c.Im() == 4);
		}
	}
	SECTION("operator /=")
	{
		SECTION("complex /= complex")
		{
			CComplex c = a;
			c /= b;
			REQUIRE(c.Re() == 2);
			REQUIRE(c.Im() == 0);
		}
		SECTION("complex /= real")
		{
			CComplex c = a;
			c /= 2;
			REQUIRE(c.Re() == 1);
			REQUIRE(c.Im() == 1);
		}
		SECTION("complex /= 0")
		{
			CComplex c = a;
			REQUIRE_THROWS(c /= 0);
		}
	}
	SECTION("operator ==")
	{
		SECTION("complex == complex")
		{
			REQUIRE(a == a);
			REQUIRE(!(a == b));
		}
		CComplex c(1, 0);
		SECTION("complex == real")
		{
			REQUIRE(!(a == 1));
			REQUIRE(c == 1);
		}
		SECTION("real == complex")
		{
			REQUIRE(!(1 == a));
			REQUIRE(1 == c);
		}
	}
}