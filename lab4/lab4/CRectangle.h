#pragma once

#include "CPoint.h"
#include "SolidShape.h"

class CRectangle : public SolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
};