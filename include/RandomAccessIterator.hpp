#ifndef FT_CONTAINERS_RANDOMACCESSITERATOR_HPP
#define FT_CONTAINERS_RANDOMACCESSITERATOR_HPP

#include "IteratorsTraits.hpp"
#include "Iterator.hpp"

namespace ft {
	template <class T>
	class random_access_iterator/* : iterator<random_access_iterator_tag, T>*/ {

		public:
			typedef typename iterator_traits<T>::pointer pointer;
			typedef typename iterator_traits<T>::value_type value_type;
			typedef typename iterator_traits<T>::difference_type difference_type;
			typedef typename iterator_traits<T>::reference reference;
			typedef typename iterator_traits<T>::iterator_category iterator_category;

			explicit random_access_iterator(pointer const &src) { this->_ptr = src; }
			random_access_iterator &operator=(random_access_iterator const &rhs) { this->_ptr = rhs._ptr; return *this; }

			value_type &operator*() const { return *this->_ptr; };
			pointer &operator->() const { return (pointer*)0; };
			pointer &operator--() { this->_ptr--; return this->_ptr; }
			pointer &operator--(int) { pointer tmp = this->_ptr; this->_ptr--; return tmp; }
			pointer &operator++() { this->_ptr++; return this->_ptr; }
			pointer &operator++(int) { pointer tmp = this->_ptr; this->_ptr++; return tmp; }
			bool operator!=(random_access_iterator const &rhs) { return this->_ptr != rhs._ptr; }

		private:
			pointer _ptr;
	};
}

#endif
