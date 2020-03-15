#include <optional>
#include <string>

struct Args
{
	std::string search;
	std::string replace;
};

std::optional<Args> ArgsValidate(int argc, char* argv[]);