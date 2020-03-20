#include "pch.h"
#include <sstream>
#include <algorithm>

using namespace std;

TEST_CASE("CalcWordFrequency should return the frequency of occurrence of words")
{
	setlocale(LC_CTYPE, "rus");
	istringstream input("Apple apple apple \n\n\t  Banana apple!\t");
	Frequency expected = {
		{ "Apple", 1 },
		{ "Banana", 1 },
		{ "apple", 2 },
		{ "apple!", 1 }
	};
	Frequency frequency = CalcWordFrequency(input);
	REQUIRE(frequency == expected);

	istringstream input2(" \t \n ");
	Frequency expected2;
	Frequency frequency2 = CalcWordFrequency(input2);
	REQUIRE(frequency2 == expected2);
}