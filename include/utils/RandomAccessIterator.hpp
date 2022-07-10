#ifndef FT_CONTAINERS_RANDOMACCESSITERATOR_HPP
#define FT_CONTAINERS_RANDOMACCESSITERATOR_HPP

#include "IteratorsTraits.hpp"
#include "Iterator.hpp"
#include <iostream>

namespace ft {
	template <class T>
	class random_access_iterator {

		public:
			typedef typename iterator_traits<T>::pointer pointer;
			typedef typename iterator_traits<T>::value_type value_type;
			typedef typename iterator_traits<T>::difference_type difference_type;
			typedef typename iterator_traits<T>::reference reference;
			typedef typename iterator_traits<T>::iterator_category iterator_category;
			typedef random_access_iterator iterator;

			explicit random_access_iterator() { this->_ptr = 0; }
			explicit random_access_iterator(pointer const src) : _ptr(src) {}
			random_access_iterator(const iterator &src) {
				*this = src;
			}
			template<class Iter>
			random_access_iterator(const random_access_iterator<Iter>& i) : _ptr(i.base()) {};

			const pointer
			base() const { return this->_ptr; }

			iterator &operator=(iterator const &rhs) { this->_ptr = rhs._ptr; return *this; }
			reference operator[](size_t pos) { return this->_ptr[pos]; }
			reference operator*() const { return *this->_ptr; };
			pointer operator->() const { return this->_ptr; };

			iterator &operator--() { this->_ptr--; return *this; }
			iterator operator--(int) { iterator tmp(*this) ; operator--(); return tmp; }
			iterator &operator++() { this->_ptr++; return *this; }
			iterator operator++(int) { iterator tmp(*this) ; operator++(); return tmp; }

			iterator operator+(const difference_type& n) const { return iterator(this->_ptr + n) ;}
			difference_type operator+(const iterator& rhs) const { return this->_ptr + rhs._ptr; }
			iterator operator-(const difference_type& n) const { return iterator(this->_ptr - n) ;}
			difference_type operator-(const iterator& rhs) const { return this->_ptr - rhs._ptr; }
			iterator &operator+=(difference_type n) { this->_ptr += n; return *this; }
			iterator &operator-=(difference_type n) { this->_ptr -= n; return *this; }

		private:
			pointer _ptr;
	};

	template <class T>
	size_t range(random_access_iterator<T> start, random_access_iterator<T> end) {
		size_t i = 0;
		while (start != end) {
			i++;
			start++;
		}
		return i;
	}


	template<typename IteratorL, typename IteratorR>
	inline bool
	operator==(const random_access_iterator<IteratorL>& lhs,
			   const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator!=(const random_access_iterator<IteratorL>& lhs,
			   const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() != rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<(const random_access_iterator<IteratorL>& lhs,
			  const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() < rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>(const random_access_iterator<IteratorL>& lhs,
			  const random_access_iterator<IteratorR>& rhs)
	{ return lhs.base() > rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<=(const random_access_iterator<IteratorL>& lhs,
			   const random_access_iterator<IteratorR>& rhs)
	{ return lhs.base() <= rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>=(const random_access_iterator<IteratorL>& lhs,
			   const random_access_iterator<IteratorR>& rhs)
	{ return lhs.base() >= rhs.base(); }

	template<class IteratorL, class IteratorR>
	inline typename random_access_iterator<IteratorL>::difference_type
	operator-(const random_access_iterator<IteratorL>& lhs,
				const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() - rhs.base();
	}

	template<class IteratorL, class IteratorR>
	inline typename random_access_iterator<IteratorL>::difference_type
	operator+(const random_access_iterator<IteratorL>& lhs,
			  const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() + rhs.base();
	}

	template<typename Iterator>
	inline random_access_iterator<Iterator>
	operator+(typename random_access_iterator<Iterator>::difference_type lhs,
				const random_access_iterator<Iterator>& rhs) {
		return random_access_iterator<Iterator>(rhs.base() + lhs);
	}

	template<typename Iterator>
	inline random_access_iterator<Iterator>
	operator-(typename random_access_iterator<Iterator>::difference_type lhs,
			  const random_access_iterator<Iterator>& rhs) {
		return random_access_iterator<Iterator>(rhs.base() - lhs);
	}


}

#endif
