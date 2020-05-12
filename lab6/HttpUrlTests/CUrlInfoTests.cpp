#include "catch2/catch.hpp"
#include "lab6/CHttpUrl.h"
#include "lab6/CUrlInfo.h"
#include <iostream>
#include <sstream>

using namespace std;

string MakeUrlViewString(string const& link, string const& protocol, string const& domain,
	unsigned short port, string const& document)
{
	stringstream ss;
	ss << "URL: " << link << endl
	   << "Protocol: " << protocol << endl
	   << "Domain: " << domain << endl
	   << "Port: " << port << endl
	   << "Document: " << document << endl;
	return ss.str();
}

TEST_CASE("CUrlInfo")
{
	SECTION("correct url")
	{
		istringstream input("http://www.cplusplus.com:81/reference/regex/");
		ostringstream output;
		CUrlInfo urlInfo;

		urlInfo.ShowUrlInfo(input, output);

		string expectedOut = MakeUrlViewString("http://www.cplusplus.com:81/reference/regex/",
			"http", "www.cplusplus.com", 81, "/reference/regex/");
		REQUIRE(output.str() == expectedOut);
	}
	SECTION("correct urls")
	{
		istringstream input("http://www.cplusplus.com:81/reference/regex/\n"
							"HTTPS://localhost");
		ostringstream output;
		CUrlInfo urlInfo;

		urlInfo.ShowUrlInfo(input, output);

		string expectedOut = MakeUrlViewString("http://www.cplusplus.com:81/reference/regex/",
			"http", "www.cplusplus.com", 81, "/reference/regex/");
		expectedOut += MakeUrlViewString("https://localhost/",
			"https", "localhost", CHttpUrl::PORT_HTTPS, "/");
		REQUIRE(output.str() == expectedOut);
	}
	SECTION("incorrect url")
	{
		istringstream input("http://");
		ostringstream output;
		CUrlInfo urlInfo;

		urlInfo.ShowUrlInfo(input, output);

		REQUIRE(output.str() == "Invalid url\n");
	}
	SECTION("unexpected protocol")
	{
		istringstream input("ftp://localhost");
		ostringstream output;
		CUrlInfo urlInfo;

		urlInfo.ShowUrlInfo(input, output);

		REQUIRE(output.str() == "Undefined protocol\n");
	}
	SECTION("port out allow range")
	{
		SECTION("port 0")
		{
			istringstream input("http://localhost:0");
			ostringstream output;
			CUrlInfo urlInfo;

			urlInfo.ShowUrlInfo(input, output);

			REQUIRE(output.str() == "Incorrect port\n");
		}
		SECTION("port 65536")
		{
			istringstream input("http://localhost:65536");
			ostringstream output;
			CUrlInfo urlInfo;

			urlInfo.ShowUrlInfo(input, output);

			REQUIRE(output.str() == "Incorrect port\n");
		}
	}
}