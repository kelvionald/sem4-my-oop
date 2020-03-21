#include "pch.h"
#include "primeNumbers.h"
#include <iostream>
#include <vector>

using namespace std;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	upperBound++;
	set<int> primes;
	vector<bool> numbers(upperBound, true);
	for (size_t p = 2; p < upperBound; p++)
	{
		if (numbers[p] != false)
		{
			primes.insert(p);
			for (size_t j = p * p; j < upperBound; j += p)
			{
				numbers[j] = false;
			}
		}
	}
	return primes;
}
