#include "../include/utils/RBTree.hpp"

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

	void swapColor(RbTreeColor& a, RbTreeColor& b) {
		RbTreeColor tmp = a;
		a = b;
		b = tmp;
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

	/**
	 * @brief delete a node in the tree and rebalanced it
	 * @param z the node to delete
	 * @param header the header of the tree
	 * @return the node to be deleted
	 * @details
	 * first conditions block check z's child
	 * second conditions block whether link z's successor in place of z
	 * or rearrange z parent according to z's position in  the tree
	 * the finally we rebalance the tree
	 */

	RbTreeNodeBase*
	eraseAndRebalance(RbTreeNodeBase* const z,
					  RbTreeNodeBase& header) {
		RbTreeNodeBase*& root = header.parent;
		RbTreeNodeBase*& leftmost = header.left;
		RbTreeNodeBase*& rightmost = header.right;
		RbTreeNodeBase* y = z;
		RbTreeNodeBase* x = 0;
		RbTreeNodeBase* x_parent = 0;

		if (y->left == 0) {
			x = y->right;
		} else {
			if (y->right == 0) {
				x = y->left;
			} else {
				y = y->right;
				while (y->left != 0) {
					y = y->left;
				}
				x = y->right;
			}
		}

		if (y != z) {
			z->left->parent = y;
			y->left = z->left;
			if (y != z->right) {
				x_parent = y->parent;
				if (x) {
					x->parent = y->parent;
				}
				y->parent->left = x;
				y->right = z->right;
				z->right->parent = y;
			} else {
				x_parent = y;
			}
			if (root == z) {
				root = y;
			} else if (z->parent->left == z) {
				z->parent->left = y;
			} else {
				z->parent->right = y;
			}
			y->parent = z->parent;
			swapColor(y->color, z->color);
			y = z;
		} else {
			x_parent = y->parent;
			if (x) {
				x->parent = y->parent;
			}
			if (root == z) {
				root = x;
			} else {
				if (z->parent->left == z) {
					z->parent->left = x;
				} else {
					z->parent->right = x;
				}
			}
			if (leftmost == z) {
				if (z->right == 0) {
					leftmost = z->parent;
				} else {
					leftmost = RbTreeNodeBase::minimum(x);
				}
			}
			if (rightmost == z) {
				if (z->left == 0) {
					rightmost = z->parent;
				} else {
					rightmost = RbTreeNodeBase::maximum(x);
				}
			}
		}

		if (y->color != red) {
			while (x != root && (x == 0 || x->color == black)) {
				if (x == x_parent->left) {
					RbTreeNodeBase* w = x_parent->right;
					if (w->color == red) {
						w->color = black;
						x_parent->color = red;
						leftRotate(root, x_parent);
						w = x_parent->right;
					}
					if ((w->left == 0 ||
						w->left->color == black) &&
							(w->right == 0 ||
							w->right->color == black)) {
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					} else {
						if (w->right == 0 ||
							w->right->color == black) {
							w->left->color = black;
							w->color = red;
							rightRotate(root, w);
							w = x_parent->right;
						}
						w->color = x_parent->color;
						x_parent->color = black;
						if (w->right) {
							w->right->color = black;
						}
						leftRotate(root, x_parent);
						break;
					}
				} else {
					RbTreeNodeBase* w = x_parent->left;
					if (w->color == red) {
						w->color = black;
						x_parent->color = red;
						rightRotate(root, x_parent);
						w = x_parent->left;
					}
					if ((w->right == 0 ||
						w->right->color == black) &&
							(w->left == 0 ||
							w->left->color == black)) {
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					} else {
						if (w->left == 0 || w->left->color == black) {
							w->right->color = black;
							w->color = red;
							leftRotate(root, w);
							w = x_parent->left;
						}
						w->color = x_parent->color;
						x_parent->color = black;
						if (w->left) {
							w->left->color = black;
						}
						rightRotate(root, x_parent);
						break;
					}
				}
				if (x) {
					x->color = black;
				}
			}
		}
		return y;
	}

}