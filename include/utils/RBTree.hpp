#ifndef FT_CONTAINERS_TMP_RBT_HPP
#define FT_CONTAINERS_TMP_RBT_HPP

#include "pair.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "IteratorsTraits.hpp"
#include "Iterator.hpp"
#include "ReverseIterator.hpp"
#include <memory>
#include <iostream>
#include <vector>

#define _grandParent parent->parent

enum RbTreeColor
{
	red = false,
	black = true,
};


namespace ft
{

	template<typename Value>
		struct RbTreeNode {
			typedef RbTreeNode<Value>	Node;

			Value			valueField;
			Node*			parent;
			Node*			left;
			Node*			right;
			RbTreeColor		color;

			static Node*
			minimum(Node* x) {
				while (x->left != 0) x = x->left;
				return x;
			}

			static const Node*
			minimum(const Node* x) {
				while (x->left != 0) x = x->left;
				return x;
			}

			static Node*
			maximum(Node* x) {
				while (x->right != 0) x = x->right;
				return x;
			}

			static const Node*
			maximum(const Node* x) {
				while (x->right != 0) x = x->right;
				return x;
			}

		};



	template<typename Key, typename Value, typename KeyOfValue, class Compare, class Allocator = std::allocator<Value> >
	class RBTree {

			typedef typename Allocator::template rebind<RbTreeNode<Value> >::other node_allocator;

		protected:
			typedef RbTreeNode<Value>		Node;
		public:
			typedef Key						key_type;
			typedef Value					value_type;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;
			typedef value_type&				reference;
			typedef	const value_type&		const_reference;
			typedef Compare					key_compare;
			typedef size_t					size_type;
			typedef std::ptrdiff_t 			difference_type;
			typedef Allocator				allocator_type;


		private:
			node_allocator	allocator;
			key_compare		compare;
			Node			header;
			size_type		count;

		public:

			allocator_type
			getAllocator() const
			{ return allocator_type(); }

		public:
			Node*
			getNode() {
				return allocator.allocate(1);
			}

			void
			popNode(Node* p) {
				allocator.deallocate(p, 1);
			}

			Node*
			createNode(const value_type& x) {
				Node* tmp = getNode();
				try {
					getAllocator().construct(&tmp->valueField, x);
				} catch (...) {
					popNode(tmp);
					__throw_exception_again;
				}
				return tmp;
			}

			Node*
			cloneNode(const Node* x) {
				Node* tmp = createNode(x->valueField);
				tmp->color = x->color;
				tmp->left = 0;
				tmp->right = 0;
				return tmp;
			}

			void
			destroyNode(Node* p) {
				getAllocator().destroy(&p->valueField);
				popNode(p);
			}


			#include "RBTreeOP.hpp"

			public:

				Node*&
				leftmost()
				{ return this->header.left; }

				const Node*
				leftmost() const
				{ return this->header.left; }

				Node*&
				rightmost()
				{ return this->header.right; }

				const Node*
				rightmost() const
				{ return this->header.right; }

				Node*&
				root()
				{ return this->header.parent; }

				const Node*
				root() const
				{ return this->header.parent; }


				static const_reference
				value(const Node* x)
				{ return x->valueField; }

				static const Key&
				key(const Node* x)
				{ return KeyOfValue()(value(x)); }

				static Node*
				left(Node* x)
				{ return x->left; }

				static const Node*
				left(const Node* x)
				{ return x->left; }

				static Node*
				right(Node* x)
				{ return x->right; }

				static const Node*
				right(const Node* x)
				{ return x->right; }

				static Node*
				minimum(Node* x)
				{ return x->minimum(x); }

				static const Node*
				minimum(const Node* x)
				{ return x->minimum(x); }

				static Node*
				maximum(Node* x)
				{ return x->maximum(x); }

				static const Node*
				maximum(const Node* x)
				{ return x->maximum(x); }

#include "RbTreeIterator.hpp"

		public:
			typedef RbTreeIterator<value_type> iterator;
			typedef RbTreeConstIterator<value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			 /*************************************************/
			/**************** CONSTRUCTORS *******************/
		   /*************************************************/

			public:

				RBTree()
				:
				allocator(node_allocator()),
				compare(key_compare()),
				header(),
				count(0) {}

				RBTree(const key_compare& comp = key_compare())
						:
						allocator(node_allocator()),
						compare(comp),
						header(),
						count(0) {
					this->header.color = red;
					this->header.parent = 0;
					this->header.left = &this->header;
					this->header.right = &this->header;
				}

				RBTree(const key_compare& comp = key_compare(),
						const node_allocator& a = node_allocator())
						:
						allocator(a),
						compare(comp),
						header(),
						count(0) {
					this->header.color = red;
					this->header.parent = 0;
					this->header.left = &this->header;
					this->header.right = &this->header;
				}

//				RBTree(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& src)
//				:
//				allocator(src.getAllocator()),
//				compare(src.key_comp()),
//				header(),
//				count(0) {
//					if (src.root() != 0) {
////						this->insertUnique(src.begin(), src.end());
//						for (const_iterator it = src.begin(); it != src.end(); it++) {
//							this->insertUnique(value_type(it->first, it->second));
//						}
////						this->root() = copy(src.nodeBegin(), this->nodeEnd());
////						copy(src);
//						this->leftmost() = minimum(this->root());
//						this->rightmost() = maximum(this->root());
//						this->count = src.count;
//					}
//				};

				~RBTree() { erase(root()); }

				RBTree &operator=(const RBTree& rhs) {
					if (this != &rhs) {
						this->clear();
						this->compare = rhs.key_comp();
						if (rhs.root() != 0) {
							this->insertUnique(rhs.begin(), rhs.end());
							this->leftmost() = minimum(this->root());
							this->rightmost() = maximum(this->root());
							this->count = rhs.count;
						}
					}
					return *this;
				}

//				void
//				copy(Node*)


//				Node*
//				copy(const Node* x, Node* p) {
//					Node* top = cloneNode(x);
//					top->parent = p;
//
//					try {
//						if (x->right)
//							top->right = copy(x->right, top);
//						p = top;
//						x = x->left;
//
//						while (x != 0) {
//							Node* y = cloneNode(x);
//							p->left= y;
//							y->parent = p;
//							if (x->right)
//								y->right = copy(x->right, y);
//							p = y;
//							x = x->left;
//						}
//					} catch(...) {
//						erase(top);
//						__throw_exception_again;
//					}
//					return top;
//				}

				iterator
				begin()
				{ return iterator(this->header.left); }

				const_iterator
				begin() const
				{ return const_iterator(this->header.left); }

				iterator
				end()
				{ return iterator(&this->header); }

				const_iterator
				end() const
				{ return const_iterator(&this->header); }

				Node*
				nodeBegin()
				{ return this->header.left; }

				const Node*
				nodeBegin() const
				{ return this->header.left; }

				Node*
				nodeEnd()
				{ return &this->header; }

				const Node*
				nodeEnd() const
				{ return &this->header; }


//#include "printTree.hpp"
//
//				void
//				print(basePtr node) {
//					print_tree(node);
//				}

				size_type
				size() const
				{ return this->count; }

				size_type
				max_size() const
				{ return this->allocator.max_size(); }

				reverse_iterator
				rbegin() { return reverse_iterator(end()); }

				const_reverse_iterator
				rbegin() const { return const_reverse_iterator(end()); }

				reverse_iterator
				rend() { return reverse_iterator(begin()); }

				const_reverse_iterator
				rend() const { return const_reverse_iterator(begin()); }

				void
				clear() {
					erase(this->root());
					this->leftmost() = nodeEnd();
					this->header.parent = 0;
					this->rightmost() = nodeEnd();
					this->count = 0;
				}

			iterator
			find(const Key& k) {

				Node* x = this->root();
				while (x != 0) {
					if (compare(key(x), k)) {
						x = right(x);
					} else if (compare(k, key(x))) {
						x = left(x);
					}
					else if (!compare(key(x), k)
								&& !compare(k, key(x))) {
						return iterator(x);
					}
				}
				return iterator(this->end());
			}

			const_iterator
			find(const Key& k) const {

				const Node* x = this->root();
				while (x != 0) {
					if (compare(key(x), k)) {
						x = right(x);
					} else if (compare(k, key(x))) {
						x = left(x);
					}
					else if (!compare(key(x), k)
							 && !compare(k, key(x))) {
						return const_iterator(x);
					}
				}
				return this->end();
			}

			iterator
			lower_bound(const Key& k) {
				Node* x = this->root();
				Node* y = this->nodeEnd();
				while (x != 0) {
					if (!compare(key(x), k)) {
						y = x, x = left(x);
					} else {
						x = right(x);
					}
				}
				return iterator(y);
			}

			const_iterator
			lower_bound(const Key& k) const {
				const Node* x = this->root();
				const Node* y = this->nodeEnd();
				while (x != 0) {
					if (!compare(key(x), k)) {
						y = x, x = left(x);
					} else {
						x = right(x);
					}
				}
				return const_iterator(y);
			}

			iterator
			upper_bound(const Key& k) {
				Node* x = this->root();
				Node* y = this->nodeEnd();
				while (x != 0) {
					if (compare(k, key(x))) {
						y = x, x = left(x);
					} else {
						x = right(x);
					}
				}
				return iterator(y);
			}

			const_iterator
			upper_bound(const Key& k) const {
				const Node* x = this->root();
				const Node* y = this->nodeEnd();
				while (x != 0) {
					if (compare(k, key(x))) {
						y = x, x = left(x);
					} else {
						x = right(x);
					}
				}
				return const_iterator(y);
			}

			iterator
			insert(Node* x, Node* p, const value_type& value) {
					bool insertLeft = (x != 0 || p == nodeEnd()
							|| compare(KeyOfValue()(value),
												key(p)));

					Node* z = createNode(value);
					insertAndRebalance(insertLeft,
									   z,
									   p,
									   this->header);
					++this->count;
					return iterator(z);
				}

				size_type
				erase(const Key& key) {
					iterator ret = this->find(key);
					if (ret != this->end()) {
						erase(ret);
						return 1;

					} else {
						return 0;
					}
				}

				void
				erase(iterator pos) {
					Node* y = eraseAndRebalance(pos.node, this->header);
					destroyNode(y);
					--this->count;
				}

				void
				erase(iterator first, iterator last) {
					if (first == this->begin() && last == this->end()) {
						this->clear();
					} else {
						while (first != last) {
							erase(first++);
						}
					}
				}

				void
				erase(Node* x) {
					while (x != 0) {
						erase(right(x));
						Node* y = left(x);
						destroyNode(x);
						x = y;
					}
				}

			pair<iterator, bool>
				insertUnique(const value_type& value) {
					Node* x =	this->root();
					Node* y =	this->nodeEnd();
					bool comp = true;

					while (x != 0) {
						y = x;
						comp = compare(KeyOfValue()(value), key(x));
						x = comp ? left(x) : right(x);
					}
					iterator j = iterator(y);
					if (comp) {
						if (j == iterator(begin())) {
							return pair<iterator, bool>(insert(x, y, value), true);
						} else {
							--j;
						}
					}
					if (compare(key(j.node), KeyOfValue()(value))) {
						return pair<iterator, bool>(insert(x, y, value), true);
					}
					return pair<iterator, bool>(j, false);
				}

				iterator
				insertUnique(iterator hint, const value_type& value) {
					if (hint.node == this->nodeEnd()) {
						if (this->count > 0
							&& compare(key(this->rightmost()),
										KeyOfValue()(value))) {
							return insert(0, rightmost(), value);
						} else {
							return insertUnique(value).first;
						}
					} else if (compare(KeyOfValue()(value),
										key(hint.node))) {
						iterator before = hint;
						if (hint.node == this->leftmost()) {
							return insert(this->leftmost(), this->leftmost(), value);
						} else if (compare(key((--before).node),
												KeyOfValue()(value))) {
							if (right(before.node) == 0) {
								return insert(0, before.node, value);
							} else {
								return insert(hint.node, hint.node, value);
							}
						} else {
							return insertUnique(value).first;
						}
					} else if (compare(key(hint.node),
											KeyOfValue()(value))) {
							iterator after = hint;
							if (hint.node == this->rightmost()) {
								return insert(0, this->rightmost(), value);
							} else if (compare(KeyOfValue()(value),
												key((++after).node))) {
								if (right(hint.node) == 0) {
									return insert (0, hint.node, value);
								} else {
									return insert(after.node, after.node, value);
								}
							} else {
								return insertUnique(value).first;
							}
					} else {
						return hint;
					}
				}

				template<typename InputIt>
					void
					insertUnique(InputIt first, InputIt last) {
					for (; first != last; ++first) {
						insertUnique(end(), *first);
					}
				}

				key_compare
				key_comp() const
				{ return compare; }

				void
				swap(RBTree& other) {
					std::swap(this->root(), other.root());
					std::swap(this->leftmost(), other.leftmost());
					std::swap(this->rightmost(), other.rightmost());
					if (this->root() != 0) {
						this->root()->parent = this->nodeEnd();
					} else {
						this->header.left = &this->header;
						this->header.right = &this->header;
					}
					if (other.root() != 0) {
						other.root()->parent = other.nodeEnd();
					} else {
						this->header.left = &this->header;
						this->header.right = &this->header;
					}

					std::swap(this->count, other.count);
					std::swap(this->compare, other.compare);
				}


	};
}




#endif
