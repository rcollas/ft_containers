#include "Stack.hpp"
#include <iostream>
#include <list>

#include <compare>
#include <iterator>
#include <vector>
#include "ReverseIterator.hpp"
#include "IteratorsTraits.hpp"
#include "Iterator.hpp"
#include "Vector.hpp"
#include <ctime>
#include <cstdlib>
#include <memory>

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


	ft::iterator_traits<int *>::value_type I;
	I = 10;
	std::cout << I << std::endl;

	ft::vector<int> buzz(10);
	ft::vector<int>::iterator start(buzz.begin());
	ft::vector<int>::iterator end(buzz.end());
	std::cout << "in main buzz begin = " << *buzz.begin() << std::endl;
	std::cout << "test = " << *start << std::endl;
	ft::vector<int>::reverse_iterator bazz(buzz.rend());
	std::cout << *bazz << std::endl;
	for (;start != end;) {
		std::cout << "value = " << *start << std::endl;
		std::cout << "address = " << &*start << std::endl;
		++start;
	}


	for (int i = 0; i < 10; i++) {
		buzz[i] = 10;
		std::cout << buzz[i] << std::endl;
	}


	for (int i = 0; i < 10; i++) {
		buzz.at(i) = 20;
		std::cout << buzz.at(i) << std::endl;
	}

	ft::vector<int> fuzz(3);
	srand(time(0));
	for (int i = 0; i < 100; i++) {
		fuzz.push_back(i);
	}

	std::vector<int> fozz(3);
	for (int i = 0; i < 100; i++) {
		fozz.push_back(i);
	}
	for (size_t i = 0; i < fozz.capacity(); i++) {
		if (fuzz[i] != fozz[i]) {
			std::cout << "Error" << std::endl;
		}
	}
	fozz.push_back(10);
	std::cout << fozz[0] << std::endl;

	return 0;
}
