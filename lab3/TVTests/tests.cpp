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

TEST_CASE("TV should be turned on after use command TurnOn")
{
	istringstream input("TurnOn");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\n");
}

TEST_CASE("TV should have current channel is 1")
{
	CTVSet tv;
	istringstream input("TurnOn\nInfo");
	ostringstream output;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nTV is turned on\nCurrent channel 1\n");
}

TEST_CASE("TV should be turned off after use command TurnOff")
{
	CTVSet tv;
	istringstream input("TurnOn\nTurnOff");
	ostringstream output;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nTV is turned off\n");
}

TEST_CASE("Turned off TV should not change channel")
{
	istringstream input("SelectChannel\n5");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "Error. TV is turned off\n");
}

TEST_CASE("Turned on TV should change channel in allow range channels")
{
	istringstream input("TurnOn\nSelectChannel\n5");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nSelected channel 5\n");
}

TEST_CASE("Turned on TV should not change channel when channel out of end range")
{
	istringstream input("TurnOn\nSelectChannel\n100");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nError. Channel is out of allow range\n");
}

TEST_CASE("Turned on TV should change channel when channel allow end range")
{
	istringstream input("TurnOn\nSelectChannel\n99");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nSelected channel 99\n");
}

TEST_CASE("Turned on TV should not change channel when channel out of start range")
{
	istringstream input("TurnOn\nSelectChannel\n0");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nError. Channel is out of allow range\n");
}

TEST_CASE("Turned on TV should change channel when channel allow start range")
{
	istringstream input("TurnOn\nSelectChannel\n1");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nSelected channel 1\n");
}

TEST_CASE("Turned on TV should not change channel when input is bad")
{
	istringstream input("TurnOn\nSelectChannel\nF");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nError. Input error\nUndefined command 'F'\n");
}

TEST_CASE("Turned on TV should have channel that was before turning off")
{
	istringstream input("TurnOn\nSelectChannel\n10\nTurnOff\nTurnOn\nInfo");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nSelected channel 10\nTV is turned off\nTV is turned on\n" 
		"TV is turned on\nCurrent channel 10\n");
}

TEST_CASE("Turned on TV should not have previous channel")
{
	istringstream input("TurnOn\nSelectPreviousChannel\nInfo");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nTV is turned on\nCurrent channel 1\n");
}

TEST_CASE("Turned on TV should have previous channel after change channel")
{
	istringstream input("TurnOn\nSelectChannel\n5\nSelectPreviousChannel\nInfo");
	ostringstream output;
	CTVSet tv;
	HandleTvCommands(input, output, tv);
	REQUIRE(output.str() == "TV is turned on\nSelected channel 5\nTV is turned on\nCurrent channel 1\n");
}