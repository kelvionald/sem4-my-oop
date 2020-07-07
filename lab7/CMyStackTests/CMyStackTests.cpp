#include "lab7/CMyStack/CMyStack.h"
#include <catch2/catch.hpp>
#include <utility>
#include <string>
#include <stack>

using namespace std;

class CMyPoint
{
public:
	int x;
	int y;
};

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
	SECTION("auto expand size")
	{
		CMyStack<int> stack;
		for (int i = 0; i < 34; i++)
		{
			stack.Push(i);
		}
		for (int i = 33; i >= 0; i--)
		{
			REQUIRE(stack.Pop() == i);
		}
	}
	SECTION("copy constructor")
	{
		SECTION("empty")
		{
			CMyStack<int> stack1;

			CMyStack<int> stack2(stack1);

			REQUIRE(stack2.IsEmpty());
		}
		SECTION("few elements")
		{
			CMyStack<int> stack1;
			stack1.Push(1);
			stack1.Push(2);

			CMyStack<int> stack2(stack1);

			REQUIRE(!stack2.IsEmpty());
			REQUIRE(stack2.Pop() == 2);
			REQUIRE(stack2.Pop() == 1);
			REQUIRE(stack2.IsEmpty());
		}
	}
	SECTION("copy assignment")
	{
		SECTION("empty")
		{
			CMyStack<int> stack1;
			CMyStack<int> stack2;
			stack2.Push(1);
			REQUIRE(!stack2.IsEmpty());

			stack2 = stack1;

			REQUIRE(stack2.IsEmpty());
		}
		SECTION("few elements")
		{
			CMyStack<int> stack1;
			CMyStack<int> stack2;
			stack1.Push(1);
			stack1.Push(2);

			stack2 = stack1;

			REQUIRE(!stack2.IsEmpty());
			REQUIRE(stack2.Pop() == 2);
			REQUIRE(stack2.Pop() == 1);
		}
	}
	SECTION("move assignment")
	{
		CMyStack<int> stack1;
		stack1.Push(1);
		stack1.Push(2);
		CMyStack<int> stack2 = move(stack1);

		REQUIRE(!stack2.IsEmpty());
		REQUIRE(stack2.Pop() == 2);
		REQUIRE(stack2.Pop() == 1);
	}
	SECTION("move constructor")
	{
		CMyStack<int> stack1;
		stack1.Push(1);
		stack1.Push(2);
		CMyStack<int> stack2(move(stack1));

		REQUIRE(!stack2.IsEmpty());
		REQUIRE(stack2.Pop() == 2);
		REQUIRE(stack2.Pop() == 1);
	}
	SECTION("string works")
	{
		CMyStack<string> stack1;
		stack1.Push("Hello");
		stack1.Push("world");
		CMyStack<string> stack2(move(stack1));

		REQUIRE(!stack2.IsEmpty());
		REQUIRE(stack2.Pop() == "world");
		REQUIRE(stack2.Pop() == "Hello");
	}
	SECTION("default constructor")
	{
		CMyStack<CMyPoint> stack1;
		CMyPoint p1;
		p1.x = 123;
		p1.y = 456;
		stack1.Push(p1);
		p1 = stack1.Pop();
		REQUIRE(stack1.IsEmpty());
		REQUIRE(p1.x == 123);
		REQUIRE(p1.y == 456);
	}
}