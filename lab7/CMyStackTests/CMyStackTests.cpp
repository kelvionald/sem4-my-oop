#include "lab7/CMyStack/CMyStack.h"
#include <catch2/catch.hpp>

TEST_CASE("CMyStack")
{
	SECTION("IsEmpty")
	{
		CMyStack<int> stack;
		REQUIRE(stack.IsEmpty());
		stack.Push(1);
		REQUIRE(!stack.IsEmpty());
	}
	SECTION("Pop")
	{
		SECTION("not empty")
		{
			SECTION("single element")
			{
				CMyStack<int> stack;
				stack.Push(1);
				REQUIRE(!stack.IsEmpty());
				REQUIRE(stack.Pop() == 1);
				REQUIRE(stack.IsEmpty());
			}
			SECTION("few elements")
			{
				CMyStack<int> stack;
				stack.Push(1);
				stack.Push(2);
				stack.Push(3);
				REQUIRE(stack.Pop() == 3);
				REQUIRE(stack.Pop() == 2);
				REQUIRE(stack.Pop() == 1);
				REQUIRE(stack.IsEmpty());
			}
		}
		SECTION("empty")
		{
			CMyStack<int> stack;
			REQUIRE_THROWS(stack.Pop());
		}
	}
	SECTION("Top")
	{
		SECTION("not empty")
		{
			CMyStack<int> stack;
			stack.Push(1);
			REQUIRE(stack.Top() == 1);
			REQUIRE(!stack.IsEmpty());
		}
		SECTION("empty")
		{
			CMyStack<int> stack;
			REQUIRE_THROWS(stack.Top());
		}
	}
	SECTION("Clear")
	{
		SECTION("not empty")
		{
			SECTION("single element")
			{
				CMyStack<int> stack;
				stack.Push(1);
				stack.Clear();
				REQUIRE(stack.IsEmpty());
			}
			SECTION("few elements")
			{
				CMyStack<int> stack;
				stack.Push(1);
				stack.Push(2);
				stack.Push(3);
				stack.Clear();
				REQUIRE(stack.IsEmpty());
			}
		}
		SECTION("empty")
		{
			CMyStack<int> stack;
			REQUIRE(stack.IsEmpty());
			stack.Clear();
			REQUIRE(stack.IsEmpty());
		}
	}
	SECTION("CMyStack(CMyStack const& stack)")
	{
	}
}