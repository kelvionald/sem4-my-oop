#pragma once
#include <exception>

class CNonDoubleException : public std::exception
{
	char const* what() const;
};