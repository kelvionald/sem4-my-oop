#pragma once
#include <exception>

class CParamsCountException : public std::exception
{
public:
	char const* what() const;
};