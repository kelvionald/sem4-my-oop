#pragma once
#include "SolidShape.h"
#include "CPoint.h"

class CCircle : public SolidShape
{
public:
	CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;
	double GetRadius() const;
	CPoint GetCenter() const;
	~CCircle();

private:
	CPoint m_center;
	double m_radius;
};