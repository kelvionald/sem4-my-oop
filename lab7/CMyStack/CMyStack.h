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
	int m_maxSize;
	T* m_stack;
	int m_size;
	void ExpandSize();
	void InitByStack(const CMyStack<T>& stack);
};

template <typename T>
inline CMyStack<T>::CMyStack()
{
	m_maxSize = m_INITIAL_SIZE;
	m_stack = new T[m_maxSize];
	m_size = 0;
}

template <typename T>
inline void CMyStack<T>::Push(T const& element)
{
	if (m_size < m_maxSize)
	{
		ExpandSize();
	}
	m_stack[m_size++] = element;
}

template <typename T>
inline T CMyStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw std::underflow_error("stack is empty");
	}
	return m_stack[--m_size];
}

template <typename T>
inline T CMyStack<T>::Top() const
{
	if (IsEmpty())
	{
		throw std::underflow_error("stack is empty");
	}
	return m_stack[m_size - 1];
}

template <typename T>
inline bool CMyStack<T>::IsEmpty() const
{
	return m_size == 0;
}

template <typename T>
inline void CMyStack<T>::Clear()
{
	m_size = 0;
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
	m_maxSize = stack.m_maxSize;
	m_size = stack.m_size;
	delete[] m_stack;
	m_stack = new T[m_maxSize];
	std::copy(stack.m_stack, stack.m_stack + m_size, m_stack);
}

template <typename T>
inline CMyStack<T>::CMyStack(CMyStack&& stack)
	: m_size(stack.m_size)
	, m_maxSize(stack.m_maxSize)
	, m_stack(std::move(stack.m_stack))
{
	stack.m_stack = nullptr;
}

template <typename T>
inline CMyStack<T>& CMyStack<T>::operator=(const CMyStack<T>&& stack)
{
	m_size(stack.m_size);
	m_maxSize(stack.m_maxSize);
	m_stack(std::move(stack.m_stack));
	stack.m_stack = nullptr;
}

template <typename T>
inline void CMyStack<T>::ExpandSize()
{
	int new_size = m_maxSize * 2;
	T* stack = new T[new_size];
	try
	{
		std::copy(m_stack, m_stack + m_maxSize, stack);
	}
	catch (std::exception& ex)
	{
		delete[] stack;
		throw ex;
	}
	delete[] m_stack;
	m_stack = stack;
}
