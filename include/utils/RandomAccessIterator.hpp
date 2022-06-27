#ifndef FT_CONTAINERS_RANDOMACCESSITERATOR_HPP
#define FT_CONTAINERS_RANDOMACCESSITERATOR_HPP

#include "IteratorsTraits.hpp"
#include "Iterator.hpp"

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
			explicit random_access_iterator(pointer const src) { this->_ptr = src; }
			random_access_iterator(iterator const &src) {
				*this = src;
			}
			iterator &operator=(iterator const &rhs) { this->_ptr = rhs._ptr; return *this; }
			reference operator[](size_t pos) { return this->_ptr[pos]; }

			long operator-(iterator const &rhs) {
				long i = 0;
				iterator tmp = *this;
				if (tmp._ptr < rhs._ptr) while (tmp != rhs) {tmp++; i--;}
				else if (tmp._ptr > rhs._ptr) while (tmp != rhs) {tmp--; i++;};
				return i;
			}

			value_type &operator*() const { return *this->_ptr; };
			pointer &operator->() const { return (pointer*)0; };

			iterator &operator--() { this->_ptr--; return *this; }
			iterator operator--(int) { iterator tmp(*this) ; operator--(); return tmp; }
			iterator &operator++() { this->_ptr++; return *this; }
			iterator operator++(int) { iterator tmp(*this) ; operator++(); return tmp; }

			iterator operator+(int n) const { return iterator(this->_ptr + n) ;}
			iterator operator-(int n) const { return iterator(this->_ptr - n) ;}
			iterator &operator+=(difference_type n) { this->_ptr += n; return *this; }
			iterator &operator-=(difference_type n) { this->_ptr -= n; return *this; }

			bool operator==(iterator const &rhs) { return this->_ptr == rhs._ptr; }
			bool operator!=(iterator const &rhs) { return this->_ptr != rhs._ptr; }
			bool operator<(iterator const &rhs) { return this->_ptr < rhs._ptr; }
			bool operator>(iterator const &rhs) { return this->_ptr > rhs._ptr; }
			bool operator<=(iterator const &rhs) { return this->_ptr <= rhs._ptr; }
			bool operator>=(iterator const &rhs) { return this->_ptr >= rhs._ptr; }

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
}

#endif
