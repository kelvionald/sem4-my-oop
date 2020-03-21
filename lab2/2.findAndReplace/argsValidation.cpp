#include "pch.h";
#include <iostream>

using namespace std;

optional<Args> ArgsValidate(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: findAndReplace.exe <search-string> <replace-string>\n";
		return nullopt;
	}
	Args args;
	args.search = argv[0];
	args.replace = argv[1];
	return args;
}
