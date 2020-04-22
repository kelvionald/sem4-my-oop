#pragma once
#include "SolidShape.h"
#include "CPoint.h"

class CTriangle : public SolidShape
{
public:
	CTriangle(CPoint a, CPoint b, CPoint c, uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() override;
	virtual double GetPerimeter() override;
	virtual std::string ToString() override;
	CPoint GetVertex1();
	CPoint GetVertex2();
	CPoint GetVertex3();

private:
	CPoint m_a;
	CPoint m_b;
	CPoint m_c;
};