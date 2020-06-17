#pragma once
#include <string>

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = HTTP);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);
	std::string GetURL()const;
	std::string GetDomain()const;
	std::string GetDocument()const;
	Protocol GetProtocol()const;
	unsigned short GetPort() const;
	std::string GetStrProtocol(Protocol protocol) const;
	static const unsigned short PORT_HTTP = 80;
	static const unsigned short PORT_HTTPS = 443;

private:
	Protocol m_protocol;
	unsigned short m_port;
	std::string m_document;
	std::string m_domain;

	static bool IsPortBelongsProtocol(Protocol protocol, unsigned short port);
	static Protocol DetermineProtocol(std::string const& protocolStr);
	static unsigned short DeterminePort(std::string const& portStr, Protocol& protocol);
	void FillDocument(std::string const& document);
	static unsigned short GetPortByProtocol(Protocol protocol);
	void SetDomain(std::string const& domain);
	void SetPort(int port);
	static bool IsCorrectPort(int port);
};
