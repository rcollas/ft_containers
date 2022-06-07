#ifndef FT_CONTAINERS_TMP_VECTOR_ASSIGN_H
#define FT_CONTAINERS_TMP_VECTOR_ASSIGN_H

#include <vector>
#include "../../include/Vector.hpp"
#include "../googletest/googletest/include/gtest/gtest.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

class AssignVectorTest : public ::testing::Test {
	protected:
		AssignVectorTest() : foo(20), bar(20) {}
		void SetUp() override {
			srand(time(0));
			for (size_t i = 0; i < 20; i++) {
				int value = rand();
				foo.push_back(std::to_string(value));
				bar.push_back(std::to_string(value));
			}
		}
	ft::vector<std::string> foo;
	std::vector<std::string> bar;
};

TEST(vectorAssign, assignOnEmptyVector) {

	ft::vector<std::string> foo;
	std::vector<std::string> bar;

	foo.assign(10, "hello");
	bar.assign(10, "hello");
	ASSERT_EQ(foo.size(), bar.size());
	ASSERT_EQ(foo.capacity(), bar.capacity());
	for (size_t i = 0; i < foo.size(); i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST(vectorAssign, assignOnSmallerVector) {

	ft::vector<std::string> foo(10);
	std::vector<std::string> bar(10);

	foo.assign(20, "hello");
	bar.assign(20, "hello");
	ASSERT_EQ(foo.size(), bar.size());
	ASSERT_EQ(foo.capacity(), bar.capacity());
	for (size_t i = 0; i < foo.size(); i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, withIterator) {

	ft::vector<std::string> fizz;
	fizz.assign(foo.begin(), foo.end());

	std::vector<std::string> buzz;
	buzz.assign(bar.begin(), bar.end());

	ASSERT_EQ(fizz.size(), buzz.size());
	ASSERT_EQ(fizz.capacity(), buzz.capacity());
	for (size_t i = 0; i < fizz.size(); i++) {
		EXPECT_EQ(fizz[i], buzz[i]);
	}
}

TEST_F(AssignVectorTest, erasePos) {

	ft::vector<std::string>::iterator it = foo.erase(foo.begin() + 3);
	std::vector<std::string>::iterator ite = bar.erase(bar.begin() + 3);

	ASSERT_EQ(foo.size(), bar.size());
	ASSERT_EQ(*it, *ite);
	for (size_t i = 0; i < foo.size(); i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, eraseIterator) {
	ft::vector<std::string>::iterator it = foo.erase(foo.begin(), foo.end());
	std::vector<std::string>::iterator ite = bar.erase(bar.begin(), bar.end());

	ASSERT_EQ(foo.size(), bar.size());
	ASSERT_EQ(*it, *ite);
	for (size_t i = 0; i < foo.size(); i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, resize) {

	foo.resize(100);
	bar.resize(100);
	ASSERT_EQ(foo.size(), bar.size());
	for (size_t i = 0; i < foo.size(); i++) {
		ASSERT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, resizeWithValue) {

	foo.resize(100, "bazz");
	bar.resize(100, "bazz");
	ASSERT_EQ(foo.size(), bar.size());
	for (size_t i = 0; i < foo.size(); i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, insertPos) {

	foo.insert(foo.begin(), "zapp");
	bar.insert(bar.begin(), "zapp");
	ASSERT_EQ(foo.size(), bar.size());
	for (size_t i = 0; i < foo.size() - 1; i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, insertCount) {
	foo.insert(foo.begin() + 10, 10, "zlut");
	bar.insert(bar.begin() + 10, 10, "zlut");
	ASSERT_EQ(foo.size(), bar.size());
	for (size_t i = 0; i < foo.size() - 1; i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, insertIterator) {
	foo.insert(foo.begin() + 10, foo.begin(), foo.end() - 1);
	bar.insert(bar.begin() + 10, bar.begin(), bar.end() - 1);
	ASSERT_EQ(foo.size(), bar.size());
	for (size_t i = 0; i < foo.size() - 1; i++) {
		EXPECT_EQ(foo[i], bar[i]);
	}
}

TEST_F(AssignVectorTest, end) {
	EXPECT_EQ(*(foo.end() - 1), *(bar.end() - 1));
}

#endif
