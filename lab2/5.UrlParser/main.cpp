#include "pch.h"
#include <iostream>
#include <string>
#include "UrlParser.h"

using namespace std;

int main()
{
	Protocol protocol;
	int port;
	string host;
	string document;

	string url;
	while (getline(cin, url))
	{
		if (ParseURL(url, protocol, port, host, document))
		{
			cout << url << endl;
			cout << "HOST: " << host << endl;
			cout << "PORT: " << port << endl;
			cout << "DOC: " << document << endl;
		}
	}
}