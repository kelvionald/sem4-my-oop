#include "pch.h"
#include <algorithm>
#include <sstream>

using namespace std;

TEST_CASE("CalcWordFrequency should return the frequency of occurrence of words")
{
	setlocale(LC_CTYPE, "rus");
	istringstream input("Apple apple apple \n\n\t  Banana apple!\t");
	Frequency expected = {
		{ "apple", 3 },
		{ "banana", 1 },
		{ "apple!", 1 }
	};
	Frequency frequency = CalcWordFrequency(input);
	REQUIRE(frequency == expected);

	istringstream input2(" \t \n ");
	Frequency expected2;
	Frequency frequency2 = CalcWordFrequency(input2);
	REQUIRE(frequency2 == expected2);

	istringstream input3("Привет привет Приветик Apple apple");
	Frequency expected3 = {
		{ "привет", 2 },
		{ "приветик", 1 },
		{ "apple", 2 }
	};
	Frequency frequency3 = CalcWordFrequency(input3);
	REQUIRE(frequency3 == expected3);
}
