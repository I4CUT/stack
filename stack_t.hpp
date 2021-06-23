#pragma once
#include <iostream>
#include <memory>

template <typename T>
struct Elem
{
	T num;
	std::shared_ptr<Elem<T>> p;
};

template <typename T>
class Stack
{
	std::shared_ptr<Elem<T>> top;
	void reverse();

public:
	T pop();
	void push(T num);
	void show();
	void clear();
	Stack();
	Stack(const Stack<T> &other);
	~Stack();
	Stack &operator=(const Stack<T> &other);
	
};

template <typename T>
void Stack<T>::reverse()
{
	std::shared_ptr<Elem<T>> prev, cur, next;

	prev = nullptr;
	cur = top;

	while (cur != nullptr)
	{
		next = cur->p;
		cur->p = prev;
		prev = cur;
		cur = next;
	}
	top = prev;
}

template <typename T>
T Stack<T>::pop()
{
	int pop_elem = 0;
	if (top == nullptr)
	{
		std::cout << "The stack is empty!" << std::endl;
	}
	else
	{
		std::cout << "removed element - ";
		std::shared_ptr<Elem<T>> elem = top;
		pop_elem = top->num;
		top = top->p;
	}
	return pop_elem;
}

template <typename T>
void Stack<T>::push(T num)
{

	std::shared_ptr<Elem<T>> elem(new Elem<T>);
	elem->num = num;
	elem->p = top;
	top = elem;
}

template <typename T>
void Stack<T>::show()
{
	std::shared_ptr<Elem<T>> elem = top;
	while (elem != nullptr)
	{
		std::cout << elem->num << std::endl;
		elem = elem->p;
	}
	std::cout << std::endl;
}

template <typename T>
void Stack<T>::clear()
{
	while (top != nullptr)
	{
		std::shared_ptr<Elem<T>> elem = top;
		top = top->p;
	}
}

template <typename T>
Stack<T>::Stack()
{
	top = nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other)
{
	top = nullptr;
	std::shared_ptr<Elem<T>> elem = other.top;
	while (elem != nullptr)
	{
		push(elem->num);
		elem = elem->p;
	}
	reverse();
}

template <typename T>
Stack<T>::~Stack()
{
	while (top != nullptr)
	{
		std::shared_ptr<Elem<T>> elem = top;
		top = top->p;
	}
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
	clear();

	std::shared_ptr<Elem<T>> elem = other.top;
	while (elem != nullptr)
	{
		push(elem->num);
		elem = elem->p;
	}

	reverse();
	return *this;
}
