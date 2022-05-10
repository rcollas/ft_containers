#include "Stack.hpp"
#include <iostream>
#include <list>

#include <compare>
#include <iterator>
#include <vector>
#include "ReverseIterator.hpp"

int main() {

	ft::stack<int> foo;
	ft::stack<int> bar;
	std::cout << std::boolalpha;
	std::cout << foo.empty() << std::endl;
	std::cout << foo.size() << std::endl;
	foo.push(10);
	std::cout << foo.size() << std::endl;
	std::cout << (foo == bar) << std::endl;

	ft::stack<float, std::list<float> > fizz;
	fizz.push(10);
	std::cout << fizz.top() << std::endl;
	fizz.push(5);
	fizz.push(-10);
	fizz.push(1230);
	fizz.push(-2304);
	std::cout << fizz.top() << std::endl;
	std::cout << fizz.empty() << std::endl;
	std::cout << fizz.size() << std::endl;
	std::cout << std::endl;
	std::cout << (foo == bar) << std::endl;
	std::cout << (foo != bar) << std::endl;
	std::cout << (foo > bar) << std::endl;
	std::cout << (foo >= bar) << std::endl;
	std::cout << (foo < bar) << std::endl;
	std::cout << (foo <= bar) << std::endl;


	return 0;
}