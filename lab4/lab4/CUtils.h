#pragma once
#include "CPoint.h"
#include <string>
#include <vector>

namespace CUtils
{
	double GetDistance(const CPoint a, const CPoint b);
	std::vector<std::string> Split(const std::string& input);
	bool IsValidHexColor(const std::string& color);
	uint32_t ParseColor(const std::string& hexColor);
};