#include "pch.h"
#include <sstream>
#include "1.vector/arrayProcessor.h"

using namespace std;

TEST_CASE("FillArray should fill an array from input stream")
{
	istringstream input("2 3.1 4 5");
	vector<double> array;
	FillArray(input, array);
	vector<double> expected{ 2, 3.1, 4, 5 };
	REQUIRE(array == expected);
	array.clear();
}

TEST_CASE("FillArray should throw exception on non double input")
{
	istringstream input("2.2 a 5");
	vector<double> array;
	REQUIRE_THROWS(FillArray(input, array));
}

TEST_CASE("MultiplyOnMinimal should multiply the array by the minimum")
{
	vector<double> array{ 2, 3.2, 4, 5 };
	MultiplyOnMinimal(array);
	vector<double> expected{ 4, 6.4, 8, 10 };
	REQUIRE(array == expected);

	array = { 0, 3, 4, 5 };
	MultiplyOnMinimal(array);
	expected = { 0, 0, 0, 0 };
	REQUIRE(array == expected);

	array = { -1, 2, 3, 4, 5 };
	MultiplyOnMinimal(array);
	expected = { 1, -2, -3, -4, -5 };
	REQUIRE(array == expected);
}

TEST_CASE("DisplayArray should displays array")
{
	ostringstream output;
	vector<double> array{ 4, 6, 8, 10.1 };
	DisplayArray(output, array);
	REQUIRE(output.str() == "4 6 8 10.1 ");
}

TEST_CASE("SortArray should sort array")
{
	vector<double> array{ 6, 2, 3.2, 2.3 };
	vector<double> expected{ 2, 2.3, 3.2, 6 };
	SortArray(array);
	REQUIRE(array == expected);
}
