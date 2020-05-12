#include "CUrlInfo.h"
#include "CHttpUrl.h"
#include <string>

using namespace std;

void CUrlInfo::ShowUrlInfo(istream& input, ostream& output)
{
	string link;
	while (getline(input, link))
	{
		if (link.empty())
		{
			continue;
		}

		try
		{
			CHttpUrl url(link);
			output << "URL: " << url.GetURL() << endl
				 << "Protocol: " << url.GetStrProtocol(url.GetProtocol()) << endl
				 << "Domain: " << url.GetDomain() << endl
				 << "Port: " << url.GetPort() << endl
				 << "Document: " << url.GetDocument() << endl;
		}
		catch (invalid_argument& exception)
		{
			output << exception.what() << endl;
		}
	}
}
