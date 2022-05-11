#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include <vector>

namespace ft {
	template<class T, class Container = std::vector<T> >
	class stack{
		public:
			typedef Container container_type ;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

			explicit stack(const Container& cont = Container()) { this->c = cont; };
			stack( const stack& other ) { this->c(other); };
			~stack() {};

			stack& operator=( const stack& other ) { this->c = other.c; };

			bool empty() const { return this->c.empty(); };
			size_type size() const { return this->c.size(); };

			reference top() { return c.back(); };
			const_reference top() const { return c.back(); };

			void push(const value_type& value) { this->c.push_back(value); };
			void pop() { this->c.pop_back(); };

		protected:
			Container c;

		friend bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.c == rhs.c; };
		friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c != rhs.c; };
		friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c < rhs.c; };
		friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c <= rhs.c; };
		friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c > rhs.c; };
		friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c >= rhs.c; };
	};
}

#endif
