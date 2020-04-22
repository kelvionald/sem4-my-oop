#pragma once

#include "CPoint.h"
#include "SolidShape.h"

class CRectangle : public SolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() override;
	virtual double GetPerimeter() override;
	virtual std::string ToString() override;
	CPoint GetLeftTop();
	CPoint GetRightBottom();
	double GetWidth();
	double GetHeight();

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
};