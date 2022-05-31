#ifndef FT_CONTAINERS_TMP_VECTOR_ASSIGN_H
#define FT_CONTAINERS_TMP_VECTOR_ASSIGN_H

#include <vector>
#include "../../include/Vector.hpp"
#include "../googletest/googletest/include/gtest/gtest.h"

TEST(vectorAssign, assignOnEmptyVector) {

	ft::vector<int> foo;
	std::vector<int> bar;
	ASSERT_EQ(foo.size(), bar.size());
}

#endif
