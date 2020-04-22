#include <string> 
#include "CLineSegment.h"
#include "CUtils.h"

using namespace std;

CLineSegment::CLineSegment(CPoint start, CPoint end, uint32_t outlineColor)
{
	m_startPoint = start;
	m_endPoint = end;
	m_outlineColor = outlineColor;
}

double CLineSegment::GetArea()
{
	return 0;
}

double CLineSegment::GetPerimeter()
{
	return CUtils::GetDistance(m_startPoint, m_endPoint);
}

string CLineSegment::ToString()
{
	return "LineSegment(" + m_startPoint.ToString() + "; " 
		+ m_endPoint.ToString() + "; " 
		+ to_string(m_outlineColor) + ")";
}

uint32_t CLineSegment::GetOutlineColor()
{
	return m_outlineColor;
}

void CLineSegment::SetOutlineColor(uint32_t outlineColor)
{
	m_outlineColor = outlineColor;
}

CPoint CLineSegment::GetStartPoint()
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint()
{
	return m_endPoint;
}

void CLineSegment::SetStartPoint(CPoint point)
{
	m_startPoint = point;
}

void CLineSegment::SetEndPoint(CPoint point)
{
	m_endPoint = point;
}
