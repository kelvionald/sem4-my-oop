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
	return "LineSegment("
		+ m_startPoint.ToString() + "; " 
		+ m_endPoint.ToString() + "; " 
		+ "outlineColor:" + to_string(m_outlineColor) + "; "
		+ "area:" + to_string(GetArea()) + "; "
		+ "perimeter:" + to_string(GetPerimeter())
		+ ")";
}

uint32_t CLineSegment::GetOutlineColor()
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint()
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint()
{
	return m_endPoint;
}
