#include "Program.h"
#include "CNonColorException.h"
#include "CNonDoubleException.h"
#include "CParamsCountException.h"
#include "CUtils.h"
#include <algorithm>

using namespace std;

void CheckParamsCount(string params, int requireCount)
{
	if (Utils::Split(params).size() != requireCount)
	{
		throw CParamsCountException();
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
	if (!Utils::IsValidHexColor(color))
	{
		throw CNonColorException();
	}
}

void ReadDouble(double& val, stringstream& ss)
{
	if (!(ss >> val))
	{
		throw CNonDoubleException();
	}
}

void ReadPoint(CPoint& point, stringstream& ss)
{
	double x, y;
	ReadDouble(x, ss);
	ReadDouble(y, ss);
	point = CPoint(x, y);
}

CLineSegment* Program::ReadLineSegment(stringstream& ss)
{
	CPoint a, b;
	string outlineColor;
	ReadPoint(a, ss);
	ReadPoint(b, ss);
	ReadColor(ss, outlineColor);
	return new CLineSegment(a, b, Utils::ParseColor(outlineColor));
}

CTriangle* Program::ReadTriangle(stringstream& ss)
{
	CPoint a, b, c;
	string outlineColor, fillColor;
	ReadPoint(a, ss);
	ReadPoint(b, ss);
	ReadPoint(c, ss);
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return new CTriangle(a, b, c, Utils::ParseColor(outlineColor), Utils::ParseColor(fillColor));
}

CRectangle* Program::ReadRectangle(stringstream& ss)
{
	CPoint a;
	double width, height;
	string outlineColor, fillColor;
	ReadPoint(a, ss);
	ReadDouble(width, ss);
	ReadDouble(height, ss);
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return new CRectangle(a, width, height, Utils::ParseColor(outlineColor), Utils::ParseColor(fillColor));
}

CCircle* Program::ReadCircle(stringstream& ss)
{
	double ax, ay, radius;
	string outlineColor, fillColor;
	if (!(ss >> ax) || !(ss >> ay) || !(ss >> radius))
	{
		throw CNonDoubleException();
	}
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return new CCircle(CPoint(ax, ay), radius,
		Utils::ParseColor(outlineColor),
		Utils::ParseColor(fillColor));
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
