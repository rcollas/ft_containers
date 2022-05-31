#ifndef FT_CONTAINERS_TMP_VECTOR_ASSIGN_H
#define FT_CONTAINERS_TMP_VECTOR_ASSIGN_H

#include <vector>
#include "../../include/Vector.hpp"
#include "../googletest/googletest/include/gtest/gtest.h"

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

#endif
