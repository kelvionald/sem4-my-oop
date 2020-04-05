#include "TV/CommandHandler.h"
#include <catch2/catch.hpp>
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
	istringstream input("Info");
	ostringstream output;
	CTVSet tv;
	tv.TurnOn();
	HandleTvCommands(input, output, tv);
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

TEST_CASE("TV should not change channel when turned off")
{
	istringstream input("SelectChannel\n5");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("TV should change channel in allow range channels")
{
	istringstream input("SelectChannel\n5");
	ostringstream output;
	CTVSet tv;
	tv.TurnOn();
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("TV should not change channel when channel out of range")
{
	istringstream input("SelectChannel\n100");
	ostringstream output;
	CTVSet tv;
	tv.TurnOn();
	HandleTvCommands(input, output, tv);
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("TV should have channel 5 after repeat turn on")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(10);
	tv.TurnOff();
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 10);
}