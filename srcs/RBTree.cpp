#include "../include/utils/RBT.hpp"

namespace ft {

	RbTreeNodeBase*
	RbTreeDecrement(RbTreeNodeBase* x) {
		if (x->color == red
			&& x->parent->parent == x) {
			x = x->right;
		} else if (x->left != 0) {
			RbTreeNodeBase* y = x->left;
			while (y->right != 0) {
				y = y->right;
				x = y;
			}
		} else {
			RbTreeNodeBase* y = x->parent;
			while (x == y->left) {
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return x;
	}

	RbTreeNodeBase::constBasePtr
	RbTreeDecrement(RbTreeNodeBase::constBasePtr  x) {
		if (x->color == red
			&& x->parent->parent == x) {
			x = x->right;
		} else if (x->left != 0) {
			RbTreeNodeBase* y = x->left;
			while (y->right != 0) {
				y = y->right;
				x = y;
			}
		} else {
			RbTreeNodeBase* y = x->parent;
			while (x == y->left) {
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return x;
	}

	RbTreeNodeBase*
	RbTreeIncrement(RbTreeNodeBase* x) {
		if (x->right != 0) {
			x = x->right;
			while (x->left != 0) {
				x = x->left;
			}
		} else {
			RbTreeNodeBase* y = x->parent;
			while (x == y->right) {
				x = y;
				y = y->parent;
			}
			if (x->right != y) {
				x = y;
			}
		}
		return x;
	}

	RbTreeNodeBase::constBasePtr
	RbTreeIncrement(RbTreeNodeBase::constBasePtr x) {
		if (x->right != 0) {
			x = x->right;
			while (x->left != 0) {
				x = x->left;
			}
		} else {
			RbTreeNodeBase* y = x->parent;
			while (x == y->right) {
				x = y;
				y = y->parent;
			}
			if (x->right != y) {
				x = y;
			}
		}
		return x;
	}

	static void
	leftRotate(RbTreeNodeBase *&root, RbTreeNodeBase *&node) {

		RbTreeNodeBase* const y = node->right;

		node->right = y->left;
		if (y->left != 0) {
			y->left->parent = node;
		}
		y->parent = node->parent;

		if (node == root) {
			root = y;
		} else if (node == node->parent->left) {
			node->parent->left = y;
		} else {
			node->parent->right = y;
		}
		y->left = node;
		node->parent = y;
	}

	static void
	rightRotate(RbTreeNodeBase *&root, RbTreeNodeBase *&node) {

		RbTreeNodeBase* const y = node->left;

		node->left = y->right;
		if (y->right != 0) {
			y->right->parent = node;
		}
		y->parent = node->parent;

		if (node == root) {
			root = y;
		} else if (node == node->parent->right) {
			node->parent->right = y;
		} else {
			node->parent->left = y;
		}
		y->right = node;
		node->parent = y;
	}

	void
	rebalance(RbTreeNodeBase *&root, RbTreeNodeBase *&x) {

		while (x != root && x->parent->color == red) {

			RbTreeNodeBase* grandParent = x->_grandParent;

			if (x->parent == grandParent->left) {

				RbTreeNodeBase *uncle = grandParent->right;

				if (uncle && uncle->color == red) {

					x->parent->color = black;
					uncle->color = black;
					grandParent->color = red;
					x = grandParent;

				} else {

					if (x == x->parent->right) {
						x = x->parent;
						leftRotate(root, x->parent);
					}
					x->parent->color = black;
					grandParent->color = red;
					rightRotate(root, grandParent);
				}
			} else {
				RbTreeNodeBase *uncle = grandParent->left;
				if (uncle && uncle->color == red) {

					x->parent->color = black;
					uncle->color = black;
					grandParent->color = red;
					x = grandParent;

				} else {

					if (x == x->parent->left) {
						x = x->parent;
						rightRotate(root, x);
					}
					x->parent->color = black;
					grandParent->color = red;
					leftRotate(root, grandParent);
				}
			}
		}
		root->color = black;
	}

	/**
	 * @brief
	 * insert a node in the actual tree and rebalance it
	 * @param[in] insertLeft bool value
	 * @param[in] x the node to insert
	 * @param[in] p x's parent
	 * @param[in] header header of the tree
	 * @details
	 * if insertLeft is true, make x the left child of p
	 * else make x the right child of p
	 * if tree is empty, set x as the root (header.parent)
	 * if p is rightmost or leftmost, update the header
	 */

	void
	insertAndRebalance(const bool insertLeft,
					   RbTreeNodeBase* x,
					   RbTreeNodeBase* p,
					   RbTreeNodeBase& header) {

		RbTreeNodeBase*& root = header.parent;
		x->parent = p;
		x->left = 0;
		x->right = 0;
		x->color = red;

		if (insertLeft) {
			p->left = x;

			if (p == &header) {
				header.parent = x;
				header.right = x;
			}
			else if (p == header.left) {
				header.left = x;
			}
		} else {
			p->right = x;
			if (p == header.right) {
				header.right = x;
			}
		}
		rebalance(root, x);
	}


}
