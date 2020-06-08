#include "SolidShape.h"

SolidShape::SolidShape(uint32_t outlineColor, uint32_t fillColor)
{
	m_outlineColor = outlineColor;
	m_fillColor = fillColor;
}

uint32_t SolidShape::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t SolidShape::GetFillColor() const
{
	return m_fillColor;
}

SolidShape::~SolidShape()
{
}
