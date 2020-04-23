#pragma once

class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;

private:
	double m_real;
	double m_image;
};