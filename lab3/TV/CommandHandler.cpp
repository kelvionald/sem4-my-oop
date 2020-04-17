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
			else
			{
				output << "TV is already on\n";
			}
		}
		else if (command == "TurnOff")
		{
			if (tv.IsTurnedOn())
			{
				tv.TurnOff();
			}
			else
			{
				output << "TV is already off\n";
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
				output << "Input error\n";
				input.clear();
			}
		}
		else if (command == "Info")
		{
			output << "TV is turned " << (tv.IsTurnedOn() ? "on" : "off") << endl;
			output << "Current channel " << tv.GetChannel() << endl;
		}
		else if (command == "SelectPreviousChannel")
		{
			tv.SelectPreviousChannel();
		}
		else
		{
			output << "Undefined command" << endl;
		}
	}
}
