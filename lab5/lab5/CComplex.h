#pragma once

class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;
	CComplex operator+(const CComplex& a) const;
	CComplex operator-(const CComplex& a) const;
	CComplex operator*(const CComplex& a) const;
	CComplex operator/(const CComplex& a) const;
	CComplex operator+() const;
	CComplex operator-() const;
	CComplex operator+=(const CComplex& a);

private:
	double m_real;
	double m_image;
};

CComplex operator+(const double a, const CComplex b);
CComplex operator-(const double a, const CComplex b);
CComplex operator*(const double a, const CComplex b);
CComplex operator/(const double a, const CComplex b);