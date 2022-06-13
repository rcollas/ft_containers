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

int main() {

	std::cout << std::endl;
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
//	ft::vector<int> foo;
//	std::vector<int> bar;
//
//	foo.assign(10, 0);
//	bar.assign(10, 0);
////	foo.reserve(10);
////	bar.reserve(10);
////	for (size_t i = 0; i < foo.size(); i++) {
////		std::cout << foo[i] << std::endl;
////	}
////	for (size_t i = 0; i < bar.size(); i++) {
////		std::cout << bar[i] << std::endl;
////	}
//	ft::vector<int>::iterator it = foo.begin();
//	ft::vector<int>::iterator ite = foo.end();
//	std::cout << it - ite << std::endl;
//	std::cout << ite - it << std::endl;
//	std::cout << ite - ite << std::endl;
////	while (it != ite) {
////		std::cout << *it << std::endl;
////		it++;
////	}
//	std::vector<int>::iterator b = bar.begin();
//	std::vector<int>::iterator e = bar.end();
//	std::cout << b - e << std::endl;
//	std::cout << e - b << std::endl;
//	std::cout << e - e << std::endl;
////	while (b != e) {
////		std::cout << *b << std::endl;
////		b++;
////	}
//
//	std::cout << ft::is_same<int, int16_t>::value << std::endl;
//
//	ft::vector<base> fuu(20);
//	ft::vector<base> fizz;
//	std::cout << "fizz is empty = " << fizz.empty() << std::endl;
//	std::cout << "fizz data = " << fizz.data() << std::endl;
//	fizz.assign(fuu.begin(), fuu.end());
//	std::cout << "fizz data after assign = " << fizz.data() << std::endl;
//	std::cout << fuu.end() - fuu.begin() << std::endl;
//	std::vector<base> buu(20);
//	std::vector<base> buzz;
//	buzz.assign(buu.begin(), buu.end());
//	std::cout << buu.end() - buu.begin() << std::endl;
//
//	ft::vector<base> bazz(fuu.rbegin(), fuu.rend());
//	std::cout << bazz[0].getFloat() << std::endl;
////	std::vector<base> bizz(buu.rbegin(), buu.rend());
////	std::cout << bizz[0].getFloat() << std::endl;
//	ft::vector<int>::iterator test;


//	std::cout << std::endl;

//	ft::vector<Base> foo(20);
////	ft::vector<Base> bar(20);
////	std::vector<Base> bar(20);
//
////	srand(time(0));
//	Base value;
//	for (size_t i = 0; i < 10; i++) {
////		Base value = rand();
//		foo.push_back(value);
////		bar.push_back(Base());
//	}
////	foo.pop_back();
//	foo.erase(foo.begin());
//	foo.reserve(100);
//	ft::vector<Base>::iterator it = foo.begin();
//	std::cout << *it << std::endl;
//	std::cout << *foo.insert(it, Base()) << std::endl;
//	std::cout << *foo.begin() << std::endl;
//	std::cout << *it << std::endl;
//	bar.erase(bar.begin(), bar.end());
//	std::cout << foo.size() << std::endl;
//	std::cout << bar.end() - bar.begin() << std::endl;

//	for (size_t i = 0; i < bar.size(); i++) {
//		std::cout << "foo = " << foo[i] << " bar = " << bar[i] << std::endl;
//	}

//	std::cout << *(foo.begin()) << std::endl;
//	std::cout << *(foo.end() - 1) << std::endl;
//	std::cout << *(bar.end() - 1) << std::endl;

//	ft::vector<int>::iterator it = foo.erase(foo.begin() + 3);
////	std::vector<int>::iterator ite = bar.erase(bar.begin() + 3);
////
////	std::cout << "it = " << *(it) << std::endl;
////	std::cout << "ite = " << *ite << std::endl;
//
////	std::vector<Base> bar;
////	std::cout << &*bar.begin() << std::endl;
////	bar.insert(bar.begin(), Base());
////	std::cout << *bar.begin() << std::endl;
//
//	ft::vector<int> foo(10);
////	std::cout << *(foo.end() - 1) << std::endl;
////	std::cout << *(bar.end() - 1) << std::endl;
////	foo.erase(foo.begin(), foo.end());
////	for (int i = 0; i < 4; i++) {
////		foo.push_back(Base());
////	}
////	foo.push_back(Base());
////	std::cout << "capacity = " << foo.capacity() << " size = " << foo.size() << std::endl;
////	foo.insert(foo.begin(), 20, Base());
//	std::vector<int> bar(10);
//	std::vector<int> zap(20);
//	ft::vector<int> buzz;
////	std::cout << test + 4 << std::endl;
////	buzz.assign(test, test + 3);
////	std::cout << buzz.size() << std::endl;
////	buzz.assign(buzz.begin(), buzz.end());
////	std::cout << bar.end() - bar.begin() << std::endl;
//	foo.insert(foo.begin(), foo.begin(), foo.end());
//	foo.swap(buzz);
////	bar.insert(bar.begin(), bar.begin(), bar.end());
////	bar.insert(fazz.begin(), 20, Base());
////	for (size_t i = 0; i < foo.size(); i++) {
////		std::cout << foo[i] << std::endl;
//////	}
//////	bar.insert(bar.end(), Base());
//////	for (size_t i = 0; i < foo.size(); i++) {
//////		std::cout << foo[i] << std::endl;
//////	}
//////	std::cout << foo.size() << std::endl;
////	std::cout << (foo == buzz) << std::endl;
////	std::cout << (bar == zap) << std::endl;
////	std::map<int, int> foo;
////	foo.insert(std::pair<char, int>('a', 100));
////	std::cout << foo.at('a') << std::endl;
//
//
//	ft::map<int, int> bar;
////	ft::map<int, int>::iterator ite = bar.begin();
//	bar.insert(ft::pair<int, int>(10, 0));
//	bar.insert(ft::pair<int, int>(-10, 1));
//	bar.insert(ft::pair<int, int>(20, 2));
//	bar.insert(ft::pair<int, int>(0, 3));
//	std::cout << "root = " << bar._tree->_root->valueField.second << std::endl;
//	std::cout << "node left " << bar._tree->_root->left->valueField.second << std::endl;
//	std::cout << "node left right " << bar._tree->_root->left->right->data.second << std::endl;
////	bar.insert(ft::pair<int, int>(1, 100));
////	bar.insert(ft::pair<int, int>(2, 100));
////	bar.insert(ft::pair<int, int>(3, 100));
////	bar.insert(ft::pair<int, int>(4, 100));
////	bar.insert(ft::pair<int, int>(5, 100));
////	bar.print();
////	std::cout << (*ite).second << std::endl;
//
//	std::map<int, int> foo;
//	std::map<int, int>::iterator it = foo.begin();
//	foo.insert(std::pair<int, int>(10, 10));
//	std::cout << (*it).second << std::endl;
//	std::map<int, int> foo;
//	foo.insert(std::pair<int, int>(0, 0));
//	foo.insert(std::pair<int, int>(1, 1));
//	foo.insert(std::pair<int, int>(2, 2));
//	std::map<int, int>::iterator it(foo.begin());
//	std::cout << ++(++it)->second << std::endl;
//	foo.insert(std::pair<int, int>(3, 3));
//	foo.insert(std::pair<int, int>(4, 4));
//	foo.insert(std::pair<int, int>(5, 5));
//	foo.insert(std::pair<int, int>(6, 6));
//	it = foo.begin();
//	std::cout << ++(++it)->second << std::endl;
	ft::map<int, int> foo;
	std::cout << (foo.insert(ft::pair<int, int>(0, 1))).second << std::endl;
	std::cout << (foo.insert(ft::pair<int, int>(0, 2))).second << std::endl;
	std::cout << (foo.insert(ft::pair<int, int>(0, 3))).second << std::endl;
	std::cout << (foo.insert(ft::pair<int, int>(0, 4))).second << std::endl;
	std::cout << (foo.insert(ft::pair<int, int>(0, 5))).second << std::endl;
	ft::map<int, int>::iterator it = foo.begin();
	ft::map<int, int>::iterator ite = foo.end();

	std::cout << "start ft " << std::endl;
	while (it != ite) {
		std::cout << it->second << std::endl;
		it++;
	}
	std::cout << foo.begin()->second << std::endl;
	std::cout << foo.end()->second << std::endl;
	std::cout << std::endl;



	std::map<int, int> bar;
	std::cout << (bar.insert(std::pair<int, int>(0, 1))).second << std::endl;
	std::cout << (bar.insert(std::pair<int, int>(0, 2))).second << std::endl;
	std::cout << (bar.insert(std::pair<int, int>(0, 3))).second << std::endl;
	std::cout << (bar.insert(std::pair<int, int>(0, 4))).second << std::endl;
	std::cout << (bar.insert(std::pair<int, int>(0, 5))).second << std::endl;
	std::map<int, int>::iterator rit = bar.begin();
	std::map<int, int>::iterator rite = bar.end();

	std::cout << "start std" << std::endl;
	while (rit != rite) {
		std::cout << rit->second << std::endl;
		rit++;
	}
	std::cout << bar.begin()->second << std::endl;
	std::cout << bar.end()->second << std::endl;


}
