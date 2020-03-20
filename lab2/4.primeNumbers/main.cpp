#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

void DisplayError(string message) {
	cout << message << endl << "Usage: primeNumbers.exe <max number>\n";
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		DisplayError("Invalid arguments count");
		return 1;
	}
	int upperBound;
	stringstream ss;
	ss << argv[1];
	if (ss >> upperBound)
	{
		set<int> primes = GeneratePrimeNumbersSet(upperBound);
		for (int prime : primes)
		{
			cout << prime << ' ';
		}
		return 0;
	}
	else
	{
		DisplayError("Argument <max number> is not numeric");
		return 1;
	}
}