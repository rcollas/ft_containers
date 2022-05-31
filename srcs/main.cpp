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

//	ft::stack<int> foo;
//	ft::stack<int> bar;
//	std::cout << std::boolalpha;
//	std::cout << foo.empty() << std::endl;
//	std::cout << foo.size() << std::endl;
//	foo.push(10);
//	std::cout << foo.size() << std::endl;
//	std::cout << (foo == bar) << std::endl;
//
//	ft::stack<float, std::list<float> > fizz;
//	fizz.push(10);
//	std::cout << fizz.top() << std::endl;
//	fizz.push(5);
//	fizz.push(-10);
//	fizz.push(1230);
//	fizz.push(-2304);
//	std::cout << fizz.top() << std::endl;
//	std::cout << fizz.empty() << std::endl;
//	std::cout << fizz.size() << std::endl;
//	std::cout << std::endl;
//	std::cout << (foo == bar) << std::endl;
//	std::cout << (foo != bar) << std::endl;
//	std::cout << (foo > bar) << std::endl;
//	std::cout << (foo >= bar) << std::endl;
//	std::cout << (foo < bar) << std::endl;
//	std::cout << (foo <= bar) << std::endl;
//
//
//	ft::iterator_traits<int *>::value_type I;
//	I = 10;
//	std::cout << I << std::endl;
//
//	ft::vector<int> buzz(10);
//	ft::vector<int>::iterator start(buzz.begin());
//	ft::vector<int>::iterator end(buzz.end());
//	std::cout << "in main buzz begin = " << *buzz.begin() << std::endl;
//	std::cout << "test = " << *start << std::endl;
//	ft::vector<int>::reverse_iterator bazz(buzz.begin());
//	std::cout << *bazz << std::endl;
//	for (;start != end;) {
//		std::cout << "value = " << *start << std::endl;
//		std::cout << "address = " << &*start << std::endl;
//		start++;
//	}
//
//
//	for (int i = 0; i < 10; i++) {
//		buzz[i] = 10;
//		std::cout << buzz[i] << std::endl;
//	}
//
//
//	for (int i = 0; i < 10; i++) {
//		buzz.at(i) = 20;
//		std::cout << buzz.at(i) << std::endl;
//	}
//
//	ft::vector<int> fuzz(3);
//	srand(time(0));
//	for (int i = 0; i < 100; i++) {
//		fuzz.push_back(i);
//	}
//
//	std::vector<int> fozz(3);
//	for (int i = 0; i < 100; i++) {
//		fozz.push_back(i);
//	}
//	std::cout << "fuzz size = " << fuzz.size() << " fozz size = " << fozz.size() << std::endl;
//	for (size_t i = 0; i < fozz.size(); i++) {
//		if (fuzz[i] != fozz[i]) {
//			std::cout << "fuzz = " << fuzz[i]  << " fozz = " << fozz[i] << std::endl;
//		}
//	}
//	fozz.push_back(10);
//	std::cout << fozz[0] << std::endl;
//
//	ft::vector<int>::iterator it(fuzz.begin());
//	ft::vector<int>::iterator ite(fuzz.end());
//	ft::vector<int> fazz(it, ite);
//
//	std::cout << "fuzz[10] = " << fuzz[10] << " fazz[10] = " << fazz[10] << std::endl;
//
//	ft::vector<int> copy(fuzz);
//	std::cout << "fuzz[20] = " << fuzz[20] << " copy[20] = " << copy[20] << std::endl;
//
//	ft::vector<int> copyOverload = ft::vector<int>(it, ite);
//	std::cout << "fuzz[10] = " << fuzz[10] << " copyOverload[10] = " << copyOverload[10] << std::endl;
//
//	ft::vector<std::string> fooStr(10);
//	fooStr[0] = "hello";
//	fooStr[1] = "bonjour";
//	fooStr[2] = "ciao";
//	fooStr[3] = "hola";
//	//for (int i = 0; i < 20; i++) {
//	//	fooStr.push_back("PUSH_BACK");
//	//}
//
//	std::vector<std::string> compare(10);
//	compare[0] = "hello";
//	compare[1] = "bonjour";
//	compare[2] = "ciao";
//	compare[3] = "hola";
//	for (int i = 0; i < 20; i++) {
//		compare.push_back("PUSH_BACK");
//	}
//
//	for (int i = 0; i < 20; i++) {
//		if (fooStr[i] != compare[i]) {
//			std::cout << "ERROR" << std::endl;
//		}
//	}
//	ft::vector<int> foo;
//	std::cout << foo.capacity() << std::endl;
//	foo.push_back(10);
//	for (int i = 0; i < 10; i++) {
//		foo.push_back(5);
//	}
//	std::cout << *foo.begin() << std::endl;
//	std::cout << foo.capacity() << std::endl;
//	for (size_t i = 0; i < foo.size(); i++) {
//		std::cout << foo[i] << std::endl;
//	}
//
//	std::vector<int> bar;
//	std::cout << bar.capacity() << std::endl;
//	bar.push_back(10);
//	for (int i = 0; i < 10; i++) {
//		bar.push_back(5);
//	}
//	std::cout << *bar.begin() << std::endl;
//	std::cout << bar.capacity() << std::endl;
//	for (size_t i = 0; i < bar.size(); i++) {
//		std::cout << bar[i] << std::endl;
//	}
	ft::vector<int> foo;
	std::vector<int> bar;

	foo.assign(10, 0);
	bar.assign(10, 0);
//	foo.reserve(10);
//	bar.reserve(10);
	for (size_t i = 0; i < foo.size(); i++) {
		std::cout << foo[i] << std::endl;
	}
	for (size_t i = 0; i < bar.size(); i++) {
		std::cout << bar[i] << std::endl;
	}
	ft::vector<int>::iterator it = foo.begin();
	ft::vector<int>::iterator ite = foo.end();
//	std::cout << it - ite << std::endl;

	return 0;
}
