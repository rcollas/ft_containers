#ifndef REWORK_FT_CONTAINERS_RBTREEITERATOR_HPP
#define REWORK_FT_CONTAINERS_RBTREEITERATOR_HPP




template<typename Type>
struct RbTreeIterator {

	typedef Type	value_type;
	typedef Type&	reference;
	typedef Type*	pointer;

	typedef ft::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t 				difference_type;

	typedef RbTreeIterator<Type>		self;

	Node* node;

	RbTreeIterator()
			: node() {}

	explicit
	RbTreeIterator(Node* x)
			: node(x) {}

	Node*
	RbTreeDecrement(Node* x) {

		if (x->color == red
			&& x->parent->parent == x) {
			x = x->right;
		} else if (x->left != 0) {
			Node* y = x->left;
			while (y->right != 0) {
				y = y->right;
			}
			x = y;
		} else {
			Node* y = x->parent;
			while (x == y->left) {
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return x;
	}

	Node*
	RbTreeIncrement(Node* x) {

		if (x->right != 0) {
			x = x->right;
			while (x->left != 0) {
				x = x->left;
			}
		} else {
			Node* y = x->parent;
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

	reference
	operator*() const
	{ return this->node->valueField; }

	pointer
	operator->() const
	{ return &this->node->valueField; }

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
	typedef std::ptrdiff_t 					difference_type;

	typedef RbTreeConstIterator<Type>			self;

	const Node* node;

	RbTreeConstIterator()
			: node() {}

	explicit
	RbTreeConstIterator(Node* x)
			: node(x) {}

	explicit
	RbTreeConstIterator(const Node* x)
	: node(x) {}

	RbTreeConstIterator(const iterator& it)
			: node(it.node) {}

	const Node*
	RbTreeDecrement(const Node* x) {

		if (x->color == red
			&& x->parent->parent == x)
			x = x->right;
		else if (x->left != 0)
		{
			Node* y = x->left;
			while (y->right != 0)
				y = y->right;
			x = y;
		}
		else
		{
			Node* y = x->parent;
			while (x == y->left) {
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return x;
	}

	const Node*
	RbTreeIncrement(const Node* x) {

		if (x->right != 0) {
			x = x->right;
			while (x->left != 0) {
				x = x->left;
			}
		} else {
			Node* y = x->parent;
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

	reference
	operator*() const
	{
		return this->node->valueField; }

	pointer
	operator->() const
	{
		return &this->node->valueField; }

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

#endif