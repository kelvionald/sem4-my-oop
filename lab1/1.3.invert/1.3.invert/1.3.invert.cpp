#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define WIDTH 3
#define HEIGHT 3

int fillMatrix(int (*m)[HEIGHT][WIDTH], ifstream& input)
{
	int readCount = 0;
	stringstream ss;
	string line;
	for (int i = 0; i < HEIGHT; i++)
	{
		getline(input, line);
		ss << line;
		for (int j = 0; j < WIDTH; j++)
		{
			double element;
			if (ss >> element)
			{
				(*m)[i][j] = element;
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

	return readCount;
}

double calcDeterm(int (*_m)[HEIGHT][WIDTH])
{
	double determ = 0;
	auto m = *_m;
	for (int i = 0; i < WIDTH; i++)
	{
		double coef = m[0][i];
		int left = (i + 1) % 3;
		int right = (i + 2) % 3;
		int top = 1;
		int bottom = 2;
		determ = determ + coef * (m[top][left] * m[bottom][right] - m[top][right] * m[bottom][left]);
	}
	return determ;
}

void showInvertMatrix(int (*_m)[HEIGHT][WIDTH], double determ)
{
	auto m = *_m;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
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
}

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

	int m[HEIGHT][WIDTH];
	if (fillMatrix(&m, input) != HEIGHT * WIDTH)
	{
		cout << "Incorrect input format\n";
		return 1;
	}

	cout.precision(3);
	cout.setf(ios::fixed);

	double determ = calcDeterm(&m);
	if (determ == 0)
	{
		cout << "Matrix is singular\n";
		return 1;
	}

	showInvertMatrix(&m, determ);

	return 0;
}
