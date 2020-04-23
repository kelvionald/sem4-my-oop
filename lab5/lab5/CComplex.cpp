#include "CComplex.h"
#define _USE_MATH_DEFINES
#include <cmath>

CComplex::CComplex(double real, double image)
{
	m_real = real;
	m_image = image;
}

double CComplex::Re() const
{
	return m_real;
}

double CComplex::Im() const
{
	return m_image;
}

double CComplex::GetMagnitude() const
{
	return sqrt(pow(m_real, 2) + pow(m_image, 2));
}

double CComplex::GetArgument() const
{
	if (m_real == 0)
	{
		return 0;
	}
	else if (m_real > 0)
	{
		return atan(m_image / m_real);
	}
	else
	{
		if (m_image > 0)
		{
			return M_PI + atan(m_image / m_real);
		}
		else
		{
			return - M_PI + atan(m_image / m_real);
		}
	}	
}

CComplex CComplex::operator+(const CComplex& a) const
{
	return CComplex(m_real + a.Re(), m_image + a.Im());
}

CComplex CComplex::operator-(const CComplex& a) const
{
	return CComplex(m_real - a.Re(), m_image - a.Im());
}

CComplex operator+(const double a, const CComplex b)
{
	return CComplex(b.Re() + a, b.Im());
}

CComplex operator-(const double a, const CComplex b)
{
	return CComplex(a - b.Re(), - b.Im());
}
