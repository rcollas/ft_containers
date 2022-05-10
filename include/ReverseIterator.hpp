#ifndef FT_CONTAINERS_REVERSEITERATOR_HPP
#define FT_CONTAINERS_REVERSEITERATOR_HPP

#include "IteratorsTraits.hpp"

namespace ft {
	template<class Iter>
	class reverse_iterator {
		public:
			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;

			reverse_iterator() : Iter() {};
			explicit reverse_iterator(iterator_type x) : Iter(x) {};

			template<class U>
			reverse_iterator(const reverse_iterator<U> &other) : Iter(other) {};

			template<class U>
			reverse_iterator &operator=(const reverse_iterator<U> &other) { this->current = other.current; };

			iterator_type base() const { return current.base(); };

			reference operator*() const { Iter tmp = this->current; return *--tmp; };
			pointer operator->() const { return std::__addressof(operator*()); };

			/*unspecified*/reverse_iterator &operator[](difference_type n) const { base()[-n-1]; };

			reverse_iterator& operator++() { --base(); return *this; };
			reverse_iterator& operator--() { ++base(); return *this; };
			reverse_iterator& operator++(int) {Iter tmp = *this; base()++; return tmp; };
			reverse_iterator& operator--(int) {Iter tmp = *this; base()--; return tmp; };
			reverse_iterator& operator+(difference_type n) const { return reverse_iterator(base() - n); };
			reverse_iterator& operator-(difference_type n) const { return reverse_iterator(base() + n); };
			reverse_iterator& operator+=(difference_type n) { base() -= n; return *this; };
			reverse_iterator& operator-=(difference_type n) { base() += n; return *this; };


		protected:
			Iter current;

		template< class Iterator1, class Iterator2 >
		friend bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
								const ft::reverse_iterator<Iterator2>& rhs ) { return lhs.base() == rhs.base(); };
		template< class Iterator1, class Iterator2 >
		friend bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
								const ft::reverse_iterator<Iterator2>& rhs ) { return lhs.base() != rhs.base(); };
		template< class Iterator1, class Iterator2 >
		friend bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
								const ft::reverse_iterator<Iterator2>& rhs ) { return lhs.base() < rhs.base(); };
		template< class Iterator1, class Iterator2 >
		friend bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
								const ft::reverse_iterator<Iterator2>& rhs ) { return lhs.base() <= rhs.base(); };
		template< class Iterator1, class Iterator2 >
		friend bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
								const ft::reverse_iterator<Iterator2>& rhs ) { return lhs.base() > rhs.base(); };
		template< class Iterator1, class Iterator2 >
		friend bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
								const ft::reverse_iterator<Iterator2>& rhs ) { return lhs.base() >= rhs.base(); };

		friend reverse_iterator<Iter>
		operator+( typename reverse_iterator<Iter>::difference_type n,
				   const reverse_iterator<Iter>& it ) { reverse_iterator<Iter>(it.base() - n); };

		template< class Iterator >
		typename reverse_iterator<Iterator>::difference_type
		friend operator-( const reverse_iterator<Iterator>& lhs,
				   const reverse_iterator<Iterator>& rhs ) { return rhs.base() - lhs.base(); };
	};
}

#endif
