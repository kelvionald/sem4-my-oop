#include "CPoint.h"
#include <string>

using namespace std;

CPoint::CPoint()
{
}

CPoint::CPoint(double x, double y)
{
	m_x = x;
	m_y = y;
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}

string CPoint::ToString() const
{
	return "Point(x:" + to_string(m_x) + "; y:" + to_string(m_y) + ")";
}

bool operator==(const CPoint& a, const CPoint& b)
{
	return a.m_x == b.m_x && a.m_y == b.m_y;
}