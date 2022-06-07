#ifndef FT_CONTAINERS_TMP_EQUAL_HPP
#define FT_CONTAINERS_TMP_EQUAL_HPP

#include <iostream>

namespace ft {

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1,
			   InputIt2 first2) {

		for (size_t i = 0; &(first1[i]) != &(last1[i]); i++) {
			if (first1[i] != first2[i]) {
				return false;
			}
		}
		return true;
	};

}

#endif