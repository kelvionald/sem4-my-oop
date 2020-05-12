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
	unsigned short GetPort()const;
	static const unsigned short PORT_HTTP = 80;
	static const unsigned short PORT_HTTPS = 443;

private:
	Protocol m_protocol;
	unsigned short m_port;
	std::string m_document;
	std::string m_domain;
	bool IsPortBelongsProtocol(Protocol protocol, unsigned short port) const;
	std::string GetStrProtocol(Protocol protocol) const;
	Protocol DetermineProtocol(std::string const& protocolStr) const;
	unsigned short DeterminePort(std::string const& portStr, Protocol& protocol) const;
	void FillDocument(std::string const& document);
	unsigned short GetPortByProtocol(Protocol protocol) const;
	void SetDomain(std::string const& domain);
	void SetPort(unsigned short port);
	bool IsCorrectPort(unsigned short port) const;
};
