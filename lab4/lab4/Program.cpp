#include "Program.h"
#include "CUtils.h"

using namespace std;

void CheckParamsCount(string params, int requireCount)
{
	if (CUtils::Split(params, " ").size() != requireCount)
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

CLineSegment* Program::ReadLineSegment(stringstream& ss)
{
	double ax, ay, bx, by;
	string outlineColor;
	if (!(ss >> ax) || !(ss >> ay) || !(ss >> bx) || !(ss >> by))
	{
		throw exception("non double value");
	}
	ss >> outlineColor;
	if (!CUtils::IsValidHexColor(outlineColor))
	{
		throw exception("non color value");
	}
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
	ss >> outlineColor;
	ss >> fillColor;
	if (!CUtils::IsValidHexColor(outlineColor) || !CUtils::IsValidHexColor(fillColor))
	{
		throw exception("non color value");
	}
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
	ss >> outlineColor;
	ss >> fillColor;
	if (!CUtils::IsValidHexColor(outlineColor) || !CUtils::IsValidHexColor(fillColor))
	{
		throw exception("non color value");
	}
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
	ss >> outlineColor;
	ss >> fillColor;
	if (!CUtils::IsValidHexColor(outlineColor) || !CUtils::IsValidHexColor(fillColor))
	{
		throw exception("non color value");
	}
	return new CCircle(CPoint(ax, ay), radius,
		CUtils::ParseColor(outlineColor),
		CUtils::ParseColor(fillColor));
}

IShape* Program::GetShapeByIndex(int index)
{
	return m_shapes[index];
}
