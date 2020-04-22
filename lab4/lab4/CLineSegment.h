#pragma once
#include "IShape.h"
#include "CPoint.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint start, CPoint end, uint32_t color);
	virtual double GetArea() override;
	virtual double GetPerimeter() override;
	virtual std::string ToString() override;
	virtual uint32_t GetOutlineColor() override;
	virtual void SetOutlineColor(uint32_t outlineColor) override;
	CPoint GetStartPoint();
	CPoint GetEndPoint();
	void SetStartPoint(CPoint point);
	void SetEndPoint(CPoint point);

private:
	uint32_t m_outlineColor;
	CPoint m_startPoint;
	CPoint m_endPoint;
};