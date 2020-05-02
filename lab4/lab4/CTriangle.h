#pragma once
#include "SolidShape.h"
#include "CPoint.h"

class CTriangle : public SolidShape
{
public:
	CTriangle(CPoint a, CPoint b, CPoint c, uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_a;
	CPoint m_b;
	CPoint m_c;
};