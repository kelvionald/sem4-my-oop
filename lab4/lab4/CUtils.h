#pragma once
#include "CPoint.h"
#include <string>
#include <vector>

namespace CUtils
{
	double GetDistance(CPoint a, CPoint b);
	std::vector<std::string> Split(const std::string& input);
	bool IsValidHexColor(std::string color);
	uint32_t ParseColor(std::string hexColor);
};