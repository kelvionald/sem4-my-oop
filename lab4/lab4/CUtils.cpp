#include "CUtils.h"
#include <algorithm>
#include <functional>
#include <regex>
#include <sstream>
#include <iostream>

using namespace std;

namespace Utils
{
	double GetDistance(const CPoint a, const CPoint b)
	{
		return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
	}

	vector<string> Split(const string& input)
	{
		stringstream ss;
		ss << input;
		vector<string> arr;
		while (!ss.eof())
		{
			string word;
			getline(ss, word, ' ');
			if (word.length())
			{
				arr.push_back(word);
			}
		}
		return arr;
	}

	bool IsValidHexColor(const string& color)
	{
		if (color.length() != 6)
		{
			return false;
		}
		for (int i = 0; i < color.length(); i++)
		{
			char ch = color[i];
			if (!(isdigit(ch) || 'A' <= ch && ch <= 'F' || 'a' <= ch && ch <= 'f'))
			{
				return false;
			}
		}
		return true;
	}

	uint32_t ParseColor(const string& hexColor)
	{
		return stoul(hexColor, nullptr, 16);
	}
}