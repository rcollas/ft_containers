#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include "ReverseIterator.hpp"
#include "Iterator.hpp"
#include "RandomAccessIterator.hpp"
#include "enable_if.hpp"
#include "is_same.hpp"
#include <stdexcept>
#include <cstdio>
#include <cstdlib>

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

			/********* MEMBER TYPES ***********/
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

			/********** CONSTRUCTOR ********/
			vector() {

				this->_alloc = Allocator();
				this->_capacity = 0;
				this->_start = 0;
				this->_end = 0;
				this->_size = 0;
			};
			explicit vector( const Allocator& alloc ) {
				this->_alloc = alloc;
				this->_capacity = 0;
				this->_start = 0;
				this->_end = 0;
				this->_size = 0;
			};
			explicit vector(size_type count,
							 const T& value = T(),
							 const Allocator& alloc = Allocator()) {
				this->_alloc = alloc;
				this->_capacity = count * 2;
				this->_start = this->_alloc.allocate(count * 2);
				this->_size = count;
				this->_end = this->_start + this->_size;
				for (size_type i = 0; i < this->_capacity; i++) {
					this->_alloc.construct((_start + i), value);
				}
			};
			template <class InputIt>
			vector(InputIt first, InputIt last,
					const Allocator& alloc = Allocator(),
					typename ft::enable_if<!ft::is_same<InputIt, int>::value>::type* = 0) {
				this->_alloc = alloc;
//				this->_size = last - first;
//				this->_capacity = this->_size * 2;
//				this->_start = this->_alloc.allocate(this->_capacity);
//				this->_end = this->_start + this->_size;
				assign(first, last);
			};

			vector(const vector& other)
				:
					_alloc(Allocator()),
					_start(0),
					_size(0),
					_capacity(0),
					_end(0) {
				*this = other;
			};

			/********** DESTRUCTOR **********/

			~vector() {
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_start + i);
				}
				this->_alloc.deallocate(this->_start, this->_capacity);
			}

			/************* ASSIGNMENT OPERATOR *********/

			vector& operator=(const vector& other) {
				if (this->_start) {
					for (size_type i = 0; i < this->_size; i++) {
						this->_alloc.destroy(this->_start + i);
					}
					this->_alloc.deallocate(this->_start, this->_capacity);
				}
				this->_alloc = other._alloc;
				this->_size = other._size;
				this->_capacity = other._capacity;
				this->_start = this->_alloc.allocate(this->_capacity);
				this->_end = this->_start + this->_size;
				for (size_type i = 0; i < this->_capacity; i++) {
					this->_alloc.construct(this->_start + i, other[i]);
				}
				return *this;
			};

			void assign(size_type count, const T& value) {
				if (count > this->_capacity) {
					this->_capacity == 0 ? reserve(count) : reserve(this->_capacity * 2);
				}
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_start + i);
				}
				this->_size = count;
				this->_end = this->_start + count - 1;
				for (size_type i = 0; i < count; i++) {
					this->_alloc.construct(this->_start + i, value);
				}
			}

			template< class InputIt >
			void assign(InputIt first, InputIt last,
						typename ft::enable_if<!ft::is_same<InputIt, int>::value>::type* = 0) {
				size_type count = last - first;
				InputIt tmp = first;

				if (count > this->_capacity) {
					this->_capacity == 0 ? reserve(count) : reserve(this->_capacity * 2);
				}
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_start + i);
				}
				this->_size = count;
				for (size_type i = 0; i < count; i++) {
					this->_alloc.construct(this->_start + i, *tmp);
				}
			}

			allocator_type get_allocator() const { return this->_alloc; }

			/************* ELEMENT ACCESS ***********/

			reference at( size_type pos ) {
				if (pos >= capacity()) {
					throw std::out_of_range("Index out of range");
				}
				return *(this->_start + pos);
			};
			const_reference at( size_type pos ) const {
				if (pos >= capacity()) {
					throw std::out_of_range("Index out of range");
				}
				return *(this->_start + pos);
			};

			reference operator[]( size_type pos ) { return *(this->_start + pos); };
			const_reference operator[]( size_type pos ) const { return *(this->_start + pos); };

			reference front() { return *(this->_start); }
			const_reference front() const { return *(this->_start); }

			reference back() { return *(this->_end); }
			const_reference back() const { return *(this->_end); }

			T* data(){ return this->_start; }
			const T* data() const { return this->_start; }

			/************ ITERATORS *************/

			iterator begin() {
				return iterator(this->_start);
			}
			iterator end() {
				return iterator(this->_end + 1);
			}
			reverse_iterator rend() {
				return reverse_iterator(this->begin()--);
			}
			reverse_iterator rbegin() {
				return reverse_iterator(this->end()--);
			}

			/*************** CAPACITY ********************/

			void reserve(size_type new_cap) {
				if (new_cap > this->_alloc.max_size()) {
					throw std::length_error("Your allocation capacity exceed the maximum available size");
				}
				pointer prev_start = this->_start;
				this->_start = this->_alloc.allocate(new_cap);
				this->_capacity = new_cap;
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.construct(this->_start + i, *(prev_start + i));
					this->_alloc.destroy(prev_start + i);
				}
			}

			size_type size() { return this->_size; }
			size_type capacity() { return this->_capacity; }

			void push_back(const T& value) {
				if (this->_size != this->_capacity) {
					this->_alloc.construct(this->_start + this->_size, value);
					this->_size++;
					this->_end += 1;
				} else {
					this->_capacity == 0 ? reserve(1) : reserve(this->_capacity * 2);
					this->_alloc.construct(this->_start + this->_size, value);
					this->_size++;
					this->_end++;
				}
			};

		private:
			Allocator _alloc;
			pointer _start;
			size_type _size;
			size_type _capacity;
			pointer _end;

	};
}

#endif
