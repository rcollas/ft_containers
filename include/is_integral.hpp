#ifndef FT_CONTAINERS_TMP_IS_INTEGRAL_HPP
#define FT_CONTAINERS_TMP_IS_INTEGRAL_HPP

#include <type_traits>

namespace ft {
	template<class T>
	struct is_integral {
		static constexpr T value = v;

		using value_type = T;
		using type = integral_constant; // using injected-class-name
		constexpr operator value_type() const noexcept { return value; }
		constexpr value_type operator()() const noexcept { return value; }
	};
}

#endif
