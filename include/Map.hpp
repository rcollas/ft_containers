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
			class Type,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, Type> >
	> class map {

		public:
			typedef Key key_type;
			typedef typename ft::pair<const Key, Type> value_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;


		typedef RBTree<key_type, value_type, std::_Select1st<value_type>, key_compare, allocator_type> RBTree;

		public:
			typedef Type mapped_type;
			typedef typename std::size_t size_type;
			typedef typename std::ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename RBTree::iterator iterator;
			typedef typename RBTree::const_iterator const_iterator;
			typedef typename RBTree::reverse_iterator reverse_iterator;
			typedef typename RBTree::const_reverse_iterator const_reverse_iterator;


			map() : _tree(new RBTree(_compare)) {
				std::cout << "Default constructor" << std::endl;
			};
			explicit map(const Compare& comp,
						  const Allocator& alloc = Allocator()) : _tree(0) {
				(void) comp;
				(void)alloc;
				std::cout << "map(const Compare& comp, const Allocator& alloc = Allocator())" << std::endl;
			};

			~map() {
				delete this->_tree;
			}

			ft::pair<iterator, bool>
			insert( const value_type& value ){
				return _tree->insertUnique(value);
			};

			void print() const {
				this->_tree->print();
				std::cout << std::endl;
			}

			iterator begin() { return _tree->begin(); }

			iterator end() { return _tree->end(); }

			RBTree *_tree;
		private:
			key_compare _compare;

	};

}

#endif
