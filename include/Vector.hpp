#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include "ReverseIterator.hpp"
#include "Iterator.hpp"
#include "RandomAccessIterator.hpp"
#include <stdexcept>


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
					const Allocator& alloc = Allocator()) {
				this->_alloc = alloc;
				this->_size = range(first, last);
				this->_capacity = this->_size * 2;
				this->_start = this->_alloc.allocate(this->_capacity);
				this->_end = this->_start + this->_size;
				size_type i = 0;
				while (first != last) {
					this->_alloc.construct(this->_start + i, *first);
					first++;
					i++;
				}
			};

			vector( const vector& other )
				:
					_alloc(Allocator()),
					_start(0),
					_size(0),
					_capacity(0),
					_end(0) {
				*this = other;
			};

			~vector() {
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_start + i);
				}
				this->_alloc.deallocate(this->_start, this->_capacity);
			}

			vector& operator=( const vector& other ) {
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

			void push_back(const T& value) {
				if (this->_size != this->_capacity) {
					this->_alloc.construct(this->_start + this->_size, value);
					this->_size++;
					this->_end += 1;
				} else {
					vector<T> realloc((this->_capacity + 1) * 2);

					for (size_type i = 0; i < this->_size; i++) {
						realloc[i] = (*this)[i];
					}
					realloc[this->_size] = value;
					if (this->_capacity) {
						for (size_type i = 0; i < this->_size; i++) {
							this->_alloc.destroy(this->_start + i);
						}
						//this->_alloc.deallocate(this->_start, this->_capacity);
					}
					this->_size++;
					realloc._size = this->_size;
					*this = realloc;
				}
			};

			iterator begin() {
				return iterator(this->_start);
			}
			iterator end() {
				return iterator(this->_end + 1);
			}
			reverse_iterator rend() {
				return reverse_iterator(this->begin());
			}

			size_type size() { return this->_size; }
			size_type capacity() { return this->_capacity; }


		private:
			Allocator _alloc;
			pointer _start;
			size_type _size;
			size_type _capacity;
			pointer _end;

	};
}

#endif
