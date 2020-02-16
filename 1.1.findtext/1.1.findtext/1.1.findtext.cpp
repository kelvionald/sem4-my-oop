#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: 1.1.findtext.exe <file name> <text to search>\n";
		return 1;
	}

	ifstream input(argv[1]);
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	string line;
	int lineCounter = 1;
	bool isFound = false;

	while (getline(input, line))
	{
		if (line.find(argv[2]) != string::npos)
		{
			isFound = true;
			cout << lineCounter << endl;
		}
		lineCounter++;
	}

	if (isFound)
	{
		return 0;
	}

	return 1;
}