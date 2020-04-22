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

double CRectangle::GetArea()
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter()
{
	return m_width * 2 + m_height * 2;
}

string CRectangle::ToString()
{
	return "Rectangle("
		+ m_leftTop.ToString() + "; "
		+ to_string(m_width) + "; "
		+ to_string(m_height) + "; "
		+ to_string(m_outlineColor) + "; "
		+ to_string(m_fillColor)
		+ ")";
}

CPoint CRectangle::GetLeftTop()
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom()
{
	return m_rightBottom;
}

double CRectangle::GetWidth()
{
	return m_width;
}

double CRectangle::GetHeight()
{
	return m_height;
}
