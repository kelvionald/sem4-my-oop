#include "argsValidation.h"
#include <string>
#include <iostream>

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace);
void FindAndReplaceStream(std::istream& input, std::ostream& output, Args args);