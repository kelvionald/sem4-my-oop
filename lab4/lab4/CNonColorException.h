#pragma once
#include <exception>

class CNonColorException : public std::exception
{
	char const* what() const;
};