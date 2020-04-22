#pragma once
#include <string>

class CPoint
{
private:
	double m_x;
	double m_y;

public:
	CPoint();
	CPoint(double x, double y);
	double GetX();
	double GetY();
	std::string ToString();
	friend bool operator==(const CPoint& a, const CPoint& b);
};