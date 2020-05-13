#pragma once
#include <cstdlib>
#include <stdexcept>

template <typename T>
struct StackElement
{
	T value;
	StackElement* prev;
};

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
	CMyStack& operator=(const CMyStack& stack);
	//CMyStack(CMyStack const&& stack);
	//CMyStack& operator=(const CMyStack&& stack);

private:
	StackElement<T>* m_top = NULL;
};

template <typename T>
inline CMyStack<T>::CMyStack() {}

template <typename T>
inline void CMyStack<T>::Push(T const& element)
{
	StackElement<T>* top = m_top;
	m_top = new StackElement<T>;
	m_top->value = element;
	m_top->prev = top;
}

template <typename T>
inline T CMyStack<T>::Pop()
{
	if (m_top == NULL)
	{
		throw std::underflow_error("stack is empty");
	}
	T element = m_top->value;
	StackElement<T>* top = m_top;
	m_top = top->prev;
	delete top;
	return element;
}

template <typename T>
inline T CMyStack<T>::Top() const
{
	if (m_top == NULL)
	{
		throw std::underflow_error("stack is empty");
	}
	return m_top->value;
}

template <typename T>
inline bool CMyStack<T>::IsEmpty() const
{
	return m_top == NULL;
}

template <typename T>
inline void CMyStack<T>::Clear()
{
	while (m_top != NULL)
	{
		StackElement<T>* top = m_top;
		m_top = top->prev;
		delete top;
	}
}

template <typename T>
inline CMyStack<T>::CMyStack(CMyStack const& stack)
{
	m_top = stack.m_top;
}
