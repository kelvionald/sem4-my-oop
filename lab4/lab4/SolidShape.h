#pragma once
#include "ISolidShape.h"

class SolidShape : public ISolidShape
{
public:
	SolidShape(uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() const override = 0;
	virtual double GetPerimeter() const override = 0;
	virtual std::string ToString() const override = 0;
	virtual uint32_t GetOutlineColor() const override;
	virtual uint32_t GetFillColor() const override;

protected:
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};