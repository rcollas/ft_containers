#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include "ReverseIterator.hpp"


namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef  value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;

	};
}

#endif
