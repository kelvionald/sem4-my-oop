#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "IShape.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"

class Program
{
public:
	void ReadShapes(std::istream& input);
	CLineSegment* ReadLineSegment(std::stringstream& ss);
	CTriangle* ReadTriangle(std::stringstream& ss);
	CRectangle* ReadRectangle(std::stringstream& ss);
	CCircle* ReadCircle(std::stringstream& ss);
	IShape* FindWithMaxArea();
	IShape* FindWithMinPerimeter();
	IShape* GetShapeByIndex(int index);

private:
	std::vector<IShape*> m_shapes;
};