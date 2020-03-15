#include "pch.h"

using namespace std;

TEST_CASE("FindAndReplace should find and filter all occurrences of the substring in the string")
{
	string subject = "I thought a thought. But the thought I thought wasn't the thought";
	string search = "thought";
	string replace = "hid";
	string result = FindAndReplace(subject, search, replace);
	string expected = "I hid a hid. But the hid I hid wasn't the hid";
	REQUIRE(result == expected);

	subject = "thought ";
	search = "thought";
	replace = "hid";
	result = FindAndReplace(subject, search, replace);
	expected = "hid ";
	REQUIRE(result == expected);

	subject = " thought";
	search = "thought";
	replace = "hid";
	result = FindAndReplace(subject, search, replace);
	expected = " hid";
	REQUIRE(result == expected);

	subject = "thought";
	search = "thought";
	replace = "hid";
	result = FindAndReplace(subject, search, replace);
	expected = "hid";
	REQUIRE(result == expected);

	subject = "thought";
	search = "";
	replace = "hid";
	result = FindAndReplace(subject, search, replace);
	expected = "thought";
	REQUIRE(result == expected);
}

TEST_CASE("ArgsValidate should return an argument structure")
{
	char* argv1[] = { const_cast<char*>("search"), const_cast<char*>("replace") };
	optional<Args> args = ArgsValidate(2, argv1);
	REQUIRE(args.value().search == "search");
	REQUIRE(args.value().replace == "replace");

	char* argv2[] = { const_cast<char*>("search") };
	args = ArgsValidate(1, argv2);
	REQUIRE(!args);
}