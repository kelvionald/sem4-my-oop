#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: 1.3.invert.exe <matrix file>\n";
		return 1;
	}

	string matrixFile = argv[1];
	ifstream input(matrixFile);
	if (!input.is_open())
	{
		cout << "Failed to open '" << matrixFile << "' for reading\n";
		return 1;
	}

	int m[3][3];
	int readCount = 0;
	stringstream ss;
	string line;
	for (int i = 0; i < 3; i++)
	{
		getline(input, line);
		ss << line;
		for (int j = 0; j < 3; j++)
		{
			double element;
			if (ss >> element)
			{
				m[i][j] = element;
				readCount++;
			}
			else
			{
				cout << "Incorrect double value on line " << i + 1 << "\n";
				return 1;
			}
			if (ss.eof())
			{
				break;
			}
		}
		ss.clear();
		if (input.peek() == EOF)
		{
			break;
		}
	}

	if (readCount != 9)
	{
		cout << "Incorrect input format\n";
		return 1;
	}

	cout.precision(3);
	cout.setf(ios::fixed);

	double determ = 0;
	for (int i = 0; i < 3; i++)
	{
		double coef = m[0][i];
		int left = (i + 1) % 3;
		int right = (i + 2) % 3;
		int top = 1;
		int bottom = 2;
		determ = determ + coef * (m[top][left] * m[bottom][right] - m[top][right] * m[bottom][left]);
	}

	if (determ == 0)
	{
		cout << "Matrix is singular\n";
		return 1;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int top = (j + 1) % 3;
			int bottom = (j + 2) % 3;
			int left = (i + 1) % 3;
			int right = (i + 2) % 3;
			cout << ((m[top][left] * m[bottom][right]) - (m[top][right] * m[bottom][left])) / determ;
			if (j < 2)
			{
				cout << "\t";
			}
		}
		cout << endl;
	}

	return 0;
}

