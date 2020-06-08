#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: SolidShape(outlineColor, fillColor)
{
	m_center = center;
	m_radius = radius;
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

string CCircle::ToString() const
{
	return "Circle(" 
		+ m_center.ToString() + "; " 
		+ "radius:" + to_string(m_radius) + "; " 
		+ "outlineColor:" + to_string(m_outlineColor) + "; "
		+ "fillColor:" + to_string(m_fillColor) + "; "
		+ "area:" + to_string(GetArea()) + "; "
		+ "perimeter:" + to_string(GetPerimeter()) 
		+ ")";
}

double CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

CCircle::~CCircle()
{
}
