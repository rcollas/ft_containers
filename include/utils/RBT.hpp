#ifndef FT_CONTAINERS_TMP_RBT_HPP
#define FT_CONTAINERS_TMP_RBT_HPP

#include "pair.hpp"

#define RED 0
#define BLACK 1
#define _grandParent _parent->_parent

namespace ft {
	template<class T>
	class Node {
		public:
			Node() :
				_data(T()),
				_parent(0),
				_left(0),
				_right(0),
				_color(RED) {};

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


	template<class T, class Compare, class Allocator = std::allocator<T> >
	class RBTree {
		#include "printTree.hpp"
		public:
			typedef T value_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef typename Allocator::pointer pointer;
			typedef Node<T> Node;
//			typedef typename Allocator::template node_allocator;
//			typedef typename node_allocator::pointer pointer;

			RBTree() : _root(0), _compare(key_compare()) {};
			RBTree(value_type value) : _root(new Node(value)), _compare(key_compare()) {
				this->_root->setColor(BLACK);
			};

			void clear(Node *node) {

				if (node->_right) {
					clear(node->_right);
				}
				if (node->_left) {
					clear(node->_left);
				}
				std::cout << "node value = " << node->_data._second << std::endl;
				std::cout << "!node left = " << !node->_left << std::endl;
				std::cout << "!node right = " << !node->_right << std::endl;
				if (node->_right) {
					std::cout << "fuck right node = " << node->_right->_data._second << std::endl;
				}
				if (!node->_left && !node->_right) {
					delete node;
					node = 0;
				}
			}

			~RBTree() {
				clear(this->_root);
				delete this->_root;
				std::cout << "tree deleted" << std::endl;
			}

			void print() {
				print_tree(this->_root);
				std::cout << std::endl;
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
				return root;
			}
			pointer insert(value_type value) {
				Node *node = new Node(value);
				this->_root = insertHelper(this->_root, node);
				insertFix(this->_root, node);
				return &(node->_data);
			};

			Node *_root;
			key_compare _compare;
	};
}

#endif
