#include "TV/CTVSet.h"
#include "catch2/catch.hpp"
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("CTVSet")
{
	SECTION("TV turned off")
	{
		SECTION("after init should be turned off")
		{
			CTVSet tv;
			REQUIRE_FALSE(tv.IsTurnedOn());
		}
		SECTION("cannot switch the channel")
		{
			CTVSet tv;
			REQUIRE_FALSE(tv.SelectChannel(1));
			REQUIRE(tv.GetChannel() == 0);
		}
	}
	SECTION("TV turned on")
	{
		SECTION("call TurnOn then should be turned on")
		{
			CTVSet tv;
			tv.TurnOn();
			REQUIRE(tv.IsTurnedOn());
		}
		SECTION("call SelectChannel then TV should be switch channel")
		{
			CTVSet tv;
			tv.TurnOn();
			tv.SelectChannel(1);
			REQUIRE(tv.GetChannel() == 1);
		}
		SECTION("TV should save channel after restart TV")
		{
			CTVSet tv;
			tv.TurnOn();
			tv.SelectChannel(1);
			tv.TurnOff();
			tv.TurnOn();
			REQUIRE(tv.GetChannel() == 1);
		}
		SECTION("TV allows change channels in range 1-99")
		{
			CTVSet tv;
			tv.TurnOn();
			REQUIRE(tv.SelectChannel(1));
			REQUIRE(tv.SelectChannel(99));
		}
		SECTION("TV disallows change channels in out range 1-99")
		{
			CTVSet tv;
			tv.TurnOn();
			REQUIRE_FALSE(tv.SelectChannel(0));
			REQUIRE_FALSE(tv.SelectChannel(100));
			REQUIRE(tv.GetChannel() == 1);
		}
		SECTION("call SelectPreviousChannel after turn on")
		{
			CTVSet tv;
			tv.TurnOn();
			tv.SelectPreviousChannel();
			REQUIRE(tv.GetChannel() == 1);
			tv.SelectChannel(2);
			REQUIRE(tv.GetChannel() == 2);
		}
		SECTION("call SelectPreviousChannel after change channel and restart TV")
		{
			CTVSet tv;
			tv.TurnOn();
			tv.SelectChannel(2);
			REQUIRE(tv.GetChannel() == 2);
			tv.TurnOff();
			tv.TurnOn();
			tv.SelectPreviousChannel();
			REQUIRE(tv.GetChannel() == 1);
		}
	}
}