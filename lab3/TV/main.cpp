#include <iostream>
#include "CTVSet.h"
#include "CommandHandler.h"

using namespace std;

int main()
{
	CTVSet tv;
	HandleTvCommands(cin, cout, tv);
}