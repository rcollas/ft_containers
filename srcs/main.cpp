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
//		using namespace ft;
//
//		vector<int>			test(3, 3);
//
//		std::cout << "self assignation test\n";
//		vector<vector<int> >	self_assign;
//		vector<vector<int> >	*ptr = &self_assign;
//		vector<vector<int> >	*ptr2 = &self_assign;
//
//		self_assign.assign(4, test);
//		*ptr = *ptr2;
//
//		std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
////	self_assign = self_assign; //compiler doesn't like it!
//
//
//
//		vector<vector<int> > JOHN;
//		vector<vector<int> > BOB(5, test);
//		std::cout << "BOB(5, test(test, 5)) : \n";
//		for (size_t i = 0; i < BOB.size(); i++)
//		{
//			for (size_t j = 0; j < BOB[i].size(); j++)
//				std::cout << BOB[i][j] << ' ';
//			std::cout << '\n';
//		}
//		vector<vector<int> > MIKE(BOB);
//
//		// CTORs
//		std::cout << "\nCTORS\n";
//		std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
//		std::cout << "BOB is empty? " << BOB.empty() << '\n';
//
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//
//		// RESIZE
//		size_t	bob_resize = 2;
//		std::cout << "\nRESIZE\n";
//		BOB.resize(bob_resize);
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		if (JOHN.capacity() >= JOHN.size())
//			std::cout << "Capacity of JOHN is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		if (BOB.capacity() >= bob_resize)
//			std::cout << "Capacity of BOB is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//		if (MIKE.capacity() >= MIKE.size())
//			std::cout << "Capacity of MIKE is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 63\n";
//
//		size_t	mike_resize = 9;
//		bob_resize = 0;
//
//		BOB.resize(bob_resize);
//		std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
//		MIKE.resize(mike_resize, test);
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		if (JOHN.capacity() >= JOHN.size())
//			std::cout << "Capacity of JOHN is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		if (BOB.capacity() >= bob_resize)
//			std::cout << "Capacity of BOB is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//		if (MIKE.capacity() >= mike_resize)
//			std::cout << "Capacity of MIKE is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
//		for (size_t i = 0; i < MIKE.size(); i++)
//		{
//			for (size_t j = 0; j < MIKE[i].size(); j++)
//			{
//				std::cout << MIKE[i][j] << ' ';
//			}
//			std::cout << std::endl;
//		}
//		// RESERVE
//		std::cout << "\nRESERVE\n";
//
//		size_t	john_reserve = 0;
//		size_t	bob_reserve = 3;
//		size_t	mike_reserve = 4;
//
//		JOHN.reserve(john_reserve);
//		BOB.reserve(bob_reserve);
//		MIKE.reserve(mike_reserve);
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		if (JOHN.capacity() >= john_reserve)
//			std::cout << "Capacity of JOHN is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		if (BOB.capacity() >= bob_reserve)
//			std::cout << "Capacity of BOB is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//		if (MIKE.capacity() >= mike_reserve)
//			std::cout << "Capacity of MIKE is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
//		for (size_t i = 0; i < MIKE.size(); i++)
//		{
//			for (size_t j = 0; j < MIKE[i].size(); j++)
//				std::cout << MIKE[i][j] << ' ';
//			std::cout << std::endl;
//		}
//
//		//AT
//		std::cout << "\nAT\n";
//		try
//		{
//			std::cout << MIKE.at(2).front() << '\n';
//			std::cout << MIKE.at(87).back() << '\n';
//		}
//		catch (std::out_of_range& oor)
//		{
//			(void)oor;
//			std::cout << "OOR error caught\n";
//		}
//
//		// FRONT / BACK
//		std::cout << "\nFRONT / BACK\n";
//		std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
//		std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';
//
//		//ASSIGN
//		std::cout << "\nASSIGN\n";
//		test.assign(3, 17);
//		BOB.assign(3, test);
//
//		//ASSIGN RANGE
//		std::cout << "\nASSIGN RANGE\n";
//		vector<vector<int> >	assign_range;
//		assign_range.assign(8, test);
//		assign_range.assign(BOB.begin() + 1, BOB.end() - 2);
//
//		//EMPTY
//		std::cout << "\nEMPTY\n";
//		std::cout << "BOB is empty ? " << BOB.empty() << '\n';
//		std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';
//
//		//PUSH/POP_BACK
//		std::cout << "\nPUSH/POP_BACK\n";
//		test.assign(2, 42);
//		BOB.push_back(test);
//		std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
//		BOB.pop_back();
//		std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
//
//		//INSERT
//		std::cout << "\nINSERT\n";
//		vector<vector<int> >	insert_in_me;
//		for (int i = 0; i < 15; i++)
//		{
//			vector<int>	j(2, i);
//			insert_in_me.push_back(j);
//		}
//		for (size_t i = 0; i < insert_in_me.size(); i++)
//		{
//			for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
//				std::cout << insert_in_me.at(i).at(j) << ' ';
//			std::cout << '\n';
//		}
//
//		vector<vector<int> >::iterator	tmp;
//		test.assign(23, 19);
//		tmp = insert_in_me.begin() + 4;
//		insert_in_me.insert(tmp, 8, test);
//		for (size_t i = 0; i < insert_in_me.size(); i++)
//		{
//			for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
//				std::cout << insert_in_me.at(i).at(j) << ' ';
//			std::cout << '\n';
//		}
//
//		vector<vector<int> >::const_iterator const_it(insert_in_me.begin());
//		std::cout << "Const it.front() : " << std::endl;
//		std::cout << (*const_it).front() << '\n';
//
//
//		//INSERT
//		std::cout << "\nINSERT\n";
//		vector<vector<int> >	std_insert_in_me;
//		for (int i = 0; i < 15; i++)
//			std_insert_in_me.push_back(test);
//		for (size_t i = 0; i < std_insert_in_me.size(); i++)
//			std::cout << std_insert_in_me.at(i).front() << ' ';
//		std::cout << '\n';
//
//		vector<vector<int> >::iterator	std_tmp;
//		std_tmp = std_insert_in_me.begin() + 4;
//		std_insert_in_me.insert(std_tmp, 8, test);
//		for (size_t i = 0; i < std_insert_in_me.size(); i++)
//			std::cout << std_insert_in_me.at(i).back() << ' ';
//		std::cout << '\n';
//
//
//		//INSERT RANGE
//		std::cout << "\nINSERT RANGE\n";
//		vector<vector<int> >	insert_bis;
//		for (int i = 0; i < 7; i++)
//		{
//			vector<int>	j(2, i * 3);
//			insert_bis.push_back(j);
//		}
//		for (size_t i = 0; i < insert_bis.size(); i++)
//			std::cout << insert_bis[i].back() << ' ';
//		std::cout << '\n';
//
//		insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
//		for (size_t i = 0; i < insert_bis.size(); i++)
//			std::cout << insert_bis[i].back() << ' ';
//		std::cout << '\n';
//
//
//		//ERASE
//		std::cout << "\nERASE\n";
//		vector<vector<int> >	erase_in_me;
//		for (int i = 0; i < 15; i++)
//		{
//			vector<int>	j(1, i);
//			erase_in_me.push_back(j);
//		}
//		for (size_t i = 0; i < erase_in_me.size(); i++)
//			std::cout << erase_in_me.at(i).front() << ' ';
//		std::cout << '\n';
//
//		erase_in_me.erase(erase_in_me.begin() + 7);
//		for (size_t i = 0; i < erase_in_me.size(); i++)
//			std::cout << erase_in_me.at(i).front() << ' ';
//		std::cout << '\n';
//		erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
//		for (size_t i = 0; i < erase_in_me.size(); i++)
//			std::cout << erase_in_me.at(i).front() << ' ';
//		std::cout << '\n';
//
//		//SWAP
//		std::cout << "\nSWAP\n";
//		john_reserve = 4;
//		JOHN.reserve(john_reserve);
//		BOB.swap(MIKE);
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		if (JOHN.capacity() >= JOHN.size())
//			std::cout << "Capacity of JOHN is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		if (BOB.capacity() >= BOB.size())
//			std::cout << "Capacity of BOB is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//		if (MIKE.capacity() >= MIKE.size())
//			std::cout << "Capacity of MIKE is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
//		for (size_t i = 0; i < MIKE.size(); i++)
//		{
//			for (size_t j = 0; j < MIKE[i].size(); j++)
//				std::cout << MIKE[i][j] << ' ';
//			std::cout << std::endl;
//		}
//
//		MIKE.swap(JOHN);
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		if (JOHN.capacity() >= JOHN.size())
//			std::cout << "Capacity of JOHN is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		if (BOB.capacity() >= BOB.size())
//			std::cout << "Capacity of BOB is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//		if (MIKE.capacity() >= MIKE.size())
//			std::cout << "Capacity of MIKE is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
//		for (size_t i = 0; i < MIKE.size(); i++)
//		{
//			for (size_t j = 0; j < MIKE[i].size(); j++)
//				std::cout << MIKE[i][j] << ' ';
//			std::cout << std::endl;
//		}
//
//		//CLEAR
//		std::cout << "\nCLEAR\n";
//		JOHN.clear();
//		MIKE.clear();
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		if (JOHN.capacity() >= JOHN.size())
//			std::cout << "Capacity of JOHN is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		if (BOB.capacity() >= BOB.size())
//			std::cout << "Capacity of BOB is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//		if (MIKE.capacity() >= MIKE.size())
//			std::cout << "Capacity of MIKE is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
//		for (size_t i = 0; i < MIKE.size(); i++)
//		{
//			for (size_t j = 0; j < MIKE[i].size(); j++)
//				std::cout << MIKE[i][j] << ' ';
//			std::cout << std::endl;
//		}
//
//		//NON MEMBER Functions
//		std::cout << "\nNON MEMBER functions\n";
//		swap(BOB, MIKE);
//		std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//		if (JOHN.capacity() >= JOHN.size())
//			std::cout << "Capacity of JOHN is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
//		std::cout << "Size of BOB " << BOB.size() << std::endl;
//		if (BOB.capacity() >= BOB.size())
//			std::cout << "Capacity of BOB is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
//		std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//		if (MIKE.capacity() >= MIKE.size())
//			std::cout << "Capacity of MIKE is sufficient\n";
//		else
//			std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
//		for (size_t i = 0; i < MIKE.size(); i++)
//		{
//			for (size_t j = 0; j < MIKE[i].size(); j++)
//				std::cout << MIKE[i][j] << ' ';
//			std::cout << std::endl;
//		}
//
//		//RELATIONAL OPERATORS
//		std::cout << "\nRELATIONAL OPERATORS\n";
//		vector<vector<int> > MIKE_2(MIKE);
//		std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
//		std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';
//
//		std::cout << "\nReal Vector\n";
//		vector<vector<int> > real;
//		real.assign(5, test);
//		for (vector<vector<int> >::iterator it = real.begin(); it != real.end(); it++)
//		std::cout << (*it).front() << " ";
//		std::cout << '\n';
//
//		std::cout << std::endl;


//	}
//
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
//		std::cout << "foo.insert(foo.end(), 0, \"hello\")" << std::endl;
//		foo.insert(foo.end(), 0, "hello");
//		printCapacity(foo);
//		std::cout << "foo.insert(foo.end(), 100000, \"trello\")" << std::endl;
//		foo.insert(foo.end(), 1000, "trello");
//		printCapacity(foo);
//		std::cout << "foo.insert(foo.end(), 20, \"mello\")" << std::endl;
//		foo.insert(foo.end(), 20, "mello");
//		printCapacity(foo);
//		std::cout << "foo.insert(foo.begin() + 5, foo.begin(), foo.end())" << std::endl;
//		foo.insert(foo.begin() + 5, foo.begin(), foo.end());
//		printCapacity(foo);
//		std::cout << "foo.insert(foo.begin() + 999, 0, \"brello\")" << std::endl;
//		foo.insert(foo.begin() + 999, 0, "brello");
//		printCapacity(foo);
//		std::cout << "foo.insert(foo.end() - 2, foo.begin(), foo.end())" << std::endl;
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
//
//	{
//		printTest("INT VECTOR ERASE");
//
//		NS::vector<int> foo;
//		srand(time(0));
//		for (int i = 0; i < 10; i++) {
//			foo.push_back(i);
//		}
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//		}
//		std::cout << "foo.erase(foo.begin(), foo.begin() + 5" << std::endl;
//		foo.erase(foo.begin(), foo.begin() + 5);
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//		}
//		std::cout << "foo.insert(foo.begin() + 1, foo.begin(), foo.end())" << std::endl;
//		foo.insert(foo.begin() + 1, foo.begin(), foo.end());
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//			std::cout << std::endl;
//		}
//		foo.clear();
//		for (int i = 0; i < 10; i++) {
//			foo.push_back(i);
//		}
//		std::cout << "foo.insert(foo.begin(), foo.begin(), foo.end())" << std::endl;
//		foo.insert(foo.begin(), foo.begin(), foo.end());
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
//			std::cout << std::endl;
//		}
//	}

//	{
//		printTest("SELF ASSIGNED VECTOR");
//
//		NS::vector<int> test(3, 3);
//		NS::vector<int> test2(10, 3);
//		NS::vector<NS::vector<int> > foo;
//		NS::vector<NS::vector<int> > bar;
//		bar.assign(4, test2);
//		printCapacity(foo);
//		NS::vector<NS::vector<int> > *ptr = &foo;
//		NS::vector<NS::vector<int> > *ptr2 = &foo;
//		std::cout << ptr->size() << std::endl;
//		foo.assign(4, test);
//		std::cout << ptr2->size() << std::endl;
//		*ptr = *ptr2;
//		std::cout << (*ptr == *ptr2) << std::endl;
//		std::cout << "before swap foo > bar " << (foo > bar) << std::endl;
//		NS::swap(foo, bar);
//		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
//		foo.swap(bar);
//		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
//		foo.clear();
//		printCapacity(foo);
//		std::cout << "foo.reserve(1000)" << std::endl;
//		foo.reserve(1000);
//		printCapacity(foo);
//		std::cout << "foo.reserve(10)" << std::endl;
//		foo.reserve(10);
//		printCapacity(foo);
//	}
//
//	{
//		printTest("VECTOR ITERATOR");
//		NS::vector<int> foo;
//		for (int i = 0; i < 10; i++) {
//			foo.push_back(i);
//		}
//		NS::vector<int>::iterator it = foo.begin();
//		NS::vector<int>::iterator ite = foo.end();
//		NS::vector<int>::reverse_iterator rit = foo.rbegin();
//		NS::vector<int>::reverse_iterator rite = foo.rend();
//		std::cout << "for (;it != ite; i++)" << std::endl;
//		for (; it != ite; it++) {
//			std::cout << *it << std::endl;
//		}
//		std::cout << "for (;rit != rite; i++)" << std::endl;
//		for (;rit != rite; rit++) {
//			std::cout << *rit << std::endl;
//		}
//	}
//
//	{
//		printTest("SWAP VECTOR");
//		NS::vector<int> foo;
//		NS::vector<int> bar;
//		for (int i = 0; i < 10; i++) {
//			foo.push_back(i);
//		}
//		for (int i = 0; i < 10; i++) {
//			bar.push_back(i + 10);
//		}
//		std::cout << "before swap foo > bar " << (foo > bar) << std::endl;
//		NS::swap(foo, bar);
//		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
//		foo.swap(bar);
//		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
//		std::cout << "foo.swap(foo)" << std::endl;
//		foo.swap(foo);
//
//		foo.clear();
//		bar.clear();
//		foo.assign(10, 5);
//		bar.assign(30, 0);
//		foo.swap(bar);
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//		}
//		for (size_t i = 0; i < bar.size(); i++) {
//			std::cout << "bar[" << i << "] = " << bar[i] << std::endl;
//		}
//		NS::swap(foo, bar);
//		for (size_t i = 0; i < foo.size(); i++) {
//			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
//		}
//		for (size_t i = 0; i < bar.size(); i++) {
//			std::cout << "bar[" << i << "] = " << bar[i] << std::endl;
//		}
//	}

	{
		printTest("MAP TEST");
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
		foo.erase("one");
		std::cout << "foo[one] = " << foo["one"] << std::endl;
	}



}
