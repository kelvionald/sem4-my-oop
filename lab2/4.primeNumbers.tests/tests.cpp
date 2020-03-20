#include "pch.h"
#include <set>
#include <iostream>

using namespace std;

TEST_CASE("GeneratePrimeNumbersSet should return primes no more than a given number")
{
	set<int> primes = GeneratePrimeNumbersSet(13);
	set<int> expectedSet = { 2, 3, 5, 7, 11, 13 };
	REQUIRE(primes == expectedSet);

	primes = GeneratePrimeNumbersSet(100000000);
	int expectedLength = 5761455;
	REQUIRE(primes.size() == expectedLength);
}