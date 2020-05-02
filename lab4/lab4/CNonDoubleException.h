#pragma once
#include <exception>

class CNonDoubleException : public std::exception
{
public:
	char const* what() const;
};