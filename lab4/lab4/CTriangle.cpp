#include "CTriangle.h"
#include "CUtils.h"

using namespace std;

CTriangle::CTriangle(CPoint a, CPoint b, CPoint c, uint32_t outlineColor, uint32_t fillColor)
	: SolidShape(outlineColor, fillColor)
{
	m_a = a;
	m_b = b;
	m_c = c;
}

double CTriangle::GetArea()
{
	return abs((m_b.GetX() - m_a.GetX()) * (m_c.GetY() - m_a.GetY())
		- (m_c.GetX() - m_a.GetX()) * (m_b.GetY() - m_a.GetY())) / 2;
}

double CTriangle::GetPerimeter()
{
	return CUtils::GetDistance(m_a, m_b) + CUtils::GetDistance(m_b, m_c) + CUtils::GetDistance(m_c, m_a);
}

std::string CTriangle::ToString()
{
	return "Triangle("
		+ m_a.ToString() + "; "
		+ m_b.ToString() + "; "
		+ m_c.ToString() + "; "
		+ "outlineColor:" + to_string(m_outlineColor) + "; "
		+ "fillColor:" + to_string(m_fillColor) + "; "
		+ "area:" + to_string(GetArea()) + "; "
		+ "perimeter:" + to_string(GetPerimeter())
		+ ")";
}

CPoint CTriangle::GetVertex1()
{
	return m_a;
}

CPoint CTriangle::GetVertex2()
{
	return m_b;
}

CPoint CTriangle::GetVertex3()
{
	return m_c;
}
