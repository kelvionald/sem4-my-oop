#pragma once
#include <numeric>
#include <string>
#include <vector>

template <typename T>
T ArraySum(std::vector<T> const& arr);

template <>
std::string ArraySum<std::string>(std::vector<std::string> const& arr);

template <typename T>
T ArraySum(std::vector<T> const& arr)
{
	if (arr.empty())
	{
		return T();
	}
	T initial = 0;
	return std::accumulate(arr.begin(), arr.end(), initial);
}

template <>
std::string ArraySum<std::string>(std::vector<std::string> const& arr)
{
	if (arr.empty())
	{
		return std::string();
	}
	std::string initial = "";
	return std::accumulate(arr.begin(), arr.end(), initial);
}