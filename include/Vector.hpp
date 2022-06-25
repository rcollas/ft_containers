#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include "utils/ReverseIterator.hpp"
#include "utils/Iterator.hpp"
#include "utils/RandomAccessIterator.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_same.hpp"
#include "utils/equal.hpp"
#include "utils/lexicographical_compare.hpp"
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <sstream>

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class vector {



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

		private:
			Allocator _alloc;
			size_type _capacity;
			pointer _start;
			size_type _size;
			pointer _end;

		public:

			/********** CONSTRUCTOR ********/

			vector()
			:
			_alloc(Allocator()),
			_capacity(0),
			_start(0),
			_size(0),
			_end(0) {}

			explicit vector( const Allocator& alloc )
			:
			_alloc(alloc),
			_capacity(0),
			_start(0),
			_size(0),
			_end(0) {}

			explicit vector(size_type count,
							 const T& value = T(),
							 const Allocator& alloc = Allocator()) {
				this->_alloc = alloc;
				this->_capacity = count * 2;
				this->_start = this->_alloc.allocate(count * 2);
				this->_size = count;
				this->_end = this->_start + this->_size;
				for (size_type i = 0; i < count; i++) {
					this->_alloc.construct((_start + i), value);
				}
			}

			template <class InputIt>
			vector(InputIt first, InputIt last,
					const Allocator& alloc = Allocator(),
					typename ft::enable_if<!ft::is_same<InputIt, int>::value>::type* = 0)
					:
					_alloc(alloc),
					_capacity(0),
					_start(0),
					_size(0),
					_end(0) { assign(first, last); };

			vector(const vector& other)
			:
			_alloc(Allocator()),
			_capacity(0),
			_start(0),
			_size(0),
			_end(0) { *this = other; };

			/********** DESTRUCTOR **********/

			~vector() {
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_start + i);
				}
				this->_alloc.deallocate(this->_start, this->_capacity);
			}

			/************* ASSIGNMENT OPERATOR *********/

			vector& operator=(const vector& other) {
				if (*this != other) {
					if (this->_start) {
						for (size_type i = 0; i < this->_size; i++) {
							this->_alloc.destroy(this->_start + i);
						}
						this->_alloc.deallocate(this->_start, this->_capacity);
					}
					this->_alloc = other._alloc;
//					this->assign(other.begin(), other.end());
					this->_size = other._size;
					this->_capacity = other._capacity;
					this->_start = this->_alloc.allocate(this->_capacity);
					this->_end = this->_start + this->_size;
					for (size_type i = 0; i < other.size(); i++) {
						this->_alloc.construct(this->_start + i, other[i]);
					}
				}
				return *this;
			};

			void assign(size_type count, const T& value) {

				this->clear();
				if (count > this->_capacity) {
					this->_capacity == 0 ? reserve(count) :
											reserve(this->_capacity * 2);
				}
				while (this->_size < count) {
					this->push_back(value);
				}
			}

			template< class InputIt >
			void assign(InputIt first, InputIt last,
						typename ft::enable_if<!ft::is_same<InputIt, int>::value>::type* = 0) {
				size_type count = last - first;
				InputIt tmp = first;

				this->clear();
				if (count > this->_capacity) {
					this->_capacity == 0 ? reserve(count) :
											reserve(this->_capacity * 2);
				}
				while (this->_size < count) {
					this->push_back(*tmp++);
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

			reference back() { return *(this->_end - 1); }
			const_reference back() const { return *(this->_end - 1); }

			T* data() { return this->_start; }
			const T* data() const { return this->_start; }

			/*************** ITERATORS ****************/

			iterator begin() {
				return iterator(this->_start);
			}
			iterator end() {
				return iterator(this->_end);
			}
			reverse_iterator rend() {
				return reverse_iterator(this->begin()--);
			}
			reverse_iterator rbegin() {
				return reverse_iterator(this->end()--);
			}

			const_iterator begin() const {
				return const_iterator(this->_start);
			}
			const_iterator end() const {
				return const_iterator(this->_end);
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(this->begin()--);
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(this->end()--);
			}

			/****************** CAPACITY ********************/

			bool empty() const { return this->begin() == this->end(); }

			size_type size() const { return this->_size; }
			size_type max_size() const { return this->_alloc.max_size(); }
			size_type capacity() const { return this->_capacity; }

			void reserve(size_type new_cap) {
				if (new_cap > this->max_size()) {
					throw std::length_error("Your allocation capacity exceed the maximum available size");
				}
				pointer prev_start = this->_start;
				this->_start = this->_alloc.allocate(new_cap);
				this->_capacity = new_cap;
				this->_end = this->_start + this->_size;
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.construct(this->_start + i, *(prev_start + i));
					this->_alloc.destroy(prev_start + i);
				}
				this->_alloc.deallocate(prev_start, this->_capacity);
			}

			/************************ MODIFIERS ***********************/

			void clear() {
				while (this->_size > 0) {
					this->_alloc.destroy(this->_start + --this->_size);
				}
				this->_end = this->_start;
			}

			iterator insert(iterator pos, const T& value) {

				size_type index = &*pos - this->_start;
				if (this->size() == 0) {
					this->push_back(value);
				} else {
					if (this->size() == this->capacity()) {
						reserve(this->capacity() * 2);
					}
					for (size_type i = this->size(); i > index; i--) {
						this->_alloc.construct(this->_start + i, *(this->_start + i - 1));
						this->_alloc.destroy(this->_start + i - 1);
					}
					this->_size++;
					this->_end++;
					this->_alloc.construct(this->_start + index, value);
				}
				return iterator(this->_start + index);
			}

			void insert(iterator pos, size_type count, const T& value) {
				for (size_type i = 0; i < count; i++) {
					this->insert(pos + i, value);
				}
			}

			template<class InputIt>
			void insert(iterator pos, InputIt first, InputIt last,
						typename ft::enable_if<!ft::is_same<InputIt, int>::value>::type* = 0) {

				size_type count = last - first;
				ft::vector<value_type> tmp(first, last);
				size_type position = pos - begin();

				while (count--) {
					this->insert(begin() + position, tmp[count]);
				}
			}

			iterator erase(iterator pos) {
				iterator ret = pos == this->end() ? this->end() : pos;
				while (pos + 1 != this->end()) {
					*pos = *(pos + 1);
					pos++;
				}
				this->pop_back();
				return ret;
			}

			iterator erase(iterator first, iterator last) {
				iterator *ret = last == this->end() ? 0 : &last;
				int i = 0;
				while (first + i != last) {
					this->erase(iterator(first));
					i++;
				}
				return ret == 0 ? (this->end()) : *ret;
			}

			void push_back(const T& value) {
				if (this->_size != this->_capacity) {
					this->_alloc.construct(this->_start + this->_size, value);
					this->_size++;
					this->_end++;
				} else {
					this->_capacity == 0 ? reserve(1) : reserve(this->_capacity * 2);
					this->_alloc.construct(this->_start + this->_size, value);
					this->_size++;
					this->_end++;
				}
			};

			void pop_back() {
				if (this->_size) {
					this->_alloc.destroy(this->_end - 1);
					this->_end--;
					this->_size--;
				}
			}

			void resize(size_type count, T value = T()) {
				if (count > this->_capacity) {
					reserve(this->_capacity * 2);
				}
				while (count > this->_size) {
					this->push_back(value);
				}
				while (count < this->_size) {
					this->pop_back();
				}
			}

			void swap(vector& other) {
				vector tmp = other;
				other = *this;
				*this = tmp;
			}



	};

	template< class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& lhs,
					 const ft::vector<T,Alloc>& rhs ) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T,Alloc>& lhs,
					 const ft::vector<T,Alloc>& rhs) { return !(lhs == rhs); };

	template<class T, class Alloc>
	bool operator<(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T,Alloc>& lhs,
					 const ft::vector<T,Alloc>& rhs) {
		return lhs < rhs || lhs == rhs;
	};

	template<class T, class Alloc>
	bool operator>(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) {
		return lhs > rhs || lhs == rhs;
	};

	template<class T, class Alloc>
	void swap(ft::vector<T,Alloc>& lhs,
			   ft::vector<T,Alloc>& rhs) { lhs.swap(rhs); };
}

#endif
