#pragma once
#include "SolidShape.h"
#include "CPoint.h"

class CCircle : public SolidShape
{
public:
	CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() override;
	virtual double GetPerimeter() override;
	virtual std::string ToString() override;
	double GetRadius();
	CPoint GetCenter();

private:
	CPoint m_center;
	double m_radius;
};