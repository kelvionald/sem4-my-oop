#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <iostream>
#include <optional>
#include <regex>

using namespace std;

Protocol CHttpUrl::DetermineProtocol(string const& protocolStr)
{
	string protocolStrMutable = protocolStr;
	transform(protocolStrMutable.begin(), protocolStrMutable.end(), protocolStrMutable.begin(), tolower);
	if (protocolStrMutable == "http")
	{
		return Protocol::HTTP;
	}
	else if (protocolStrMutable == "https")
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw invalid_argument("Undefined protocol");
	}
}

unsigned short CHttpUrl::DeterminePort(string const& portStr, Protocol& protocol)
{
	int port;
	if (portStr.size())
	{
		port = atoi(portStr.c_str());
		if (IsCorrectPort(port))
		{
			return port;
		}
		else
		{
			throw invalid_argument("Incorrect port");
		}
	}
	return GetPortByProtocol(protocol);
}

void CHttpUrl::FillDocument(std::string const& document)
{
	if (document.empty())
	{
		m_document = "/";
	}
	else if (document[0] != '/')
	{
		m_document = "/" + document;
	}
	else
	{
		m_document = document;
	}
}

unsigned short CHttpUrl::GetPortByProtocol(Protocol protocol)
{
	switch (protocol)
	{
	case Protocol::HTTP:
		return CHttpUrl::PORT_HTTP;
	case Protocol::HTTPS:
		return CHttpUrl::PORT_HTTPS;
	default:
		throw invalid_argument("Undefined protocol");
	}
}

void CHttpUrl::SetDomain(std::string const& domain)
{
	if (domain.empty())
	{
		throw invalid_argument("Empty domain");
	}
	m_domain = domain;
}

void CHttpUrl::SetPort(unsigned short port)
{
	if (!IsCorrectPort(port))
	{
		throw invalid_argument("Incorrect port");
	}
	m_port = port;
}

bool CHttpUrl::IsCorrectPort(unsigned short port)
{
	return 1 <= port && port <= 65535;
}

CHttpUrl::CHttpUrl(std::string const& url)
{
	cmatch matchResult;
	string str = url;
	regex rx("^(.*)://([A-Za-z0-9\\-\\.]+)(:([0-9]+))?(/(.*))?$");
	regex_search(str.c_str(), matchResult, rx);
	if (matchResult.size() != 7)
	{
		throw CUrlParsingError("Invalid url");
	}
	m_protocol = DetermineProtocol(matchResult[1]);
	m_port = DeterminePort(matchResult[4], m_protocol);
	m_domain = matchResult[2];
	FillDocument(matchResult[6]);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
{
	SetDomain(domain);
	FillDocument(document);
	m_protocol = protocol;
	m_port = GetPortByProtocol(protocol);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
{
	SetDomain(domain);
	FillDocument(document);
	m_protocol = protocol;
	SetPort(port);
}

std::string CHttpUrl::GetStrProtocol(Protocol protocol) const
{
	if (protocol == Protocol::HTTP)
	{
		return "http";
	}
	else if (protocol == Protocol::HTTPS)
	{
		return "https";
	}
	throw invalid_argument("Undefined protocol");
}

bool CHttpUrl::IsPortBelongsProtocol(Protocol protocol, unsigned short port)
{
	return protocol == Protocol::HTTP && port == CHttpUrl::PORT_HTTP
		|| protocol == Protocol::HTTPS && port == CHttpUrl::PORT_HTTPS;
}

std::string CHttpUrl::GetURL() const
{
	string url = GetStrProtocol(m_protocol) + "://";
	url += m_domain;
	if (!IsPortBelongsProtocol(m_protocol, m_port))
	{
		url += ":" + to_string(m_port);
	}
	url += m_document;
	return url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}
