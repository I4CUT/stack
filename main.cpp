#include <iostream>
#include "stack_t.hpp"

int main()
{
	Stack<char> obj1;
	obj1.push('!');
	obj1.push('h');
	obj1.push('g');
	obj1.push('a');
	obj1.push('a');
	obj1.push('a');
	obj1.push('a');
	obj1.push('w');

	std::cout << "The obj1 stack contains:" << std::endl;
	obj1.show();

	Stack<char> obj2;

	obj2.push('q');
	obj2.push('w');
	obj2.push('e');
	obj2.push('r');

	std::cout << "The obj2 stack contains:" << std::endl;
	obj2.show();

	Stack<char> obj3;

	obj3.push('q');
	obj3.push('w');
	obj3.push('e');
	obj3.push('r');
	obj3.push('t');
	obj3.push('y');
	obj3.push('u');
	obj3.push('i');
	obj3.push('o');

	std::cout << "The obj3 stack contains:" << std::endl;
	obj3.show();

	obj3 = obj2 = obj1;

	std::cout << "After operator= call, the obj2 stack contains:" << std::endl;
	obj2.show();

	std::cout << "After operator= call, the obj3 stack contains:" << std::endl;
	obj3.show();

	Stack<char> obj4(obj1);
	std::cout << "After copy constructor call, the obj4 stack contains:" << std::endl;
	obj4.show();

	obj1.clear();
	std::cout << "The obj1 stack contains:" << std::endl;
	obj1.show();

	std::cout << "The obj4 stack contains:" << std::endl;
	obj4.show();
}