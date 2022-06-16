
#ifndef MAP_DISPLAY_HPP
# define MAP_DISPLAY_HPP 1

# define __BLACK "\033[40m"
# define __RED   "\e[1;41m"
# define __STOP  "\033[0m"

#include "RBT.hpp"

int countFromNode(ft::RbTreeNodeBase* ptr, int count = 0) {
	if (ptr != 0) {
		if (ptr->right != 0)
			count += countFromNode(ptr->right);
		if (ptr->left != 0)
			count += countFromNode(ptr->left);
		return ++count;
	}
	return count;
}

int countBtwP(ft::RbTreeNodeBase* ptr, bool isRight) {
	if (isRight) {
		return countFromNode(ptr->left);
	} else {
		return countFromNode(ptr->right);
	}
}

std::vector<std::vector<int> > aff;


bool search_v(int level) {
	for (size_t i = 0; i < aff.size(); i++) {
		if (aff[i][0] == level) {
			aff[i][1]--;
			if (aff[i][1] <= 0)
				aff.erase(aff.begin() + i);
			return (true);
		}
	}
	return (false);
}

void aff_chars(std::string a, std::string b, int size = -1) {
	size = (size == -1) ? a.size() : size;
	std::cout << a;
	for (int i = 5; i - size > 0; i--)
		std::cout << b;
}


void print_tree(ft::RbTreeNodeBase* ptr, int level = 0, bool is_right = 0)
{
	int i;
	if (ptr != 0)
	{
		print_tree(ptr->right, level + 1, 1);
		std::cout << std::endl;
		for (i = 1; i < level && ptr != impl.header.parent; i++) {
			if (search_v(i))
				aff_chars("│", " ", 1);
			else
				aff_chars(" ", " ");
		}
		if (ptr != impl.header.parent) {
			if (is_right && countBtwP(ptr, is_right) > 0) {
				std::vector<int> tmp;
				tmp.push_back(level);
				tmp.push_back(countBtwP(ptr, is_right));
				aff.push_back(tmp);
			}
			if (is_right)
				aff_chars("╭", "─", 1);
			else
				aff_chars("╰", "─", 1);
		}
		if (ptr->left != 0 && countBtwP(ptr->left, 0) > 0) {
			std::vector<int> tmp;
			tmp.push_back(level + 1);
			tmp.push_back(countBtwP(ptr->left, 0));
			aff.push_back(tmp);
		}
		if (ptr->color == black)
			std::cout << __BLACK << key(ptr) << __STOP;
		else
			std::cout  << __RED << key(ptr) << __STOP;
		print_tree(ptr->left, level + 1, 0);
	}
}

#endif /* MAP_DISPLAY_HPP */