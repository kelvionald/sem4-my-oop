#pragma once
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class CMyStack
{
public:
	CMyStack();
	void Push(T const& element);
	T Pop();
	T Top() const;
	bool IsEmpty() const;
	void Clear();
	CMyStack(CMyStack const& stack);
	CMyStack<T>& operator=(const CMyStack<T>& stack);
	CMyStack(CMyStack&& stack);
	CMyStack<T>& operator=(const CMyStack<T>&& stack);
	~CMyStack();

private:
	const int m_INITIAL_SIZE = 32;
	int m_size = m_INITIAL_SIZE;
	T* m_stack = new T[m_INITIAL_SIZE];
	int m_current = 0;
	void ExpandSize();
	void InitByStack(const CMyStack<T>& stack);
};

template <typename T>
inline CMyStack<T>::CMyStack() {}

template <typename T>
inline void CMyStack<T>::Push(T const& element)
{
	if (m_current < m_size)
	{
		ExpandSize();
	}
	m_stack[m_current++] = element;
}

template <typename T>
inline T CMyStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw std::underflow_error("stack is empty");
	}
	return m_stack[--m_current];
}

template <typename T>
inline T CMyStack<T>::Top() const
{
	if (IsEmpty())
	{
		throw std::underflow_error("stack is empty");
	}
	return m_stack[m_current - 1];
}

template <typename T>
inline bool CMyStack<T>::IsEmpty() const
{
	return m_current == 0;
}

template <typename T>
inline void CMyStack<T>::Clear()
{
	m_current = 0;
}

template <typename T>
inline CMyStack<T>::CMyStack(CMyStack const& stack)
{
	InitByStack(stack);
}

template <typename T>
inline CMyStack<T>& CMyStack<T>::operator=(const CMyStack<T>& stack)
{
	if (&stack == this)
	{
		return *this;
	}
	InitByStack(stack);
	return *this;
}

template <typename T>
inline CMyStack<T>::~CMyStack()
{
	delete[] m_stack;
}

template <typename T>
inline void CMyStack<T>::InitByStack(const CMyStack<T>& stack)
{
	m_size = stack.m_size;
	m_current = stack.m_current;
	delete[] m_stack;
	m_stack = new T[m_size];
	std::copy(stack.m_stack, stack.m_stack + m_current, m_stack);
}

template <typename T>
inline CMyStack<T>::CMyStack(CMyStack&& stack)
	: m_current(stack.m_current)
	, m_size(stack.m_size)
	, m_stack(stack.m_stack)
{
	stack.m_current = 0;
	stack.m_stack = nullptr;
	stack.m_size = m_INITIAL_SIZE;
}

template <typename T>
inline CMyStack<T>& CMyStack<T>::operator=(const CMyStack<T>&& stack)
{
	m_current(stack.m_current);
	m_size(stack.m_size);
	m_stack(stack.m_stack);
	stack.m_current = 0;
	stack.m_stack = nullptr;
	stack.m_size = m_INITIAL_SIZE;
}

template <typename T>
inline void CMyStack<T>::ExpandSize()
{
	int new_size = m_size * 2;
	T* stack = new T[new_size];
	std::copy(m_stack, m_stack + m_size, stack);
	delete[] m_stack;
	m_stack = stack;
}
