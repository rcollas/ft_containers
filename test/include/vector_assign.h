#ifndef FT_CONTAINERS_TMP_VECTOR_ASSIGN_H
#define FT_CONTAINERS_TMP_VECTOR_ASSIGN_H

#include <vector>
#include "../../include/Vector.hpp"
#include "../googletest/googletest/include/gtest/gtest.h"
#include <ctime>
#include <cstdlib>

class AssignVectorTest : public ::testing::Test {
	protected:
		void SetUp() override {
			srand(time(0));
			for (size_t i = 0; i < foo.size(); i++) {
				int value = rand();
				foo.push_back(value);
				bar.push_back(value);
			}
		}
	ft::vector<int> foo;
	std::vector<int> bar;
};

TEST(vectorAssign, assignOnEmptyVector) {

	ft::vector<int> foo;
	std::vector<int> bar;

	foo.assign(10, 15);
	bar.assign(10, 15);
	ASSERT_EQ(foo.size(), bar.size());
	ASSERT_EQ(foo.capacity(), bar.capacity());
	for (size_t i = 0; i < foo.size(); i++) {
			ASSERT_EQ(foo[i], bar[i]);
	}
}

TEST(vectorAssign, assignOnSmallerVector) {

	ft::vector<int> foo(10);
	std::vector<int> bar(10);

	foo.assign(20, 15);
	bar.assign(20, 15);
	ASSERT_EQ(foo.size(), bar.size());
	ASSERT_EQ(foo.capacity(), bar.capacity());
	for (size_t i = 0; i < foo.size(); i++) {
		ASSERT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, withIterator) {

	ft::vector<int> fizz;
	fizz.assign(foo.begin(), foo.end());

	std::vector<int> buzz;
	buzz.assign(bar.begin(), bar.end());

	ASSERT_EQ(fizz.size(), buzz.size());
	ASSERT_EQ(fizz.capacity(), buzz.capacity());
	for (size_t i = 0; i < fizz.size(); i++) {
		ASSERT_EQ(fizz[i], buzz[i]);
	}
}

#endif
