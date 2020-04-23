#include "SolidShape.h"

SolidShape::SolidShape(uint32_t outlineColor, uint32_t fillColor)
{
	m_outlineColor = outlineColor;
	m_fillColor = fillColor;
}

uint32_t SolidShape::GetOutlineColor()
{
	return m_outlineColor;
}

uint32_t SolidShape::GetFillColor()
{
	return m_fillColor;
}