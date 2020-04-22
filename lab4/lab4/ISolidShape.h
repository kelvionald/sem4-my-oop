#pragma once
#include "IShape.h"
#include <cstdint>

class ISolidShape : public IShape
{
private:
	uint32_t m_fillColor;

public:
	virtual uint32_t GetFillColor() = 0;
	virtual void SetFillColor(uint32_t color) = 0;
};