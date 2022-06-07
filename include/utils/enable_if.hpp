#ifndef FT_CONTAINERS_TMP_ENABLE_IF_HPP
#define FT_CONTAINERS_TMP_ENABLE_IF_HPP

namespace ft {
	template<bool B, class T = void>
	struct enable_if {
	};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

#endif