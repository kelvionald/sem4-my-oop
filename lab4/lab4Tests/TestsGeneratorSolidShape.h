#pragma once

#include "catch2\catch.hpp"
#include "lab4\lab4\ISolidShape.h"
#include <string>

void TestsGeneratorSolidShape(const ISolidShape& solidShape, const double area, const double perimeter,
	const std::string& str, const uint32_t outlineColor, const uint32_t fillColor);