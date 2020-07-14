#pragma once
#include <algorithm>
#include <cstdlib>
#include <memory>
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
	void InitByStack(const CMyStack<T>& stack);
	struct CItem
	{
		CItem(T v, std::shared_ptr<CItem> n)
			: value(v)
			, next(n)
		{
		}
		T value;
		std::shared_ptr<CItem> next;
	};
	typedef std::shared_ptr<CItem> PrtItem;
	PrtItem m_top;
};

template <typename T>
inline CMyStack<T>::CMyStack()
{
	m_top = nullptr;
}

template <typename T>
inline void CMyStack<T>::Push(T const& element)
{
	m_top = make_shared<CItem>(element, m_top);
}

template <typename T>
inline T CMyStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw std::underflow_error("stack is empty");
	}
	T g = m_top->value;
	m_top = m_top->next;
	return g;
}

template <typename T>
inline T CMyStack<T>::Top() const
{
	if (IsEmpty())
	{
		throw std::underflow_error("stack is empty");
	}
	return m_top->value;
}

template <typename T>
inline bool CMyStack<T>::IsEmpty() const
{
	return !m_top;
}

template <typename T>
inline void CMyStack<T>::Clear()
{
	while (!IsEmpty())
	{
		Pop();
	}
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
{}

template <typename T>
inline void CMyStack<T>::InitByStack(const CMyStack<T>& stack)
{
	CItem* donorTopItem = stack.m_top.get();
	if (!donorTopItem)
	{
		m_top = nullptr;
		return;
	}

	m_top = make_shared<CItem>(donorTopItem->value, nullptr);
	PrtItem donorCurrentItem = stack.m_top;
	PrtItem currentPtr = m_top;
	while (donorCurrentItem->next)
	{
		donorCurrentItem = donorCurrentItem->next;
		PrtItem tmp = make_shared<CItem>(donorCurrentItem->value, nullptr);
		currentPtr->next = tmp;
		currentPtr = tmp;
	};
}

template <typename T>
inline CMyStack<T>::CMyStack(CMyStack&& stack)
	: m_top(stack.m_top)
{
	stack.m_top = nullptr;
}

template <typename T>
inline CMyStack<T>& CMyStack<T>::operator=(const CMyStack<T>&& stack)
{
	m_top(stack.m_top);
	stack.m_top = nullptr;
}
