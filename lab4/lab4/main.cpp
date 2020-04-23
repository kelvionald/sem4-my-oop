#include <iostream>
#include "Program.h"

using namespace std;

int main()
{
	Program program;
	try
	{
		program.ReadShapes(cin);
		IShape* bigAreaShape = program.FindWithMaxArea();
		IShape* smallPerimeterShape = program.FindWithMinPerimeter();
		if (bigAreaShape != nullptr)
		{
			cout << "Shape with max area: " << bigAreaShape->ToString() << endl;
		}
		else
		{
			cout << "Shape with max area not found" << endl;
		}
		if (smallPerimeterShape != nullptr)
		{
			cout << "Shape with min perimeter: " << smallPerimeterShape->ToString() << endl;
		}
		else
		{
			cout << "Shape with min perimeter not found" << endl;
		}
	} 
	catch (exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
}