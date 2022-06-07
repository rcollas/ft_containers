#ifndef FT_CONTAINERS_TMP_IS_SAME_HPP
#define FT_CONTAINERS_TMP_IS_SAME_HPP

namespace ft {

	template <class T, class U>
	struct is_same { static const bool value = false; };

	template <class T>
	struct is_same<T, T> { static const bool value = true; };
}

#endif
