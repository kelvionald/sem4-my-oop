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
	std::shared_ptr<IShape> FindWithMaxArea() const;
	std::shared_ptr<IShape> FindWithMinPerimeter() const;
	std::shared_ptr<IShape> GetShapeByIndex(int index) const;

private:
	std::shared_ptr<CLineSegment> ReadLineSegment(std::stringstream& ss) const;
	std::shared_ptr<CTriangle> ReadTriangle(std::stringstream& ss) const;
	std::shared_ptr<CRectangle> ReadRectangle(std::stringstream& ss) const;
	std::shared_ptr<CCircle> ReadCircle(std::stringstream& ss) const;

	std::vector<std::shared_ptr<IShape>> m_shapes;
};