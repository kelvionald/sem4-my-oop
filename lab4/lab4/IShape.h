#pragma once
#include <string>

class IShape
{
public:
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	virtual std::string ToString() = 0;
	virtual uint32_t GetOutlineColor() = 0;
	virtual void SetOutlineColor(uint32_t color) = 0;
};