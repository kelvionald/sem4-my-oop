#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	Frequency frequency = CalcWordFrequency(cin);
	if (frequency.empty())
	{
		cout << "No words found\n";
		return 0;
	}
	for (auto el : frequency)
	{
		cout << el.first << " -> " << el.second << endl;
	}
	return 0;
}