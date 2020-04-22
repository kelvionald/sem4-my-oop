#pragma once
#include "CPoint.h"
#include <string>
#include <vector>

class CUtils
{
public:
	static double GetDistance(CPoint a, CPoint b);
	static std::vector<std::string> Split(const std::string& input, const std::string& regex);
	static bool IsValidHexColor(std::string color);
	static uint32_t ParseColor(std::string hexColor);
};