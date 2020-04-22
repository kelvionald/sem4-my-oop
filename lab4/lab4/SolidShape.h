#pragma once
#include "ISolidShape.h"

class SolidShape : public ISolidShape
{
public:
	SolidShape(uint32_t outlineColor, uint32_t fillColor);
	virtual double GetArea() override = 0;
	virtual double GetPerimeter() override = 0;
	virtual std::string ToString() override = 0;
	virtual uint32_t GetOutlineColor() override;
	virtual uint32_t GetFillColor() override;

protected:
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};