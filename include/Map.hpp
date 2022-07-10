#ifndef FT_CONTAINERS_TMP_MAP_HPP
#define FT_CONTAINERS_TMP_MAP_HPP

#include <memory>
#include "utils/ReverseIterator.hpp"
#include "utils/Iterator.hpp"
#include "utils/RandomAccessIterator.hpp"
#include "utils/pair.hpp"
#include "utils/RBTree.hpp"
#include <vector>

namespace ft {

	template<
			class Key,
			class Type,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, Type> >
	> class map {


		public:
			typedef Key									key_type;
			typedef typename ft::pair<const Key, Type>	value_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;


		typedef RBTree<key_type, value_type, std::_Select1st<value_type>, key_compare, allocator_type> RBTree;

		public:
			typedef Type 									mapped_type;
			typedef typename std::size_t					size_type;
			typedef typename std::ptrdiff_t					difference_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename RBTree::iterator				iterator;
			typedef typename RBTree::const_iterator			const_iterator;
			typedef typename RBTree::reverse_iterator		reverse_iterator;
			typedef typename RBTree::const_reverse_iterator	const_reverse_iterator;

		private:
			key_compare	_compare;
			RBTree		_tree;

		public:
			class value_compare {
				protected:
					Compare comp;

				public :
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					value_compare() : comp(Compare()) {}
					bool
					operator()( const value_type& lhs,
							const value_type& rhs ) const {
						return comp(lhs.first, rhs.first);
					};
			};

		public:

			/************* CONSTRUCTOR ******************/

			map()
			: _tree(RBTree(_compare)) {};

			explicit map(const Compare& comp,
						  const Allocator& alloc = Allocator())
						  : _tree(RBTree(comp, alloc)) {};

			template< class InputIt >
				map(InputIt first, InputIt last,
					 const Compare& comp = Compare(),
					 const Allocator& alloc = Allocator())
					 : _tree(RBTree(comp, alloc))
					 { _tree.insertUnique(first, last); };

			~map() {}


			map& operator=( const map& other ) {
				if (this != &other) {
					this->_tree = other._tree;
					this->_compare = other._compare;
				}
				return *this;
			}

			allocator_type
			get_allocator() const {
				return this->_tree.getAllocator();
			}



			void
			print() {
				this->_tree.print();
				std::cout << std::endl;
			}



			/********** ELEMENT ACCESS ************/

			mapped_type&
			at(const Key& key) {
				return _tree.find(key)->second;
			}

			const mapped_type&
			at(const Key& key) const {
				return _tree.find(key)->second;
			}

			mapped_type&
			operator[](const Key& key) {
				iterator ret = this->_tree.find(key);
				if (ret != this->end()) {
					mapped_type &value = this->at(key);
					return value;
				} else {
					return (this->insert(value_type(key, mapped_type()))).first->second;
				}
			}

			/************* ITERATORS *****************/

			iterator
			begin() { return this->_tree.begin(); }

			iterator
			end() { return this->_tree.end(); }

			const_iterator
			begin() const { return this->_tree.begin(); }

			const_iterator
			end() const { return this->_tree.end(); }

			reverse_iterator
			rbegin() { return this->_tree.rbegin(); }

			reverse_iterator
			rend() { return this->_tree.rend(); }

			const_reverse_iterator
			rbegin() const { return this->_tree.rbegin(); }

			const_reverse_iterator
			rend() const { return this->_tree.rend(); }

			bool
			empty() const { return this->begin() == this->end(); }

			size_type
			size() const { return _tree.size(); }

			size_type
			max_size() const { return this->_tree.max_size(); }

			void
			clear() { this->_tree.clear(); }

			ft::pair<iterator, bool>
			insert( const value_type& value ){
				return this->_tree.insertUnique(value);
			}

			iterator
			insert( iterator hint, const value_type& value ) {
				return this->_tree.insertUnique(hint, value);
			}

			template< class InputIt >
			void
			insert( InputIt first, InputIt last ) {
				this->_tree.insertUnique(first, last);
			}

			void
			erase(iterator pos) { this->_tree.erase(pos) ; }

			size_type
			erase(const Key& key) { return this->_tree.erase(key); }

			void
			erase(iterator first, iterator last) { this->_tree.erase(first, last); }

			void
			swap(map& other) { this->_tree.swap(other._tree); }

			size_type
			count( const Key& key ) const {
				const_iterator ret = this->_tree.find(key);
				return ret != this->end();
			}

			iterator
			find(const Key &key) { return this->_tree.find(key); }

			const_iterator
			find(const Key &key) const { return this->_tree.find(key); }

			iterator
			lower_bound(const Key& key) { return this->_tree.lower_bound(key); }

			const_iterator
			lower_bound(const Key& key) const { return this->_tree.lower_bound(key); }

			iterator
			upper_bound(const Key& key) { return this->_tree.upper_bound(key); }

			const_iterator
			upper_bound(const Key& key) const { return this->_tree.upper_bound(key); }

			ft::pair<iterator,iterator>
			equal_range( const Key& key ) {
				return ft::pair<iterator, iterator>(lower_bound(key),
													upper_bound(key));
			}

			ft::pair<const_iterator,const_iterator>
			equal_range( const Key& key ) const {
				return ft::pair<iterator, iterator>(lower_bound(key),
													upper_bound(key));
			}

			key_compare
			key_comp() const { return this->_tree.key_comp(); }

			map::value_compare
			value_comp() const { return value_compare(); }

	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
				   const ft::map<Key, T, Compare, Alloc> &rhs) {
		return ft::lexicographical_compare(
				lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs) {
		return !(rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
				   const ft::map<Key, T, Compare, Alloc> &rhs) {
		return rhs < lhs;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs,
			   map<Key,T,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	};


}

#endif
