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
			explicit vector(size_type count,
							 const T& value = T(),
							 const Allocator& alloc = Allocator()) {
				this->_alloc = Allocator(alloc);
				this->_capacity = count * 2;
				this->_start = this->_alloc.allocate(count * 2);
				this->_end = this->_start + this->_size;
				this->_size = count;
				for (size_type i = 0; i < count; i++) {
					this->_alloc.construct((_start + i), value);
				}
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
					this->_end += this->_size;
					std::cout << "pos = " << _size << std::endl;
				} else {
					std::cout << "new alloc" << std::endl;
					vector<T> ret((this->_size + 1) * 2);

					for (size_type i = 0; i < this->_size; i++) {
						ret[i] = (*this)[i];
					}
					ret[this->_size] = value;
					this->_size++;
					ret._size = this->_size;
					for (size_type i = 0; i < this->_size; i++) {
						this->_alloc.destroy(this->_start + i);
					}
					this->_alloc.deallocate(this->_start, this->_size);
					*this = ret;
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
//			size_type _maxSize;
			pointer _end;

	};
}

#endif
