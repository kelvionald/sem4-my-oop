#include "pch.h"
#include "wordFrequency.h"
#include <algorithm>

using namespace std;

Frequency CalcWordFrequency(istream& input)
{
	Frequency frequency;
	while (!input.eof())
	{
		string word;
		input >> word;
		if (word[0] != '\0')
		{
			transform(word.begin(), word.end(), word.begin(), tolower);
			frequency[word]++;
		}
	}
	return frequency;
}
