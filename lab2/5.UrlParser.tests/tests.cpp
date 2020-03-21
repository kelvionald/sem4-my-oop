#include "pch.h"
#include "5.UrlParser/UrlParser.h"
#include <iostream>
#include <set>

using namespace std;

TEST_CASE("GeneratePrimeNumbersSet should return primes no more than a given number")
{
	Protocol protocol;
	int port;
	string host;
	string document;

	string url = "http://www.cplusplus.com/reference/regex/";
	bool result = ParseURL(url, protocol, port, host, document);
	REQUIRE(result);
	REQUIRE(protocol == Protocol::HTTP);
	REQUIRE(port == Port::HTTP);
	REQUIRE(host == "www.cplusplus.com");
	REQUIRE(document == "reference/regex/");

	url = "https://www.cplusplus.com/reference/regex/";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(result);
	REQUIRE(protocol == Protocol::HTTPS);
	REQUIRE(port == Port::HTTPS);
	REQUIRE(host == "www.cplusplus.com");
	REQUIRE(document == "reference/regex/");

	url = "ftp://127.0.0.1/";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(result);
	REQUIRE(protocol == Protocol::FTP);
	REQUIRE(port == Port::FTP);
	REQUIRE(host == "127.0.0.1");
	REQUIRE(document == "");

	url = "FTP://127.0.0.1";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(result);
	REQUIRE(protocol == Protocol::FTP);
	REQUIRE(port == Port::FTP);
	REQUIRE(host == "127.0.0.1");
	REQUIRE(document == "");

	url = "FTP://127.0.0.1:63";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(result);
	REQUIRE(protocol == Protocol::FTP);
	REQUIRE(port == 63);
	REQUIRE(host == "127.0.0.1");
	REQUIRE(document == "");

	url = "ftp://127.0.0.1:";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(!result);

	url = "ftp:///";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(!result);

	url = "://127.0.0.1";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(!result);

	url = "127.0.0.1";
	result = ParseURL(url, protocol, port, host, document);
	REQUIRE(!result);
}
