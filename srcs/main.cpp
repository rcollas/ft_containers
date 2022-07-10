#include "Stack.hpp"
#include <iostream>
#include <list>

#include <compare>
#include <iterator>
#include <vector>
#include <map>
#include <iomanip>
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
#include <sys/time.h>

#ifndef STD
# define NS ft
#else
# define NS std
#endif

# define _END			"\x1b[0m"
# define _YELLOW		"\x1b[33m"
# define _PURPLE		"\x1b[35m"
# define _WHITE			"\x1b[37m"

long	get_time(void)
{
	struct timeval	timestamp;
	long			time;

	gettimeofday(&timestamp, 0);
	time = timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000;
	return (time);
}

template <class Key, class T>
void	print(NS::map<Key, T>& lst)
{
	std::cout << "printing a map : \n";
	for (typename NS::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}


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
	long timer = get_time();

	{
		printTest("EMPTY VECTOR");

		NS::vector<std::string> foo;
		printCapacity(foo);
		foo.clear();
		std::cout << foo.get_allocator().max_size() << std::endl;
		try {
			std::cout << foo.at(10)	<< std::endl;
		} catch (...) {
			std::cout << "bad index" << std::endl;
		}
		std::cout << foo.data() << std::endl;
		std::cout << foo.data() + foo.size() << std::endl;

		printTest("EMPTY VECTOR ITERATOR");
		NS::vector<std::string>::iterator it = foo.begin();
		NS::vector<std::string>::iterator ite = foo.end();
		for (; it != ite; it++) {
			std::cout << "vector iteration" << std::endl;
		}
		if (it == ite) {
			std::cout << "it == ite" << std::endl;
		}

		printTest("EMPTY VECTOR MODIFIERS");
		std::cout << *(foo.insert(foo.begin(), "ten")) << std::endl;
		printCapacity(foo);
		foo.clear();
		std::cout << "foo.insert(foo.end(), 0, \"hello\")" << std::endl;
		foo.insert(foo.end(), 0, "hello");
		printCapacity(foo);
		std::cout << "foo.insert(foo.end(), 100000, \"trello\")" << std::endl;
		foo.insert(foo.end(), 1000, "trello");
		printCapacity(foo);
		std::cout << "foo.insert(foo.end(), 20, \"mello\")" << std::endl;
		foo.insert(foo.end(), 20, "mello");
		printCapacity(foo);
		std::cout << "foo.insert(foo.begin() + 5, foo.begin(), foo.end())" << std::endl;
		foo.insert(foo.begin() + 5, foo.begin(), foo.end());
		printCapacity(foo);
		std::cout << "foo.insert(foo.begin() + 999, 0, \"brello\")" << std::endl;
		foo.insert(foo.begin() + 999, 0, "brello");
		printCapacity(foo);
		std::cout << "foo.insert(foo.end() - 2, foo.begin(), foo.end())" << std::endl;
		foo.insert(foo.end() - 2, foo.begin(), foo.end());
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
		}
		std::cout << foo.front() << std::endl;
		std::cout << foo.back() << std::endl;
		std::cout << *(foo.erase(foo.begin() + 100)) << std::endl;
		std::cout << *(foo.erase(foo.end() - 1)) << std::endl;
		std::cout << *(foo.erase(foo.end() - 1)) << std::endl;
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
		}
		std::cout << *(foo.erase(foo.begin(), foo.end())) << std::endl;
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
		}
	}

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
		std::cout << "foo.erase(foo.begin(), foo.begin() + 5" << std::endl;
		foo.erase(foo.begin(), foo.begin() + 5);
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
		}
		std::cout << "foo.insert(foo.begin() + 1, foo.begin(), foo.end())" << std::endl;
		foo.insert(foo.begin() + 1, foo.begin(), foo.end());
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
			std::cout << std::endl;
		}
		foo.clear();
		for (int i = 0; i < 10; i++) {
			foo.push_back(i);
		}
		std::cout << "foo.insert(foo.begin(), foo.begin(), foo.end())" << std::endl;
		foo.insert(foo.begin(), foo.begin(), foo.end());
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
			std::cout << "foo.at(" << i << ") = " << foo.at(i) << std::endl;
			std::cout << std::endl;
		}
	}

	{
		printTest("SELF ASSIGNED VECTOR");

		NS::vector<int> test(3, 3);
		NS::vector<int> test2(10, 3);
		NS::vector<NS::vector<int> > foo;
		NS::vector<NS::vector<int> > bar;
		bar.assign(4, test2);
		printCapacity(foo);
		NS::vector<NS::vector<int> > *ptr = &foo;
		NS::vector<NS::vector<int> > *ptr2 = &foo;
		std::cout << ptr->size() << std::endl;
		foo.assign(4, test);
		std::cout << ptr2->size() << std::endl;
		*ptr = *ptr2;
		std::cout << (*ptr == *ptr2) << std::endl;
		std::cout << "before swap foo > bar " << (foo > bar) << std::endl;
		NS::swap(foo, bar);
		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
		foo.swap(bar);
		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
		foo.clear();
		printCapacity(foo);
		std::cout << "foo.reserve(1000)" << std::endl;
		foo.reserve(1000);
		printCapacity(foo);
		std::cout << "foo.reserve(10)" << std::endl;
		foo.reserve(10);
		printCapacity(foo);
	}

	{
		printTest("VECTOR ITERATOR");
		NS::vector<int> foo;
		for (int i = 0; i < 10; i++) {
			foo.push_back(i);
		}
		NS::vector<int>::iterator it = foo.begin();
		NS::vector<int>::iterator ite = foo.end();
		NS::vector<int>::reverse_iterator rit = foo.rbegin();
		NS::vector<int>::reverse_iterator rite = foo.rend();
		std::cout << "for (;it != ite; i++)" << std::endl;
		for (; it != ite; it++) {
			std::cout << *it << std::endl;
		}
		std::cout << "for (;rit != rite; i++)" << std::endl;
		for (;rit != rite; rit++) {
			std::cout << *rit << std::endl;
		}
	}

	{
		printTest("SWAP VECTOR");
		NS::vector<int> foo;
		NS::vector<int> bar;
		for (int i = 0; i < 10; i++) {
			foo.push_back(i);
		}
		for (int i = 0; i < 10; i++) {
			bar.push_back(i + 10);
		}
		std::cout << "before swap foo > bar " << (foo > bar) << std::endl;
		NS::swap(foo, bar);
		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
		foo.swap(bar);
		std::cout << "after swap foo > bar " << (foo > bar) << std::endl;
		std::cout << "foo.swap(foo)" << std::endl;
		foo.swap(foo);

		foo.clear();
		bar.clear();
		foo.assign(10, 5);
		bar.assign(30, 0);
		foo.swap(bar);
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
		}
		for (size_t i = 0; i < bar.size(); i++) {
			std::cout << "bar[" << i << "] = " << bar[i] << std::endl;
		}
		NS::swap(foo, bar);
		for (size_t i = 0; i < foo.size(); i++) {
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
		}
		for (size_t i = 0; i < bar.size(); i++) {
			std::cout << "bar[" << i << "] = " << bar[i] << std::endl;
		}
	}
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
		std::cout << "foo.begin()->second = " << foo.begin()->second << std::endl;
		while (!foo.empty()) {
			foo.erase(foo.begin());
			std::cout << foo.size() << std::endl;
		}
	}

	{
		printTest("MAP ITERATOR");
		NS::map<int, int> foo;
		std::cout << "empty 691: " << foo.empty() << std::endl;
		for (int i = 0; i < 30; i++) {
			foo.insert(NS::pair<int, int>(i, i));
		}
		NS::map<int, int>::const_iterator cit = foo.begin();
		NS::map<int, int>::const_iterator cite = foo.end();
		NS::map<int, int>::const_reverse_iterator crit(foo.rbegin());
		NS::map<int, int>::reverse_iterator rit = foo.rbegin();
		std::cout << "rit->second = " << rit->second << std::endl;
		std::cout << "crit->second = " << crit->second << std::endl;
		std::cout << "cit->second = " << cit->second << std::endl;
		std::cout << "cite->second = " << cite->second << std::endl;
		std::cout << "(--cite)->second = " << (--cite)->second << std::endl;
		std::cout << "rbegin()->second = " << foo.rbegin()->second << std::endl;
		std::cout << "rend()->second = " << foo.rend()->second << std::endl;
		std::cout << "begin()->second = " << foo.begin()->second << std::endl;
		std::cout << "end()->second = " << foo.end()->second << std::endl;
		NS::map<int, int>::iterator ite = foo.end();
		std::cout << "cite == ite" << (cite == ite) << std::endl;
		foo[1] = 2;
		std::cout << "foo[1] = " << foo[1] << std::endl;
		std::cout << "empty 711: " << foo.empty() << std::endl;
		std::cout << "max size 713: " << foo.max_size() << std::endl;
		foo.erase(foo.begin(), foo.end());
		std::cout << "size 715: " << foo.size() << std::endl;
		foo.clear();
		for (int i = 0; i < 2; i++) {
			foo.insert(NS::pair<int, int>(i, i));
		}
		std::cout << "foo.rend() 721 = " << foo.rend()->second << std::endl;
		for (rit = foo.rbegin(); rit != foo.rend(); rit++) {
			std::cout << rit->first << "=>" << rit->second << std::endl;
		}
	}
	{
		printTest("MAP SWAP");
		NS::map<int, std::string> foo;
		NS::map<int, std::string> bar;
		for (int i = 0; i < 10; i++) {
			foo.insert(NS::pair<int, std::string>(i, "ciao"));
			bar.insert(NS::pair<int, std::string>(i, "hello"));
		}
		std::cout << "foo == bar: " << (foo == bar) << std::endl;
		NS::map<int, std::string>::iterator it = foo.begin();
		NS::map<int, std::string>::iterator bit = bar.begin();
		std::cout << "it 728 = " << it->second << std::endl;
		std::cout << "foo.begin() = " << foo.begin()->second << std::endl;
		std::cout << "bit 729 = " << bit->second << std::endl;
		std::cout << "bar.begin() = " << bar.begin()->second << std::endl;
		foo.swap(bar);
		std::cout << "it 731 = " << it->second << std::endl;
		std::cout << "foo.begin() = " << foo.begin()->second << std::endl;
		std::cout << "bit 732 = " << bit->second << std::endl;
		std::cout << "bar.begin() = " << bar.begin()->second << std::endl;
		std::cout << "foo.count(1) = " << foo.count(1) << std::endl;
		std::cout << "foo.count(100) = " << foo.count(100) << std::endl;
		for (int i = 0; i < 10; i++) {
			foo.find(i);
		}
		foo.insert(NS::pair<int, std::string>(20, "crowd"));
		foo.insert(NS::pair<int, std::string>(30, "brown"));
		foo.insert(NS::pair<int, std::string>(40, "frown"));
		std::cout << "752 lower_bound: " << (foo.lower_bound(1))->first << " => " << (foo.lower_bound(1))->second << std::endl;
		std::cout << "753 lower_bound: " << (foo.lower_bound(19))->first << " => " << (foo.lower_bound(19))->second << std::endl;
		std::cout << "754 lower_bound: " << (foo.lower_bound(20))->first << " => " << (foo.lower_bound(20))->second << std::endl;
		std::cout << "755 lower_bound: " << (foo.lower_bound(35))->first << " => " << (foo.lower_bound(35))->second << std::endl;
		std::cout << "756 upper_bound: " << (foo.upper_bound(20))->first << " => " << (foo.upper_bound(20))->second << std::endl;
		std::cout << "757 upper_bound: " << (foo.upper_bound(21))->first << " => " << (foo.upper_bound(21))->second << std::endl;
		foo = bar;
		bar.clear();
		foo.clear();
	}
	{
		printTest("OPERATION ON EMPTY MAP");
		NS::map<int, int> foo;
		std::cout << "foo.find(1) 746" << std::endl;
		foo.find(1);
		std::cout << "foo.erase(0) 748" << std::endl;
		foo.erase(0);
		foo.upper_bound(10);
		foo.lower_bound(20);
	}

	{
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		std::cout << "low : " << itlow->first << '\n';
		std::cout << "up : " << itup->first << '\n';

		mymap.erase(itlow,itup);        // erases [itlow,itup)

//		 print content:
		mymap[0];
		for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		NS::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}

	{
		std::cout << _WHITE << "# test_map" << _END << std::endl;
		std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
		std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
		std::cout << "/* ********************************************************************** */" << _END << std::endl;
		std::cout << std::endl;


		NS::map<std::string, int> mymap;
		print(mymap);


		std::cout << "mymap<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap;" << std::endl;

		std::cout << std::endl;
		std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
		print(mymap);
		std::cout << std::endl;


		print(mymap);
		mymap.insert(NS::pair<std::string, int>("ft", 42));

		print(mymap);
		mymap.insert(NS::pair<std::string, int>("one", 1));


		std::cout << _WHITE << "# testing upper/lower_bound" << _END << std::endl;
		NS::map<std::string, int>::iterator mit;
		NS::map<std::string, int>::iterator it;
		print(mymap);
		it = mymap.lower_bound("aaa");
		print(mymap);
		std::cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;
		std::cout << std::endl;
		print(mymap);
		it = mymap.lower_bound("one");
		print(mymap);
		std::cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl;
		std::cout << std::endl;
		print(mymap);
		it = mymap.lower_bound("oae");
		print(mymap);
		std::cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;
		std::cout << std::endl;
		print(mymap);
		it = mymap.lower_bound("ft");
		print(mymap);
		std::cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;
		std::cout << std::endl;
		print(mymap);
		it = mymap.lower_bound("zzz");
		print(mymap);

		if (it == mymap.end())
			std::cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl;
		std::cout << std::endl;
		print(mymap);
		it = mymap.upper_bound("aaa");

		print(mymap);
		std::cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;;
		std::cout << std::endl;
		print(mymap);
		it = mymap.upper_bound("oae");
		print(mymap);
		std::cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;;
		std::cout << std::endl;
		print(mymap);
		it = mymap.upper_bound("one");

		if (it == mymap.end())
			std::cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl;
		print(mymap);
		std::cout << std::endl;
		it = mymap.upper_bound("ft");
		print(mymap);
		std::cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;;
		std::cout << std::endl;
		print(mymap);
		it = mymap.upper_bound("zzz");

		if (it == mymap.end())
			std::cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl;
		print(mymap);
		std::cout << std::endl;

		print(mymap);
		mymap.erase("undefined");
		print(mymap);
		mymap.erase("ft");
		print(mymap);
		std::cout << _WHITE << "# double clear" << _END << std::endl;
		mymap.clear();
		print(mymap);
		mymap.clear();
		print(mymap);
		mymap["lol"];
		print(mymap);
		mymap.insert(NS::pair<std::string, int>("xD", 123));
		print(mymap);
		mymap.insert(mymap.end(), NS::pair<std::string, int>("uch", 442));
		print(mymap);
		mymap.insert(mymap.begin(), NS::pair<std::string, int>("uch", 22));
		print(mymap);
		mymap.insert(mymap.end(), NS::pair<std::string, int>("uch", 23));
		print(mymap);
		mymap.insert(NS::pair<std::string, int>("uch", 23));
		print(mymap);
		mymap["lol"] = 8;


		print(mymap);
		NS::map<std::string, int> map2;

		print(mymap);
		print(map2);
		std::cout << "mymap<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap2;" << std::endl;
		print(mymap);
		std::cout << "empty line\n";
		print(map2);
		std::cout << "empty line2\n";

		swap(mymap, map2);
		std::cout << "empty line3\n";
		print(mymap);
		std::cout << "empty line4\n";
		print(map2);
		std::cout << "empty line5\n";

		print(mymap);
		mymap = map2;
		print(mymap);
		print(map2);

		std::cout << std::setw(40) << "NS::map == map2: " << (mymap == map2) << std::endl;
		print(mymap);
		print(map2);
		std::cout << std::endl;

		mymap.clear();
		print(mymap);
		print(map2);

		mymap["satan"] = 666;
		print(mymap);
		print(map2);
		std::cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl;
		print(mymap);
		print(map2);
		std::cout << std::endl;
		std::cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl;
		print(mymap);
		print(map2);
		std::cout << std::endl;
		std::cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl;
		print(mymap);
		print(map2);
		std::cout << std::endl;
		std::cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl;
		print(mymap);
		print(map2);
		std::cout << std::endl;
		std::cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl;
		print(mymap);
		print(map2);
		std::cout << std::endl;
		mymap.empty();

	}
	std::cout << "performance: " << get_time() - timer << "ms" << std::endl;

}
