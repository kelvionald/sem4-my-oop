#include "CNonDoubleException.h"

char const* CNonDoubleException::what() const
{
	return "non double value";
}
