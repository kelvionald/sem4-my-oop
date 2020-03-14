#include "pch.h"

using namespace std;

int main()
{
	vector<float> inputArray;
	FillArray(cin, inputArray);
	MultiplyOnMinimal(inputArray);
	DisplayArray(cout, inputArray);
	cout << endl;
}
