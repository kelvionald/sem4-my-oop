#pragma once
#include <string>

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};

class Port
{
public:
	static const int HTTP = 80;
	static const int HTTPS = 443;
	static const int FTP = 21;
};

bool ParseURL(std::string const& url, Protocol& protocol, int& port, std::string& host, std::string& document);
