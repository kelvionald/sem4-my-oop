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

double CCircle::GetArea()
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter()
{
	return 2 * M_PI * m_radius;
}

string CCircle::ToString()
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

double CCircle::GetRadius()
{
	return m_radius;
}

CPoint CCircle::GetCenter()
{
	return m_center;
}
