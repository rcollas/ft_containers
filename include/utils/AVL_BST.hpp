#ifndef FT_CONTAINERS_TMP_AVL_BST_HPP
#define FT_CONTAINERS_TMP_AVL_BST_HPP

namespace ft {
	template<class T, class U>
	class Node {
		public:
			Node() :
				_key(0),
				_value(0),
				_left(0),
				_right(0),
				_height(0) {};
			Node(T key, U value, int height) :
				_key(key),
				_value(value),
				_left(0),
				_right(0),
				_height(height) {};

			T _key;
			U _value;
			Node* _left;
			Node* _right;
			int _height;
	};

#define COUNT 5

	template<class T, class U>
	class AVLTree {
		public:
			typedef Node<T,U> Node;

			AVLTree() : _root(0) {};
			AVLTree(T key, U value) : _root(new Node(key, value, 0)) {};
			void print(Node* node, int space) const {
				if (node == 0) {
					return;
				}
				space += COUNT;
				print(node->_right, space);

				std::cout << std::endl;
				for (int i = COUNT; i < space; i++) {
					std::cout << " ";
				}
				std::cout << node->_value << std::endl;
				print(node->_left, space);
			}

			void insertHelper(T key, U value, Node* node) {
				if (!this->_root) {
					this->_root = new Node(key, value, 0);
				} else {
					if (!node->_right && value > node->_value) {
						node->_right = new Node(key, value, 0);
					} else if (!node->_left && value <= node->_value) {
						node->_left = new Node(key, value, 0);
					} else if (value > node->_value) {
						insertHelper(key, value, node->_right);
					} else {
						insertHelper(key, value, node->_left);
					}
				}
			}
			void insert(T key, U value) {
				insertHelper(key, value, this->_root);
			};

			U searchHelper(U key, Node* node) {

				(void)key;
				(void)node;
				return 0;
			}
			U search(U key) {
				return searchHelper(key, this->_root);
			}

			Node *_root;
	};
}

#endif
