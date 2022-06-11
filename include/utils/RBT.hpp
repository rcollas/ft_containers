#ifndef FT_CONTAINERS_TMP_RBT_HPP
#define FT_CONTAINERS_TMP_RBT_HPP

#include "pair.hpp"

#define RED 0
#define BLACK 1
#define _grandParent _parent->_parent
#define _rightUncle _grandParent->_right
#define _leftUncle _grandParent->_left
#define _grandSon _left->_left

namespace ft {
	template<class T>
	class Node {
		public:
			Node(T const &data) :
				_data(data),
				_parent(0),
				_left(0),
				_right(0),
				_color(RED) {};

			bool getColor() const { return this->_color; }
			void setColor(bool color) { this->_color = color; }

			T _data;
			Node* _parent;
			Node* _left;
			Node* _right;
			bool _color;
	};

	template<class T>
	void swapColor(Node<T> *rhs, Node<T> *lhs) {
		bool tmpColor = rhs->getColor();
		rhs->setColor(lhs->getColor());
		lhs->setColor(tmpColor);
	}

#define COUNT 5

	template<class T, class Compare, class Allocator = std::allocator<T> >
	class RBTree {
		#include "printTree.hpp"
		public:
			typedef T value_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef Node<T> Node;

			RBTree() : _root(0), _compare(key_compare()) {};
			RBTree(value_type value) : _root(new Node(value)), _compare(key_compare()) {
				this->_root->setColor(BLACK);
			};
			void printHelper(Node* node, int space) const {
				if (node == 0) {
					return;
				}
				space += COUNT;
				printHelper(node->_right, space);

				std::cout << std::endl;
				for (int i = COUNT; i < space; i++) {
					std::cout << " ";
				}
				if (node->getColor() == RED) {
					std::cout << "\x1B[31m" << node->_data._second << "\033[0m" << std::endl;
				} else {
					std::cout << node->_data._second << std::endl;
				}
				printHelper(node->_left, space);
			}
			void print() {
				print_tree(this->_root);
				std::cout << std::endl;
			}

			bool isLeftChildOf(Node *parent, Node *node) {
				return node == parent->_left;
			}
			bool isRightChildOf(Node *parent, Node *node) {
				return parent && node == parent->_right;
			}

			bool hasLeftSubtree(Node *node)	{
				return node && node->_left;
			}
			bool hasRightSubTree(Node *node) {
				return node && node->_right;
			}

			void leftRotate(Node *&root, Node *&node) {

				Node *right = node->_right;

				node->_right = node->_left;
				if (node->_right != 0) {
					node->_right->_parent = node;
				}

				right->_parent = node->_parent;

				if (node->_parent == 0) {
					root = right;
				} else if (node == node->_parent->_left) {
					node->_parent->_left = right;
				} else {
					node->_parent->_right = right;
				}
				right->_left = node;
				node->_parent = right;
			}

			void rightRotate(Node *&root, Node *&node) {

				Node *left = node->_left;

				node->_left = node->_right;
				if (node->_left != 0) {
					node->_left->_parent = node;
				}

				left->_parent = node->_parent;

				if (node->_parent == 0) {
					root = left;
				} else if (node == node->_parent->_left) {
					node->_parent->_left = left;
				} else {
					node->_parent->_right = left;
				}
				left->_right = node;
				node->_parent = left;
			}

			void insertFix(Node *&root, Node *&node) {

				Node *parent = 0;
				Node *grandParent = 0;
				while (node && node != root && node->getColor() != BLACK && node->_parent->getColor() == RED) {

					parent = node->_parent;
					grandParent = node->_grandParent;

					if (parent == grandParent->_left) {

						Node *uncle = grandParent->_right;

						if (uncle && uncle->getColor() == RED) {

							grandParent->setColor(RED);
							parent->setColor(BLACK);
							uncle->setColor(BLACK);
							node = grandParent;

						} else {

							if (node == parent->_right) {
								leftRotate(root, parent);
								node = parent;
								parent = node->_parent;
							}
							rightRotate(root, grandParent);
							swapColor(parent, grandParent);
							node = parent;
						}
					} else {
						Node *uncle = grandParent->_left;
						if (uncle && uncle->getColor() == RED) {

							grandParent->setColor(RED);
							parent->setColor(BLACK);
							uncle->setColor(BLACK);
							node = grandParent;

						} else {

							if (node == parent->_left) {
								rightRotate(root, parent);
								node = parent;
								parent = node->_parent;
							}
							leftRotate(root, grandParent);
							swapColor(parent, grandParent);
							node = parent;
						}
					}
				}
				root->setColor(BLACK);
			}

			Node *insertHelper(Node *root, Node *&insert) {
				if (root == NULL) {
					return insert;
				}
				if (_compare(insert->_data._first, root->_data._first)) {
					root->_left = insertHelper(root->_left, insert);
					root->_left->_parent = root;
				} else if (_compare(root->_data._first, insert->_data._first)) {
					root->_right = insertHelper(root->_right, insert);
					root->_right->_parent = root;
				}
				delete insert;
				insert = 0;
				return root;
			}
			void insert(value_type value) {
				Node *node = new Node(value);
				this->_root = insertHelper(this->_root, node);
				insertFix(this->_root, node);
			};

			Node *_root;
			key_compare _compare;
	};
}

#endif
