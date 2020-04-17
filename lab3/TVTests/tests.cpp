#include "TV/CommandHandler.h"
#include "catch2/catch.hpp"
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("TV should be turned off and channel is 0")
{
	istringstream input("Info");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned off\nCurrent channel 0\n");
}

TEST_CASE("TV should have current channel is 1")
{
	CTVSet tv;
	tv.TurnOn();
	istringstream input("Info");
	ostringstream output;
	HandleTvCommands(input, output, tv);
	cout << output.str() << endl;
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("TV should be turned on after use command TurnOn")
{
	istringstream input("TurnOn");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.IsTurnedOn());
}

TEST_CASE("TV should be turned off after use command TurnOff")
{
	istringstream input("TurnOff");
	ostringstream output;
	CTVSet tv;
	tv.TurnOn();
	HandleTvCommands(input, output, tv);
	REQUIRE(!tv.IsTurnedOn());
}

TEST_CASE("Turned off TV should not change channel")
{
	istringstream input("SelectChannel\n5");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("Turned on TV should change channel in allow range channels")
{
	istringstream input("SelectChannel\n5");
	ostringstream output;
	CTVSet tv;
	tv.TurnOn();
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("Turned on TV should not change channel when channel out of range")
{
	istringstream input("SelectChannel\n100");
	ostringstream output;
	CTVSet tv;
	tv.TurnOn();
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("Turned on TV should not change channel when input is bad")
{
	istringstream input("SelectChannel\nBADINPUT");
	ostringstream output;
	CTVSet tv;
	tv.TurnOn();
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("Turned on TV should have channel 5 after repeat turn on")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(10);
	tv.TurnOff();
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 10);
}

TEST_CASE("Turned on TV should not have previous channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectPreviousChannel();
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("Turned on TV should have previous channel after change channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(2);
	istringstream input("SelectPreviousChannel");
	ostringstream output;
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 1);
}