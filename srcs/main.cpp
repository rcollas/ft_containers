#include "Stack.hpp"
#include <iostream>
#include <list>

#include <compare>
#include <iterator>
#include <vector>
#include <map>
#include "utils/ReverseIterator.hpp"
#include "utils/IteratorsTraits.hpp"
#include "utils/Iterator.hpp"
#include "Vector.hpp"
#include "Map.hpp"
#include <ctime>
#include <cstdlib>
#include <memory>
#include "utils/is_same.hpp"
#include "utils/lexicographical_compare.hpp"
//#include "utils/RBT.hpp"

#ifndef STD
# define NS ft
#else
#define NS std
#endif

//# define NS std

int main() {

	std::cout << std::endl;

	{
		NS::map<int, int> foo;
		foo.insert(NS::pair<int, int>(0, 0));
		foo.insert(NS::pair<int, int>(1, 1));
		foo.insert(NS::pair<int, int>(2, 2));
		foo.insert(NS::pair<int, int>(10, 10));
		foo.insert(NS::pair<int, int>(5, 5));
		foo.insert(NS::pair<int, int>(3, 3));
		foo.insert(NS::pair<int, int>(4, 4));
		foo.insert(NS::pair<int, int>(-1, -1));
		foo.insert(NS::pair<int, int>(-2, -2));
		foo.insert(NS::pair<int, int>(-3, -3));
		foo.insert(NS::pair<int, int>(-4, -4));
		foo.insert(NS::pair<int, int>(-5, -5));


		std::cout << (foo.insert(NS::pair<int, int>(0, 1))).second << std::endl;
		std::cout << (foo.insert(NS::pair<int, int>(0, 2))).second << std::endl;
		std::cout << (foo.insert(NS::pair<int, int>(0, 3))).second << std::endl;
		std::cout << (foo.insert(NS::pair<int, int>(0, 4))).second << std::endl;
		std::cout << (foo.insert(NS::pair<int, int>(0, 5))).second << std::endl;
		NS::map<int, int>::iterator it = foo.begin();
		NS::map<int, int>::iterator ite = foo.end();

		while (it != ite) {

			std::cout << it->second << std::endl;
			it++;
		}
		foo.insert(foo.begin(), foo.end());
		it = foo.begin();
		ite = foo.end();
		while (it != ite) {
			std::cout << it->second << std::endl;
			it++;
		}
	}
	{
		NS::map<int, int> foo;
		foo.insert(NS::pair<int, int>(-3, -3));
		foo.insert(NS::pair<int, int>(-2, -2));
		foo.insert(NS::pair<int, int>(-1, -1));
		foo.insert(NS::pair<int, int>(0, 0));
		foo.insert(NS::pair<int, int>(1, 1));
		foo.insert(NS::pair<int, int>(2, 2));
		foo.insert(NS::pair<int, int>(4, 4));
		foo.insert(NS::pair<int, int>(5, 5));
		NS::map<int, int>::iterator it = foo.begin();
		for (; it != foo.end(); it++) {
			std::cout << it->second << std::endl;
		}
		for (size_t i = -3; i < 6; i++) {
			std::cout << foo.at(i) << std::endl;
		}
	}
	{
		NS::map<std::string, int> foo;
		foo.insert(NS::pair<std::string, int>("one", 1));
		foo.insert(NS::pair<std::string, int>("two", 2));
		foo.insert(NS::pair<std::string, int>("three", 3));
		foo.insert(NS::pair<std::string, int>("four", 4));
		foo.insert(NS::pair<std::string, int>("five", 5));
		foo.insert(NS::pair<std::string, int>("six", 6));
		foo.insert(NS::pair<std::string, int>("seven", 7));
		std::cout << "foo[one] = " << foo["one"] << std::endl;
		std::cout << "foo[two] = " << foo["two"] << std::endl;
		std::cout << "foo[three] = " << foo["three"] << std::endl;
		std::cout << "foo[ten] = " << foo["ten"] << std::endl;
	}


}
