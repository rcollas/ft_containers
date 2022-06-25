#ifndef FT_CONTAINERS_TMP_EQUAL_HPP
#define FT_CONTAINERS_TMP_EQUAL_HPP

#include <iostream>

namespace ft {

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1,
			   InputIt2 first2) {

		for (; first1 != last1; first1++, first2++) {
			if (*first1 != *first2)
				return false;
		}
		return true;
	};

}

#endif