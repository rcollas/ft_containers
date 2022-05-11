#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include "ReverseIterator.hpp"
#include "Iterator.hpp"
#include "RandomAccessIterator.hpp"


namespace ft {

//	template <class Iter>
//	class vectorIterator : public ft::iterator_traits<Iter> {
//		public:
//			explicit vectorIterator(pointer const &src) {_ptr = src;}
//			pointer operator*() const {return this->_ptr; };
//			pointer operator++() {this->_ptr++; return *this; };
//		private:
//			pointer _ptr;
//	};

	template <class T, class Allocator = std::allocator<T> >
	class vector {
//			friend class iterator<T, vector>;
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef  value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename ft::random_access_iterator<pointer> iterator;
			typedef typename ft::random_access_iterator<pointer> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

//			vector() {
//				this->_alloc = Allocator();
//				this->_start = this->_alloc.allocate(10);
//				this->_size = 10;
//				this->_end = this->_start + this->_size;
//				std::cout << "start = " << this->_start << std::endl;
//				std::cout << "end = " << this->_end << std::endl;
//			};
//			explicit vector(const Allocator& alloc){};
			explicit vector(size_type count,
							 const T& value = T(),
							 const Allocator& alloc = Allocator()) {
				this->_alloc = Allocator(alloc);
				this->_size = count;
				this->_start = this->_alloc.allocate(count * 2);
				this->_end = this->_start + this->_size;
				for (size_type i = 0; i < count; i++) {
					this->_alloc.construct((_start + i), value);
				}
				std::cout << "size = " << this->_alloc.max_size() << std::endl;
			};
//			template<class InputIt>
//			vector(InputIt first, InputIt last,
//					const Allocator& alloc = Allocator()) {};
//			vector(const vector& other) {};

			void push_back(const T& value) {
				if (this->_size != this->_maxSize) {
					this->_alloc.construct(_start + _size, value);
					this->_end += this->_size;
				}
			};

			iterator begin() {
				return iterator(this->_start);
			}
			iterator end() {
				return iterator(this->_end);
			}
			reverse_iterator rend() {
				return reverse_iterator(this->begin());
			}



		private:
			Allocator _alloc;
			pointer _start;
			size_type _size;
			size_type _maxSize;
			pointer _end;

	};
}

#endif
