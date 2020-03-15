#include "pch.h"

void FillArray(std::istream& input, std::vector<float>& array)
{
	while (!input.eof())
	{
		float value;
		if (input >> value)
		{
			array.push_back(value);
		}
		else if (!input.eof())
		{
			throw std::exception("Non float input!");
		}
	}
}

void MultiplyOnMinimal(std::vector<float>& array)
{
	float minValue = *std::min_element(array.begin(), array.end());
	std::for_each(array.begin(), array.end(), [minValue](float& el) {
		el *= minValue;
	});
}

void DisplayArray(std::ostream& output, std::vector<float>& array)
{
	for_each(array.begin(), array.end(), [&output](float el) {
		output << el << ' ';
	});
}

void SortArray(std::vector<float>& array) {
	sort(array.begin(), array.end());
}