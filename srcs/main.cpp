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
# define NS std
#endif

//# define NS std

void printTest(std::string testName) {

	testName.insert(0, 1, ' ');
	testName.append(1, ' ');
	std::cout << "\x1B[32m" << std::string(90, '*') << std::endl;
	std::cout << std::string(90, '*').replace(45 - testName.length() / 2,
														testName.length(),
														testName) << std::endl;
	std::cout << std::string(90, '*') << "\033[0m" << std::endl;
}

template <typename T>
void printCapacity(NS::vector<T> v) {
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "empty = " << v.empty() << std::endl;
	std::cout << "max_size = " << v.max_size() << std::endl;
}

int main() {

	std::cout << std::endl;

//	{
//		printTest("EMPTY VECTOR");
//
//		NS::vector<std::string> foo;
//		printCapacity(foo);
//		foo.clear();
//		std::cout << foo.get_allocator().max_size() << std::endl;
//		try {
//			std::cout << foo.at(10)	<< std::endl;
//		} catch (...) {
//			std::cout << "bad index" << std::endl;
//		}
//		std::cout << foo.data() << std::endl;
//		std::cout << foo.data() + foo.size() << std::endl;
//
//		printTest("EMPTY VECTOR ITERATOR");
//		NS::vector<std::string>::iterator it = foo.begin();
//		NS::vector<std::string>::iterator ite = foo.end();
//		for (; it != ite; it++) {
//			std::cout << "vector iteration" << std::endl;
//		}
//		if (it == ite) {
//			std::cout << "it == ite" << std::endl;
//		}
//
//		printTest("EMPTY VECTOR MODIFIERS");
//		std::cout << *(foo.insert(foo.begin(), "ten")) << std::endl;
//		printCapacity(foo);
//		foo.clear();
//		foo.insert(foo.end(), 0, "hello");
//		printCapacity(foo);
//		foo.insert(foo.end(), 100000, "trello");
//		printCapacity(foo);
//		foo.insert(foo.end(), 20, "mello");
//		printCapacity(foo);
//		foo.insert(foo.begin() + 5, foo.begin(), foo.end());
//		printCapacity(foo);
//		foo.insert(foo.begin() + 999, 0, "brello");
//		printCapacity(foo);
//		foo.insert(foo.end() - 2, foo.begin(), foo.end());
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//		}
//		std::cout << foo.front() << std::endl;
//		std::cout << foo.back() << std::endl;
//		std::cout << *(foo.erase(foo.begin() + 100)) << std::endl;
//		std::cout << *(foo.erase(foo.end() - 1)) << std::endl;
//		std::cout << *(foo.erase(foo.end() - 1)) << std::endl;
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//		}
//		std::cout << *(foo.erase(foo.begin(), foo.end())) << std::endl;
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//		}
//	}

	{
		printTest("INT VECTOR ERASE");

		NS::vector<int> foo;
		srand(time(0));
		for (int i = 0; i < 10; i++) {
			foo.push_back(i);
		}
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
		}
//		foo.erase(foo.end());
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//		}
		std::cout << "foo.erase(foo.begin(), foo.begin() + 5" << std::endl;
		foo.erase(foo.begin(), foo.begin() + 5);
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//		}
		std::cout << "foo.insert(foo.begin() + 1, foo.begin(), foo.end())" << std::endl;
		foo.insert(foo.begin() + 1, foo.begin(), foo.end());
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
			std::cout << std::endl;
		}
	}

//	{
//		printTest("MAP TEST");
//		NS::map<int, int> foo;
//		foo.insert(NS::pair<int, int>(0, 0));
//		foo.insert(NS::pair<int, int>(1, 1));
//		foo.insert(NS::pair<int, int>(2, 2));
//		foo.insert(NS::pair<int, int>(10, 10));
//		foo.insert(NS::pair<int, int>(5, 5));
//		foo.insert(NS::pair<int, int>(3, 3));
//		foo.insert(NS::pair<int, int>(4, 4));
//		foo.insert(NS::pair<int, int>(-1, -1));
//		foo.insert(NS::pair<int, int>(-2, -2));
//		foo.insert(NS::pair<int, int>(-3, -3));
//		foo.insert(NS::pair<int, int>(-4, -4));
//		foo.insert(NS::pair<int, int>(-5, -5));
//
//
//		std::cout << (foo.insert(NS::pair<int, int>(0, 1))).second << std::endl;
//		std::cout << (foo.insert(NS::pair<int, int>(0, 2))).second << std::endl;
//		std::cout << (foo.insert(NS::pair<int, int>(0, 3))).second << std::endl;
//		std::cout << (foo.insert(NS::pair<int, int>(0, 4))).second << std::endl;
//		std::cout << (foo.insert(NS::pair<int, int>(0, 5))).second << std::endl;
//		NS::map<int, int>::iterator it = foo.begin();
//		NS::map<int, int>::iterator ite = foo.end();
//
//		while (it != ite) {
//
//			std::cout << it->second << std::endl;
//			it++;
//		}
//		foo.insert(foo.begin(), foo.end());
//		it = foo.begin();
//		ite = foo.end();
//		while (it != ite) {
//			std::cout << it->second << std::endl;
//			it++;
//		}
//	}
//	{
//		NS::map<int, int> foo;
//		foo.insert(NS::pair<int, int>(-3, -3));
//		foo.insert(NS::pair<int, int>(-2, -2));
//		foo.insert(NS::pair<int, int>(-1, -1));
//		foo.insert(NS::pair<int, int>(0, 0));
//		foo.insert(NS::pair<int, int>(1, 1));
//		foo.insert(NS::pair<int, int>(2, 2));
//		foo.insert(NS::pair<int, int>(4, 4));
//		foo.insert(NS::pair<int, int>(5, 5));
//		NS::map<int, int>::iterator it = foo.begin();
//		for (; it != foo.end(); it++) {
//			std::cout << it->second << std::endl;
//		}
//		for (size_t i = -3; i < 6; i++) {
//			std::cout << foo.at(i) << std::endl;
//		}
//	}
//	{
//		NS::map<std::string, int> foo;
//		foo.insert(NS::pair<std::string, int>("one", 1));
//		foo.insert(NS::pair<std::string, int>("two", 2));
//		foo.insert(NS::pair<std::string, int>("three", 3));
//		foo.insert(NS::pair<std::string, int>("four", 4));
//		foo.insert(NS::pair<std::string, int>("five", 5));
//		foo.insert(NS::pair<std::string, int>("six", 6));
//		foo.insert(NS::pair<std::string, int>("seven", 7));
//		std::cout << "foo[one] = " << foo["one"] << std::endl;
//		std::cout << "foo[two] = " << foo["two"] << std::endl;
//		std::cout << "foo[three] = " << foo["three"] << std::endl;
//		std::cout << "foo[ten] = " << foo["ten"] << std::endl;
//		foo.erase("one");
//		std::cout << "foo[one] = " << foo["one"] << std::endl;
//	}



}
