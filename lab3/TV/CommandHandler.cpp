#include "CommandHandler.h"

using namespace std;

void HandleTvCommands(std::istream& input, std::ostream& output, CTVSet& tv)
{
	string command;
	while (true)
	{
		cin >> command;
		if (command == "TurnOn")
		{
			if (!tv.IsTurnedOn())
			{
				tv.TurnOn();
			}
		}
		else if (command == "TurnOff")
		{
			if (tv.IsTurnedOn())
			{
				tv.TurnOff();
			}
		}
		else if (command == "SelectChannel")
		{
			int channel;
			if (cin >> channel)
			{
				tv.SelectChannel(channel);
			}
			else
			{
				cout << "Input error";
			}
		}
		else if (command == "Info")
		{
			if (tv.IsTurnedOn())
			{
				cout << "TV is turned on" << endl;
			}
			else
			{
				cout << "TV is turned off" << endl;
			}
			cout << "Current channel " << tv.GetChannel() << endl;
		}
	}
}
