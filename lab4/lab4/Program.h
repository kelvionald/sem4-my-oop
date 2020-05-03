#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include "IShape.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"

class Program
{
public:
	void ReadShapes(std::istream& input);
	std::shared_ptr<IShape> FindWithMaxArea();
	std::shared_ptr<IShape> FindWithMinPerimeter();
	std::shared_ptr<IShape> GetShapeByIndex(int index);

private:
	std::shared_ptr<CLineSegment> ReadLineSegment(std::stringstream& ss);
	std::shared_ptr<CTriangle> ReadTriangle(std::stringstream& ss);
	std::shared_ptr<CRectangle> ReadRectangle(std::stringstream& ss);
	std::shared_ptr<CCircle> ReadCircle(std::stringstream& ss);
	std::vector<std::shared_ptr<IShape>> m_shapes;
};