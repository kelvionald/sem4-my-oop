#include "CommandHandler.h"

using namespace std;

void HandleTvCommands(std::istream& input, std::ostream& output, CTVSet& tv)
{
	string command;
	while (!input.eof())
	{
		input >> command;
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
			if (input >> channel)
			{
				tv.SelectChannel(channel);
			}
			else
			{
				output << "Input error";
			}
		}
		else if (command == "Info")
		{
			output << "TV is turned " << (tv.IsTurnedOn() ? "on" : "off") << endl;
			output << "Current channel " << tv.GetChannel() << endl;
		}
		else
		{
			output << "Undefined command" << endl;
		}
	}
}
