#include "pch.h"

void FillArray(std::istream& input, std::vector<double>& array)
{
	while (!input.eof())
	{
		double value;
		if (input >> value)
		{
			array.push_back(value);
		}
		else if (!input.eof())
		{
			throw std::exception("Non double input!");
		}
	}
}

void MultiplyOnMinimal(std::vector<double>& array)
{
	double minValue = *std::min_element(array.begin(), array.end());
	std::for_each(array.begin(), array.end(), [minValue](double& el) {
		el *= minValue;
	});
}

void DisplayArray(std::ostream& output, std::vector<double>& array)
{
	for_each(array.begin(), array.end(), [&output](double el) {
		output << el << ' ';
	});
}

void SortArray(std::vector<double>& array) {
	sort(array.begin(), array.end());
}