#include "CUtils.h"

double CUtils::GetDistance(CPoint a, CPoint b)
{
	return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
}
