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
//		foo.print();
	}


}
