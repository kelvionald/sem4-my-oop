#include "Program.h"
#include "CUtils.h"
#include <algorithm>

using namespace std;

void CheckParamsCount(string params, int requireCount)
{
	if (CUtils::Split(params).size() != requireCount)
	{
		throw exception("unexpected params count");
	}
}

stringstream ReadParams(istream& input, int requireCount)
{
	stringstream ss;
	string params;
	getline(input, params);
	CheckParamsCount(params, requireCount);
	ss << params;
	return ss;
}

void Program::ReadShapes(istream& input)
{
	while (!input.eof())
	{
		string word;
		stringstream ss;
		getline(input, word, ' ');
		if (word == "lineSegment")
		{
			ss = ReadParams(input, 5);
			m_shapes.push_back(ReadLineSegment(ss));
		}
		else if (word == "triangle")
		{
			ss = ReadParams(input, 8);
			m_shapes.push_back(ReadTriangle(ss));
		}
		else if (word == "rectangle")
		{
			ss = ReadParams(input, 6);
			m_shapes.push_back(ReadRectangle(ss));
		}
		else if (word == "circle")
		{
			ss = ReadParams(input, 5);
			m_shapes.push_back(ReadCircle(ss));
		}
	}
}

void ReadColor(stringstream& ss, string& color)
{
	ss >> color;
	if (!CUtils::IsValidHexColor(color))
	{
		throw exception("non color value");
	}
}

CLineSegment* Program::ReadLineSegment(stringstream& ss)
{
	double ax, ay, bx, by;
	string outlineColor;
	if (!(ss >> ax) || !(ss >> ay) || !(ss >> bx) || !(ss >> by))
	{
		throw exception("non double value");
	}
	ReadColor(ss, outlineColor);
	return new CLineSegment(CPoint(ax, ay), CPoint(bx, by), CUtils::ParseColor(outlineColor));
}

CTriangle* Program::ReadTriangle(stringstream& ss)
{
	double ax, ay, bx, by, cx, cy;
	string outlineColor, fillColor;
	if (!(ss >> ax) || !(ss >> ay) || !(ss >> bx) || !(ss >> by) || !(ss >> cx) || !(ss >> cy))
	{
		throw exception("non double value");
	}
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return new CTriangle(CPoint(ax, ay), CPoint(bx, by), CPoint(cx, cy),
		CUtils::ParseColor(outlineColor),
		CUtils::ParseColor(fillColor));
}

CRectangle* Program::ReadRectangle(stringstream& ss)
{
	double ax, ay, width, height;
	string outlineColor, fillColor;
	if (!(ss >> ax) || !(ss >> ay) || !(ss >> width) || !(ss >> height))
	{
		throw exception("non double value");
	}
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return new CRectangle(CPoint(ax, ay), width, height,
		CUtils::ParseColor(outlineColor),
		CUtils::ParseColor(fillColor));
}

CCircle* Program::ReadCircle(stringstream& ss)
{
	double ax, ay, radius;
	string outlineColor, fillColor;
	if (!(ss >> ax) || !(ss >> ay) || !(ss >> radius))
	{
		throw exception("non double value");
	}
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return new CCircle(CPoint(ax, ay), radius,
		CUtils::ParseColor(outlineColor),
		CUtils::ParseColor(fillColor));
}

IShape* Program::FindWithMaxArea()
{
	if (m_shapes.size())
	{
		double maxArea = m_shapes[0]->GetArea();
		int maxAreaIndex = 0;
		for (int i = 1; i < m_shapes.size(); i++)
		{
			double tempMaxArea = m_shapes[i]->GetArea();
			if (tempMaxArea > maxArea)
			{
				maxArea = tempMaxArea;
				maxAreaIndex = i;
			}
		}
		return m_shapes[maxAreaIndex];
	}
	return nullptr;
}

IShape* Program::FindWithMinPerimeter()
{
	if (m_shapes.size())
	{
		double minPerimeter = m_shapes[0]->GetPerimeter();
		int minPerimeterIndex = 0;
		for (int i = 1; i < m_shapes.size(); i++)
		{
			double tempMinPerimeter = m_shapes[i]->GetPerimeter();
			if (tempMinPerimeter < minPerimeter)
			{
				minPerimeter = tempMinPerimeter;
				minPerimeterIndex = i;
			}
		}
		return m_shapes[minPerimeterIndex];
	}
	return nullptr;
}

IShape* Program::GetShapeByIndex(int index)
{
	return m_shapes[index];
}
