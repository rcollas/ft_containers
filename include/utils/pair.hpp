#ifndef FT_CONTAINERS_TMP_PAIR_HPP
#define FT_CONTAINERS_TMP_PAIR_HPP

namespace ft {

	template<class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		pair() : _first(first_type()), _second(second_type()) {};
		pair(const T1& x, const T2& y) : _first(x), _second(y) {};

		template< class U1, class U2 >
		pair(const pair<U1, U2>& p) : _first(p._first), _second(p._second) {};

		pair& operator=(const pair& other) {
			this->_first = other._first;
			this->_second = other._second;
			return *this;
		};

		first_type _first;
		second_type _second;
	};

	template<class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 t, T2 u) {
		return ft::pair<T1, T2>(t , u);
	};

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (lhs._first == rhs._first) && (lhs._second == rhs._second);
	};

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return !(lhs == rhs);
	};

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (lhs._first < rhs._first) || (lhs._second < rhs._second);
	};

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (lhs._first <= rhs._first) || (lhs._second <= rhs._second);
	};

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (lhs._first > rhs._first) || (lhs._second > rhs._second);
	};

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (lhs._first >= rhs._first) || (lhs._second >= rhs._second);
	};

}

#endif
