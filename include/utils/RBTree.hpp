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

	struct RbTreeNodeBase {

		typedef RbTreeNodeBase* basePtr;
		typedef const RbTreeNodeBase* constBasePtr;

		RbTreeColor		color;
		basePtr			parent;
		basePtr 		left;
		basePtr			right;

		static basePtr
		minimum(basePtr x) {
			while (x->left != 0) x = x->left;
			return x;
		}

		static constBasePtr
		minimum(constBasePtr x) {
			while (x->left != 0) x = x->left;
			return x;
		}

		static basePtr
		maximum(basePtr x) {
			while (x->right != 0) x = x->right;
			return x;
		}

		static constBasePtr
		maximum(constBasePtr x) {
			while (x->right != 0) x = x->right;
			return x;
		}

	};

	template<typename Value>
		struct RbTreeNode : public RbTreeNodeBase {
			typedef RbTreeNode<Value>* linkType;
			Value valueField;
		};

	RbTreeNodeBase*
	RbTreeDecrement(RbTreeNodeBase* x);

	RbTreeNodeBase*
	RbTreeIncrement(RbTreeNodeBase* x);

	RbTreeNodeBase::constBasePtr
	RbTreeIncrement(RbTreeNodeBase::constBasePtr x);

	void
	insertAndRebalance(const bool insertLeft,
					   RbTreeNodeBase* x,
					   RbTreeNodeBase* p,
					   RbTreeNodeBase& header);

	RbTreeNodeBase*
	eraseAndRebalance(RbTreeNodeBase* const z,
					  RbTreeNodeBase& header);

	template<typename Key, typename Value, typename KeyOfValue, class Compare, class Allocator = std::allocator<Value> >
	class RBTree {



			typedef typename Allocator::template rebind<RbTreeNode<Value> >::other node_allocator;

		protected:
			typedef RbTreeNodeBase*			basePtr;
			typedef const RbTreeNodeBase*	constBasePtr;
			typedef RbTreeNode<Value>		RbTreeNode;
		public:
			typedef Key						key_type;
			typedef Value					value_type;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;
			typedef value_type&				reference;
			typedef	const value_type&		const_reference;
			typedef RbTreeNode*				link_type;
			typedef const RbTreeNode*		const_link_type;
			typedef Compare					key_compare;
			typedef size_t					size_type;
			typedef std::ptrdiff_t 			difference_type;
			typedef Allocator				allocator_type;


			RbTreeNodeBase	header;
			key_compare		compare;
			size_type		count;

			allocator_type
			getAllocator() const
			{ return allocator_type(); }

		protected:
			RbTreeNode*
			getNode() {
				return impl.node_allocator::allocate(1);
			}

			void
			putNode(RbTreeNode* p) {
				impl.node_allocator::deallocate(p, 1);
			}

			void
			popNode(RbTreeNode*	 p) {
				node_allocator::deallocate(p, 1);
			}

			link_type
			createNode(const value_type& x) {
				link_type tmp = getNode();
				try {
					getAllocator().construct(&tmp->valueField, x);
				} catch (...) {
					putNode(tmp);
					__throw_exception_again;
				}
				return tmp;
			}

			link_type
			cloneNode(const_link_type x) {
				link_type tmp = createNode(x->valueField);
				tmp->color = x->color;
				tmp->left = 0;
				tmp->right = 0;
				return tmp;
			}

			void
			destroyNode(link_type p) {
				getAllocator().destroy(&p->valueField);
				putNode(p);
			}

			template<typename Key_Compare>
				struct RbTreeImpl : public node_allocator {
				Key_Compare		key_compare;
				RbTreeNodeBase	header;
				size_type		node_count;

				RbTreeImpl(const node_allocator& a = node_allocator(),
						   const Key_Compare& comp = Key_Compare())
				:
				node_allocator(a),
				key_compare(comp),
				header(),
				node_count(0) {
					this->header.color = red;
					this->header.parent = 0;
					this->header.left = &this->header;
					this->header.right = &this->header;
				}
			};

			RbTreeImpl<Compare> impl;

			protected:
				basePtr&
				root()
				{ return this->impl.header.parent; }

				constBasePtr
				root() const
				{ return this->impl.header.parent; }

				basePtr&
				leftmost()
				{ return this->impl.header.left; }

				constBasePtr
				leftmost() const
				{ return this->impl.header.left; }

				basePtr&
				rightmost()
				{ return this->impl.header.right; }

				constBasePtr
				rightmost() const
				{ return this->impl.header.right; }

				link_type
				_l_begin()
				{ return static_cast<link_type>(this->impl.header.parent); }

				const_link_type
				_l_begin() const
				{ return static_cast<const_link_type>(this->impl.header.parent); }

				link_type
				_l_end()
				{ return static_cast<link_type>(&this->impl.header); }

				const_link_type
				_l_end() const
				{ return static_cast<const_link_type>(&this->impl.header); }

				static const_reference
				value(const_link_type x)
				{ return x->valueField; }

				static const_reference
				value(constBasePtr x) {
					return static_cast<const_link_type>(x)->valueField;
				}

				static const Key&
				key(const_link_type x)
				{ return KeyOfValue()(value(x)); }

				static link_type
				left(basePtr x)
				{ return static_cast<link_type>(x->left); }

				static const_link_type
				left(constBasePtr x)
				{ return static_cast<const_link_type>(x->left); }

				static link_type
				right(basePtr x)
				{ return static_cast<link_type>(x->right); }

				static const_link_type
				right(constBasePtr x)
				{ return static_cast<const_link_type>(x->right); }

				static const Key&
				key(constBasePtr x)
				{ return KeyOfValue()(value(x)); }

				static basePtr
				minimum(basePtr x)
				{ return RbTreeNodeBase::minimum(x); }

				static constBasePtr
				minimum(constBasePtr x)
				{ return RbTreeNodeBase::minimum(x); }

				static basePtr
				maximum(basePtr x)
				{ return RbTreeNodeBase::maximum(x); }

				static constBasePtr
				maximum(constBasePtr x)
				{ return RbTreeNodeBase::maximum(x); }


			template<typename Type>
			struct RbTreeIterator {
				typedef Type	value_type;
				typedef Type&	reference;
				typedef Type*	pointer;

				typedef ft::bidirectional_iterator_tag	iterator_category;
				typedef std::ptrdiff_t 				difference_type;

				typedef RbTreeIterator<Type>	self;
				typedef ft::RbTreeNodeBase::basePtr basePtr;
				typedef ft::RbTreeNode<Type>*		linkType;

				basePtr	node;

				RbTreeIterator()
						: node() {}

				explicit
				RbTreeIterator(linkType x)
						: node(x) {}

				reference
				operator*() const
				{ return static_cast<linkType>(this->node)->valueField; }

				pointer
				operator->() const
				{ return &static_cast<linkType>(this->node)->valueField; }

				self&
				operator++() {
					this->node = RbTreeIncrement(this->node);
					return *this;
				}

				self
				operator++(int) {
					self tmp = *this;
					this->node = RbTreeIncrement(this->node);
					return tmp;
				}

				self&
				operator--() {
					this->node = RbTreeDecrement(this->node);
					return *this;
				}

				self
				operator--(int) {
					self tmp = *this;
					this->node = RbTreeDecrement(this->node);
					return tmp;
				}

				bool
				operator==(const self& rhs) const {
					return this->node == rhs.node;
				}

				bool
				operator!=(const self& rhs) const {
					return this->node != rhs.node;
				}

			};

			template<typename Type>
			struct RbTreeConstIterator {
				typedef Type		value_type;
				typedef const Type&	reference;
				typedef const Type*	pointer;

				typedef RbTreeIterator<Type> iterator;

				typedef ft::bidirectional_iterator_tag	iterator_category;
				typedef std::ptrdiff_t 				difference_type;

				typedef RbTreeConstIterator<Type>		self;
				typedef ft::RbTreeNodeBase::constBasePtr	basePtr;
				typedef const ft::RbTreeNode<Type>*			linkType;

				basePtr	node;

				RbTreeConstIterator()
						: node() {}

				explicit
				RbTreeConstIterator(linkType x)
						: node(x) {}

				reference
				operator*() const
				{ return static_cast<linkType>(this->node)->valueField; }

				pointer
				operator->() const
				{ return &static_cast<linkType>(this->node)->valueField; }

				self&
				operator++() {
					this->node = RbTreeIncrement(this->node);
					return *this;
				}

				self
				operator++(int) {
					self tmp = *this;
					this->node = RbTreeIncrement(this->node);
					return tmp;
				}

				self&
				operator--() {
					this->node = RbTreeDecrement(this->node);
					return *this;
				}

				self
				operator--(int) {
					self tmp = *this;
					this->node = RbTreeDecrement(this->node);
					return tmp;
				}

				bool
				operator==(const self& rhs) const {
					return this->node == rhs.node;
				}

				bool
				operator!=(const self& rhs) const {
					return this->node != rhs.node;
				}

			};



		public:
			typedef RbTreeIterator<value_type> iterator;
			typedef RbTreeConstIterator<value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			public:
				RBTree() {};

				RBTree(const Compare& comp)
				: impl(allocator_type(), comp) {};

				RBTree(const Compare& comp, const allocator_type& a)
				: impl(a, comp) {};

				RBTree(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& src)
				: impl(src.getAllocator(), src.impl.key_compare) {
					if (src.root() != 0) {
						root() = copy(src.begin(), _l_end());
						leftmost() = minimum(root());
						rightmost() = maximum(root());
						impl.node_count = src.impl.node_count;
					}
				};

				~RBTree() {}

#include "printTree.hpp"

				void
				print() {
					print_tree(impl.header.parent);
				}

				size_type
				size() const
				{ return impl.node_count; }

				iterator
				begin() {
					return iterator(static_cast<link_type>(this->impl.header.left));
				}

				const_iterator
				begin() const {
					return const_iterator(static_cast<const_link_type>(this->impl.header.left));
				}

				iterator
				end() {
					return iterator(static_cast<link_type>(&this->impl.header));
				}

				const_iterator
				end() const {
					return const_iterator(static_cast<const_link_type>(&this->impl.header));
				}

				RbTreeNodeBase* getRoot() { return this->root(); }

				iterator search(const Key& key) {

					basePtr root = this->root();
					while (root) {
						if (impl.key_compare(KeyOfValue()((static_cast<link_type>(root))->valueField), key)) {
							root = root->right;
						} else if (impl.key_compare(key, KeyOfValue()(static_cast<link_type>(root)->valueField))) {
							root = root->left;
						} else {
							return iterator(static_cast<link_type>(root));
						}
					}
					throw std::out_of_range("");
				}

				iterator
				insert(basePtr x, basePtr p, const value_type& value) {
					bool insertLeft = (x != 0 || p == _l_end()
							|| impl.key_compare(KeyOfValue()(value),
												key(p)));

					link_type z = createNode(value);
					insertAndRebalance(insertLeft, z,
									   const_cast<basePtr>(p),
									   this->impl.header);
					++impl.node_count;
					return iterator(z);
				}

				size_type
				erase(const Key& key) {
					try {
						iterator i = this->search(key);
						erase(i);
						return 1;
					} catch (...) {
						return 0;
					}
				}

				void
				erase(iterator pos) {
					link_type y =
							static_cast<link_type>(eraseAndRebalance(pos.node, this->impl.header));
					destroyNode(y);
					--this->impl.node_count;
				}

			pair<iterator, bool>
				insertUnique(const value_type& value) {
					link_type x =	this->_l_begin();
					link_type y =	this->_l_end();
					bool comp =		true;

					while (x != 0) {
						y = x;
						comp = impl.key_compare(KeyOfValue()(value), key(x));
						x = comp ? left(x) : right(x);
					}
					iterator j = iterator(y);
					if (comp) {
						if (j == begin()) {
							return pair<iterator, bool>(insert(x, y, value), true);
						} else {
							--j;
						}
					}
					if (impl.key_compare(key(j.node), KeyOfValue()(value))) {
						return pair<iterator, bool>(insert(x, y, value), true);
					}
					return pair<iterator, bool>(j, false);
				}

				iterator
				insertUnique(iterator hint, const value_type& value) {
					if (hint.node == this->_l_end()) {
						if (this->size() > 0
							&& impl.key_compare(key(rightmost()),
												KeyOfValue()(value))) {
							return insert(0, rightmost(), value);
						} else {
							return insertUnique(value).first;
						}
					} else if (impl.key_compare(KeyOfValue()(value),
												key(hint.node))) {
						iterator before = hint;
						if (hint.node == leftmost()) {
							return insert(leftmost(), leftmost(), value);
						} else if (impl.key_compare(key((--before).node),
													KeyOfValue()(value))) {
							if (right(before.node) == 0) {
								return insert(0, before.node, value);
							} else {
								return insert(hint.node, hint.node, value);
							}
						} else {
							return insertUnique(value).first;
						}
					} else if (impl.key_compare(key(hint.node),
													KeyOfValue()(value))) {
							iterator after = hint;
							if (hint.node == rightmost()) {
								return insert(0, rightmost(), value);
							} else if (impl.key_compare(KeyOfValue()(value),
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

				Compare
				key_comp() const
				{ return impl.key_compare; }


	};

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
		inline bool
		operator==(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& lhs,
					const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& rhs) {
			return lhs.size() == rhs.size()
				&& ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
		inline bool
		operator<(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& lhs,
				   const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(),
											   rhs.begin(), rhs.end());
		}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
		inline bool
		operator!=(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& lhs,
				   const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& rhs) {
			return !(lhs == rhs);
		}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
		inline bool
		operator>(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& lhs,
				   const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& rhs) {
			return rhs < lhs;
		}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
		inline bool
		operator<=(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& lhs,
				   const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& rhs) {
			return !(rhs < lhs);
		}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
		inline bool
		operator>=(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& lhs,
				   const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& rhs) {
			return !(lhs < rhs);
		}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
		inline void
		swap(const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& lhs,
				   const RBTree<Key, Value, KeyOfValue, Compare, Allocator>& rhs) {
			lhs.swap(rhs);
		}

}




#endif
