#include "pch.h"
#include "UrlParser.h"
#include <iostream>
#include <optional>
#include <regex>

using namespace std;

optional<Protocol> DetermineProtocol(string protocolStr)
{
	Protocol protocol;
	transform(protocolStr.begin(), protocolStr.end(), protocolStr.begin(), tolower);
	if (protocolStr == "http")
	{
		protocol = Protocol::HTTP;
	}
	else if (protocolStr == "https")
	{
		protocol = Protocol::HTTPS;
	}
	else if (protocolStr == "ftp")
	{
		protocol = Protocol::FTP;
	}
	else
	{
		return nullopt;
	}
	return protocol;
}

int DeterminePort(string portStr, Protocol& protocol)
{
	if (portStr.size())
	{
		return atoi(portStr.c_str());
	}
	switch (protocol)
	{
	case Protocol::HTTP:
		return Port::HTTP;
	case Protocol::HTTPS:
		return Port::HTTPS;
	case Protocol::FTP:
		return Port::FTP;
	default:
		throw new exception("Undefined protocol!");
	}
}

bool ParseURL(string const& url, Protocol& protocol, int& port, string& host, string& document)
{
	cmatch matchResult;
	string str = url; //"<h2> Egg prices </h2>";
	regex rx("^(.*)://([A-Za-z0-9\-\.]+)(:([0-9]+))?(/(.*))?$");
	regex_search(str.c_str(), matchResult, rx);
	int c = 0;
	if (matchResult.size() != 7)
	{
		return false;
	}
	optional<Protocol> protocolResult = DetermineProtocol(matchResult[1]);
	if (!protocolResult)
	{
		return false;
	}
	protocol = protocolResult.value();
	host = matchResult[2];
	port = DeterminePort(matchResult[4], protocol);
	document = matchResult[6];
	return true;
}
