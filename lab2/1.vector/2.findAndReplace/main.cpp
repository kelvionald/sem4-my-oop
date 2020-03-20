#include "pch.h"

using namespace std;

int main(int argc, char* argv[])
{
	optional<Args> args = ArgsValidate(argc, argv);
	if (!args)
	{
		return 0;
	}
	FindAndReplaceStream(cin, cout, args.value());
}