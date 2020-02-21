#include "pch.h"
#include <iostream>
#include <cctype>
//#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: 2.flipbyte.exe <input byte>\n";
		return 1;
	}

	string input = argv[1];

	if (input.length() > 3)
	{
		cout << "Invalid length of input byte\n";
		return 1;
	}

	bool inputIsNumber = true;
	for (int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			inputIsNumber = false;
			break;
		}
	}

	if (!inputIsNumber)
	{
		cout << "Input is not valid positive number\n";
		return 1;
	}

	int num = atoi(input.c_str());
	if (num > 255)
	{
		cout << "Input is not byte\n";
		return 1;
	}

	int inverted = 0;
	for (int i = 0; i < 8; i++)
	{
		char bit = num & 1;
		inverted = inverted << 1;
		inverted |= bit;
		num = num >> 1;
	}
	cout << inverted << endl;

	return 0;
}