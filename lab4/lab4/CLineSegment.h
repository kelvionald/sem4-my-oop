#pragma once
#include "IShape.h"
#include "CPoint.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint start, CPoint end, uint32_t color);
	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;
	virtual uint32_t GetOutlineColor() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	~CLineSegment();

private:
	uint32_t m_outlineColor;
	CPoint m_startPoint;
	CPoint m_endPoint;
};