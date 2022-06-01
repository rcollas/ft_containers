#ifndef FT_CONTAINERS_TMP_IS_SAME_HPP
#define FT_CONTAINERS_TMP_IS_SAME_HPP

namespace ft {
//	template<class T, T v>
//	struct integral_constant {
//		typedef ::ft::integral_constant<bool, true> true_type;
//		typedef ::ft::integral_constant<bool, false> false_type;
//		typedef T value_type;
//		typedef integral_constant type;
//		operator value_type() const { return value; }
//		value_type operator()() const { return value; }
//
//		static const T value = v;
//
//	};
//
//	template<class T, class U>
//	struct is_same : ft::integral_constant<T, 0>::false_type {};
//
//	template<class T>
//	struct is_same<T, T> : ft::integral_constant<T, 0>::true_type {};
	template <class T, class U>
	struct is_same { static const bool value = false; };

	template <class T>
	struct is_same<T, T> { static const bool value = true; };
}

#endif
