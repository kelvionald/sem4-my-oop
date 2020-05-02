#pragma once
#include <string>

class CPoint
{
public:
	CPoint();
	CPoint(double x, double y);
	double GetX() const;
	double GetY() const;
	std::string ToString() const;
	friend bool operator==(const CPoint& a, const CPoint& b);

private:
	double m_x;
	double m_y;
};