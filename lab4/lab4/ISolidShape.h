#pragma once
#include "IShape.h"
#include <cstdint>

class ISolidShape : public IShape
{
private:
	uint32_t m_fillColor;

public:
	virtual uint32_t GetFillColor() const = 0;
};