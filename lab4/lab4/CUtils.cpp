#include "CUtils.h"
#include <algorithm>
#include <functional>
#include <regex>

using namespace std;

double CUtils::GetDistance(CPoint a, CPoint b)
{
	return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
}

vector<string> CUtils::Split(const string& input, const string& regex)
{
	std::regex re(regex);
	sregex_token_iterator first{ input.begin(), input.end(), re, -1 }, last;
	return { first, last };
}

bool CUtils::IsValidHexColor(string color)
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

uint32_t CUtils::ParseColor(string hexColor)
{
	return stoul(hexColor, nullptr, 16);
}
