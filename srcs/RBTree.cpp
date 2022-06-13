#include "../include/utils/RBT.hpp"

namespace ft {

	static RbTreeNodeBase*
	LocalRbTreeDecrement(RbTreeNodeBase* x) {
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
	RbTreeDecrement(RbTreeNodeBase* x)  {
		return LocalRbTreeDecrement(x);
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

	static inline void
	swapColor(RbTreeNodeBase *rhs, RbTreeNodeBase *lhs) {
		RbTreeColor tmpColor = rhs->color;
		rhs->color = lhs->color;
		lhs->color = tmpColor;
	}

	static void
	leftRotate(RbTreeNodeBase *&root, RbTreeNodeBase *&node) {

		RbTreeNodeBase *right = node->right;

		node->right = node->left;
		if (node->right != 0) {
			node->right->parent = node;
		}

		right->parent = node->parent;

		if (node->parent == 0) {
			root = right;
		} else if (node == node->parent->left) {
			node->parent->left = right;
		} else {
			node->parent->right = right;
		}
		right->left = node;
		node->parent = right;
	}

	static void
	rightRotate(RbTreeNodeBase *&root, RbTreeNodeBase *&node) {

		RbTreeNodeBase *left = node->left;

		node->left = node->right;
		if (node->left != 0) {
			node->left->parent = node;
		}

		left->parent = node->parent;

		if (node->parent == 0) {
			root = left;
		} else if (node == node->parent->left) {
			node->parent->left = left;
		} else {
			node->parent->right = left;
		}
		left->right = node;
		node->parent = left;
	}

	void
	insertFix(RbTreeNodeBase *&root, RbTreeNodeBase *&x) {

		RbTreeNodeBase *parent = 0;
		RbTreeNodeBase *grandParent = 0;
		while (x && x != root && x->color != black && x->parent->color == red) {

			parent = x->parent;
			grandParent = x->_grandParent;

			if (parent == grandParent->left) {

				RbTreeNodeBase *uncle = grandParent->right;

				if (uncle && uncle->color == red) {

					grandParent->color = red;
					parent->color = black;
					uncle->color = black;
					x = grandParent;

				} else {

					if (x == parent->right) {
						leftRotate(root, parent);
						x = parent;
						parent = x->parent;
					}
					rightRotate(root, grandParent);
					swapColor(parent, grandParent);
					x = parent;
				}
			} else {
				RbTreeNodeBase *uncle = grandParent->left;
				if (uncle && uncle->color == red) {

					grandParent->color = red;
					parent->color = black;
					uncle->color = black;
					x = grandParent;

				} else {

					if (x == parent->left) {
						rightRotate(root, parent);
						x = parent;
						parent = x->parent;
					}
					leftRotate(root, grandParent);
					swapColor(parent, grandParent);
					x = parent;
				}
			}
		}
		root->color = black;
	}

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
		insertFix(root, x);
	}

//	RbTreeNodeBase *insertHelper(RbTreeNodeBase *root, RbTreeNodeBase *&insert) {
//		if (root == NULL) {
//			return insert;
//		}
//		if (_compare(insert->_data.first, root->_data.first)) {
//			root->_left = insertHelper(root->_left, insert);
//			root->_left->_parent = root;
//		} else if (_compare(root->_data.first, insert->_data.first)) {
//			root->_right = insertHelper(root->_right, insert);
//			root->_right->_parent = root;
//		}
//		return root;
//	}
//	pointer insert(value_type value) {
//		RbTreeNodeBase *node = new RbTreeNodeBase(value);
//		this->_root = insertHelper(this->_root, node);
//		insertFix(this->_root, node);
//		return &(node->_data);
//	};


}