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
			Node(Node* key, Node* value, int height) :
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

	template<class T, class U>
	class AVLTree {
		public:
			AVLTree() : _root(Node<T, U>()) {};
			AVLTree(T key, U value) : _root(Node<T, U>(key, value, 0)) {};

		private:
			Node<T, U> _root;
	};
}

#endif
