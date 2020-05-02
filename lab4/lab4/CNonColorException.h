#pragma once
#include <exception>

class CNonColorException : public std::exception
{
public:
	char const* what() const override;
};