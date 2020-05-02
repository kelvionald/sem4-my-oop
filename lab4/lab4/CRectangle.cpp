#include "CRectangle.h"

using namespace std;

CRectangle::CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor)
	: SolidShape(outlineColor, fillColor)
{
	m_leftTop = leftTop;
	m_rightBottom = CPoint(leftTop.GetX() + width, leftTop.GetY() + height);
	m_width = width;
	m_height = height;
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return m_width * 2 + m_height * 2;
}

string CRectangle::ToString() const
{
	return "Rectangle("
		+ m_leftTop.ToString() + "; "
		+ "width:" + to_string(m_width) + "; "
		+ "height:" + to_string(m_height) + "; "
		+ "outlineColor:" + to_string(m_outlineColor) + "; "
		+ "fillColor:" + to_string(m_fillColor) + "; "
		+ "area:" + to_string(GetArea()) + "; "
		+ "perimeter:" + to_string(GetPerimeter())
		+ ")";
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
