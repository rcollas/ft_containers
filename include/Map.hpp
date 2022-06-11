#ifndef FT_CONTAINERS_TMP_MAP_HPP
#define FT_CONTAINERS_TMP_MAP_HPP

#include <memory>
#include "utils/ReverseIterator.hpp"
#include "utils/Iterator.hpp"
#include "utils/RandomAccessIterator.hpp"
#include "utils/pair.hpp"
#include "utils/RBT.hpp"

namespace ft {

	template<
			class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<std::pair<const Key, T> >
	> class map {

		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename ft::pair<const Key, T> value_type;
			typedef typename std::size_t size_type;
			typedef typename std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename ft::random_access_iterator<pointer> iterator;
			typedef typename ft::random_access_iterator<pointer> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef RBTree<value_type, key_compare, allocator_type> RBTree;

			map() : _tree(new RBTree()) {
				std::cout << "Default constructor" << std::endl;
			};
			explicit map(const Compare& comp,
						  const Allocator& alloc = Allocator()) : _tree(0) {
				(void) comp;
				(void)alloc;
				std::cout << "map(const Compare& comp, const Allocator& alloc = Allocator())" << std::endl;
			};

			ft::pair<int, bool> insert( const value_type& value ){
				this->_tree->insert(value);
				return ft::pair<int, bool>(0, false);
			};

			void print() const {
				this->_tree->print();
				std::cout << std::endl;
			}

		private:
			RBTree *_tree;
			key_compare _compare;

	};

}

#endif
