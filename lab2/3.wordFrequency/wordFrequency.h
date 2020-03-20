#pragma once
#include "pch.h"
#include <iostream>
#include <map>
#include <string>

typedef std::map<std::string, int> Frequency;

Frequency CalcWordFrequency(std::istream& input);