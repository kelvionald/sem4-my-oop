#include "lab6/CHttpUrl.h"
#include "catch2/catch.hpp"
#include <iostream>

using namespace std;

void MakeUrlTest(CHttpUrl url, string link, Protocol protocol, string domain, 
	unsigned short port, string document)
{
	REQUIRE(url.GetURL() == link);
	REQUIRE(url.GetProtocol() == protocol);
	REQUIRE(url.GetDomain() == domain);
	REQUIRE(url.GetPort() == port);
	REQUIRE(url.GetDocument() == document);
}

TEST_CASE("CHttpUrl")
{
	SECTION("CHttpUrl(string const& url)")
	{
		SECTION("correct urls")
		{
			SECTION("protocol in capital letters (HTTP)")
			{
				string link = "HTTP://www.cplusplus.com/reference/regex/";
				CHttpUrl url(link);
				MakeUrlTest(url, "http://www.cplusplus.com/reference/regex/", Protocol::HTTP,
					"www.cplusplus.com", CHttpUrl::PORT_HTTP, "/reference/regex/");
			}
			SECTION("http url without port")
			{
				string link = "http://www.cplusplus.com/reference/regex/";
				CHttpUrl url(link);
				MakeUrlTest(url, link, Protocol::HTTP, "www.cplusplus.com", CHttpUrl::PORT_HTTP,
					"/reference/regex/");
			}
			SECTION("http url with port")
			{
				string link = "http://www.cplusplus.com:81/reference/regex/";
				CHttpUrl url(link);
				MakeUrlTest(url, link, Protocol::HTTP, "www.cplusplus.com", 81,
					"/reference/regex/");
			}
			SECTION("http url with standart port")
			{
				string link = "http://www.cplusplus.com:80/reference/regex/";
				CHttpUrl url(link);
				MakeUrlTest(url, "http://www.cplusplus.com/reference/regex/", Protocol::HTTP, 
					"www.cplusplus.com", CHttpUrl::PORT_HTTP, "/reference/regex/");
			}
			SECTION("https url without port")
			{
				string link = "https://www.cplusplus.com/reference/regex/";
				CHttpUrl url(link);
				MakeUrlTest(url, link, Protocol::HTTPS, "www.cplusplus.com", CHttpUrl::PORT_HTTPS,
					"/reference/regex/");
			}
			SECTION("without document")
			{
				string link = "http://www.cplusplus.com";
				CHttpUrl url(link);
				MakeUrlTest(url, link + "/", Protocol::HTTP, "www.cplusplus.com", 80, "/");
			}
			SECTION("domain is IP")
			{
				string link = "http://127.0.0.1";
				CHttpUrl url(link);
				MakeUrlTest(url, link + "/", Protocol::HTTP, "127.0.0.1", 80, "/");
			}
			SECTION("port in allow range")
			{
				string link = "http://127.0.0.1:1";
				CHttpUrl url(link);
				MakeUrlTest(url, link + "/", Protocol::HTTP, "127.0.0.1", 1, "/");
				link = "http://127.0.0.1:65535";
				url = CHttpUrl(link);
				MakeUrlTest(url, link + "/", Protocol::HTTP, "127.0.0.1", 65535, "/");
			}
		}
		SECTION("incorrect urls")
		{
			CHttpUrl* url;
			SECTION("unexpected protocol")
			{
				string link = "ftp://127.0.0.1/";
				REQUIRE_THROWS(url = new CHttpUrl(link));
			}
			SECTION("colon without port")
			{
				string link = "http://127.0.0.1:";
				REQUIRE_THROWS(url = new CHttpUrl(link));
			}
			SECTION("many slashes")
			{
				string link = "http:///127.0.0.1";
				REQUIRE_THROWS(url = new CHttpUrl(link));
			}
			SECTION("without protocol")
			{
				string link = "://127.0.0.1";
				REQUIRE_THROWS(url = new CHttpUrl(link));
			}
			SECTION("port out of allow range")
			{
				string link = "http://127.0.0.1:0";
				REQUIRE_THROWS(url = new CHttpUrl(link));
				link = "http://127.0.0.1:65536";
				REQUIRE_THROWS(url = new CHttpUrl(link));
			}
			SECTION("without domain")
			{
				string link = "http://";
				REQUIRE_THROWS(url = new CHttpUrl(link));
			}
		}
	}
	SECTION("CHttpUrl(string const& domain, string const& document, Protocol protocol)")
	{
		CHttpUrl* url;
		SECTION("empty domain")
		{
			REQUIRE_THROWS(url = new CHttpUrl("", "", Protocol::HTTP));
		}
		SECTION("correct domain")
		{
			CHttpUrl url("localhost", "", Protocol::HTTP);
			MakeUrlTest(url, "http://localhost/", Protocol::HTTP, "localhost", CHttpUrl::PORT_HTTP, "/");
		}
	}
	SECTION("CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)")
	{
		CHttpUrl* url;
		SECTION("empty domain")
		{
			REQUIRE_THROWS(url = new CHttpUrl("", "", Protocol::HTTP, 81));
		}
		SECTION("incorrect port")
		{
			REQUIRE_THROWS(url = new CHttpUrl("localhost", "", Protocol::HTTP, 0));
		}
		SECTION("correct port")
		{
			CHttpUrl url("localhost", "", Protocol::HTTP, 1);
			MakeUrlTest(url, "http://localhost:1/", Protocol::HTTP, "localhost", 1, "/");
			url = CHttpUrl("localhost", "", Protocol::HTTP, 65535);
			MakeUrlTest(url, "http://localhost:65535/", Protocol::HTTP, "localhost", 65535, "/");
		}
	}
}
