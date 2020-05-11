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

optional<int> DeterminePort(string portStr, Protocol& protocol)
{
	int port;
	if (portStr.size())
	{
		port = atoi(portStr.c_str());
		if (1 <= port && port <= 65535)
		{
			return port;
		}
		else
		{
			return nullopt;
		}
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
	string str = url;
	regex rx("^(.*)://([A-Za-z0-9\\-\\.]+)(:([0-9]+))?(/(.*))?$");
	regex_search(str.c_str(), matchResult, rx);
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
	optional<int> portResult = DeterminePort(matchResult[4], protocol);
	if (!portResult)
	{
		return false;
	}
	host = matchResult[2];
	port = portResult.value();
	document = matchResult[6];
	return true;
}
