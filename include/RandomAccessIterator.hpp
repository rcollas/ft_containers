#ifndef FT_CONTAINERS_RANDOMACCESSITERATOR_HPP
#define FT_CONTAINERS_RANDOMACCESSITERATOR_HPP

#include "IteratorsTraits.hpp"

namespace ft {
	template <class Iter>
	class random_access_iterator {

		public:
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::reference reference;
			typedef typename iterator_traits<Iter>::iterator_category iterator_category;
			explicit random_access_iterator(pointer const &src) { this->_ptr = src; }
			pointer operator*() { return this->_ptr; };
			pointer operator--() { this->_ptr--; return this->_ptr; }
			pointer operator++() { this->_ptr++; return this->_ptr; }
			pointer operator!=(pointer const &rhs) { return this->_ptr == rhs; }
		private:
			pointer _ptr;
	};
}

#endif
