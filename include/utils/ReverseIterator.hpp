#ifndef FT_CONTAINERS_REVERSEITERATOR_HPP
#define FT_CONTAINERS_REVERSEITERATOR_HPP

#include "IteratorsTraits.hpp"

namespace ft {

	template<class Iter>
	class reverse_iterator : public Iter {
		public:
			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;

			reverse_iterator() : current(iterator_type()) {}

			explicit reverse_iterator(iterator_type x) : current(Iter(x)) {}

			reverse_iterator(const reverse_iterator& x) : current(x.current) {}

			template<class U>
			reverse_iterator(const reverse_iterator<U> &other) : current(other.base()) {}

			template<class U>
			reverse_iterator
			&operator=(const reverse_iterator<U> &other) { this->current = other.current; };

			iterator_type
			base() const { return current; };

			reference operator*() const { Iter tmp = current; return *(--tmp); };
			pointer operator->() const { return &(operator*()); };

			/*unspecified*/reverse_iterator &operator[](difference_type n) const { base()[-n-1]; };

			reverse_iterator& operator++() { --current; return *this; };
			reverse_iterator& operator--() { ++current; return *this; };
			reverse_iterator operator++(int) {reverse_iterator tmp = *this; ++*this; return tmp; };
			reverse_iterator operator--(int) {reverse_iterator tmp = *this; --*this; return tmp; };
			reverse_iterator& operator+(difference_type n) const { return reverse_iterator(base() - n); };
			reverse_iterator& operator-(difference_type n) const { return reverse_iterator(base() + n); };
			reverse_iterator& operator+=(difference_type n) { base() -= n; return *this; };
			reverse_iterator& operator-=(difference_type n) { base() += n; return *this; };


		protected:
			iterator_type current;

	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class IteratorA, class IteratorB>
	bool operator!=(const reverse_iterator<IteratorA> &lhs,
					const reverse_iterator<IteratorB> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() <= rhs.base());
	}


	template <class Iterator>
	reverse_iterator<Iterator>	operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator> &rev_it) {
		return (rev_it + n);
	}


	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator> &lhs,
			const reverse_iterator<Iterator> &rhs) {
		return (rhs.base() - lhs.base());
	}


}

#endif
