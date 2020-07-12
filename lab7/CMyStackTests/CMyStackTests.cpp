#include "lab7/CMyStack/CMyStack.h"
#include <catch2/catch.hpp>
#include <utility>
#include <string>

using namespace std;

class CMyPoint
{
	int m_x;
	int m_y;

public:
	CMyPoint(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
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
	SECTION("check work without default constructor")
	{
		CMyStack<CMyPoint> stack1;
		CMyPoint p1(123, 456);
		stack1.Push(p1);
		p1 = stack1.Pop();
		REQUIRE(stack1.IsEmpty());
		REQUIRE(p1.getX() == 123);
		REQUIRE(p1.getY() == 456);
	}
}
