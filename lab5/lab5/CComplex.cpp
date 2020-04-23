#include "CComplex.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>

using namespace std;

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

CComplex CComplex::operator*(const CComplex& a) const
{
	double real = m_real * a.Re() - m_image * a.Im();
	double image = m_real * a.Im() + a.Re() * m_image;
	return CComplex(real, image);
}

CComplex CComplex::operator/(const CComplex& a) const
{
	double denominator = pow(a.Re(), 2) + pow(a.Im(), 2);
	if (denominator == 0)
	{
		throw exception("division by zero");
	}
	double real = m_real * a.Re() + m_image * a.Im();
	double image = m_image * a.Re() - m_real * a.Im();
	return CComplex(real / denominator, image / denominator);
}

CComplex CComplex::operator+() const
{
	return CComplex(m_real, m_image);
}

CComplex CComplex::operator-() const
{
	return 0 - *this;
}

CComplex CComplex::operator+=(const CComplex& a)
{
	m_real += a.Re();
	m_image += a.Im();
	return *this;
}

CComplex CComplex::operator-=(const CComplex& a)
{
	m_real -= a.Re();
	m_image -= a.Im();
	return *this;
}

CComplex CComplex::operator*=(const CComplex& a)
{
	CComplex b = *this * a;
	m_real = b.Re();
	m_image = b.Im();
	return *this;
}

CComplex CComplex::operator/=(const CComplex& a)
{
	CComplex b = *this / a;
	m_real = b.Re();
	m_image = b.Im();
	return *this;
}

CComplex operator+(const double a, const CComplex b)
{
	return CComplex(b.Re() + a, b.Im());
}

CComplex operator-(const double a, const CComplex b)
{
	return CComplex(a - b.Re(), - b.Im());
}

CComplex operator*(const double a, const CComplex b)
{
	return CComplex(a) * b;
}

CComplex operator/(const double a, const CComplex b)
{
	return CComplex(a) / b;
}
