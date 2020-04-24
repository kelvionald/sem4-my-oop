#pragma once
#include <exception>

class CParamsCountException : public std::exception
{
	char const* what() const;
};