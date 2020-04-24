#include "CParamsCountException.h"

char const* CParamsCountException::what() const
{
	return "Unexpected params count";
}
