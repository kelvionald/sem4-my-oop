#include "pch.h"
#include <iostream>

using namespace std;

string FindAndReplace(string const& subject, string const& search, string const& replace) {
	string::size_type lastIndex = 0;
	string result;
	string::size_type searchSize = search.size();
	if (searchSize == 0)
	{
		return subject;
	}
	string::size_type subjectSize = subject.size();
	while (true)
	{
		string::size_type index = subject.find(search, lastIndex);
		string::size_type lastPart;
		if (index != string::npos)
		{
			lastPart = index - lastIndex;
			if (lastPart > 0)
			{
				result += subject.substr(lastIndex, lastPart);
			}
			result += replace;
			lastIndex = index + searchSize;
		}
		else
		{
			if (subjectSize > lastIndex)
			{
				result += subject.substr(lastIndex, subjectSize - lastIndex);
			}
			break;
		}
	}
	
	return result;
}