#include "Program.h"
#include "CNonColorException.h"
#include "CNonDoubleException.h"
#include "CParamsCountException.h"
#include "Utils.h"
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

shared_ptr<CLineSegment> Program::ReadLineSegment(stringstream& ss)
{
	CPoint a, b;
	string outlineColor;
	ReadPoint(a, ss);
	ReadPoint(b, ss);
	ReadColor(ss, outlineColor);
	return shared_ptr<CLineSegment>(new CLineSegment(a, b, Utils::ParseColor(outlineColor)));
}

shared_ptr<CTriangle> Program::ReadTriangle(stringstream& ss)
{
	CPoint a, b, c;
	string outlineColor, fillColor;
	ReadPoint(a, ss);
	ReadPoint(b, ss);
	ReadPoint(c, ss);
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return shared_ptr<CTriangle>(new CTriangle(a, b, c, Utils::ParseColor(outlineColor),
		Utils::ParseColor(fillColor)));
}

shared_ptr<CRectangle> Program::ReadRectangle(stringstream& ss)
{
	CPoint a;
	double width, height;
	string outlineColor, fillColor;
	ReadPoint(a, ss);
	ReadDouble(width, ss);
	ReadDouble(height, ss);
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return shared_ptr<CRectangle>(new CRectangle(a, width, height, Utils::ParseColor(outlineColor),
		Utils::ParseColor(fillColor)));
}

shared_ptr<CCircle> Program::ReadCircle(stringstream& ss)
{
	double ax, ay, radius;
	string outlineColor, fillColor;
	if (!(ss >> ax) || !(ss >> ay) || !(ss >> radius))
	{
		throw CNonDoubleException();
	}
	ReadColor(ss, outlineColor);
	ReadColor(ss, fillColor);
	return shared_ptr<CCircle>(new CCircle(CPoint(ax, ay), radius,
		Utils::ParseColor(outlineColor),
		Utils::ParseColor(fillColor)));
}

shared_ptr<IShape> Program::FindWithMaxArea()
{
	if (m_shapes.size())
	{
		auto element = max_element(m_shapes.begin(), m_shapes.end(), [](shared_ptr<IShape> a, shared_ptr<IShape> b) {
			return a->GetArea() < b->GetArea();
		});
		return *element;
	}
	return nullptr;
}

shared_ptr<IShape> Program::FindWithMinPerimeter()
{
	if (m_shapes.size())
	{
		auto element = min_element(m_shapes.begin(), m_shapes.end(), [](shared_ptr<IShape> a, shared_ptr<IShape> b) {
			return a->GetPerimeter() < b->GetPerimeter();
		});
		return *element;
	}
	return nullptr;
}

shared_ptr<IShape> Program::GetShapeByIndex(int index)
{
	return m_shapes[index];
}
