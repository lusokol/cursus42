/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:31:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/18 13:19:49 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
# include <memory>
# include <vector>

namespace ft {

	class	node {
		public:

		node *parent;
		node *left;
		node *right;

		int value;

		node(int val) : parent(NULL), left(NULL), right(NULL), value(val) {}
	};

	template <class T, class Alloc = std::allocator<node> >
	class map {
		
		private:
			Alloc _myAlloc;			
			node *root;
		
		public:

			map(void) : root(NULL) {}
			~map(void) {}

			node *getNode(void) { return root; }

		private:

			node *new_node(T val, node *parent) {
				node *tmp;
				tmp = _myAlloc.allocate(1);
				_myAlloc.construct(tmp, val); 
				tmp->parent = parent;
				return (tmp);
			} 

		private:

			node *insert_bis(node *actual, T val, node *parent) {
				if (actual == NULL)
					return (new_node(val, parent));
				if (val <= actual->value)
					actual->left = insert_bis(actual->left, val, actual);
				else if (val > actual->value)
					actual->right = insert_bis(actual->right, val, actual);
				return (actual);
			}
		
		public:

			void insert(T val) {
				root = insert_bis(this->getNode(), val, NULL);
			}

			// void aff_tree(node *actual) {
			// 	if (!actual)
			// 		return ;
			// 	if (actual->left)
			// 		aff_tree(actual->left);
			// 	else {
			// 		std::cout << actual->value << " ";
			// 		return ;
			// 	}
			// 	std::cout << actual->value << " ";
			// 	if (actual->right)
			// 		aff_tree(actual->right);
			// 	else {
			// 		std::cout << actual->value << " ";
			// 		return ;
			// 	}
			// 	return ;
			// }

			/* void aff_tree(node *actual) {
				std::cout << actual->value << "\t";
				if (actual->left)
					aff_tree(actual->left);
				if (actual->right)
					aff_tree(actual->right);
			} */
			
			//////////////////////////////// display binary tree ///////////////////////////////
			int count_from_node(node *ptr, int count = 0) {
				if (ptr) {
				if (ptr->right)
					count += count_from_node(ptr->right);
				if (ptr->left)
					count += count_from_node(ptr->left);
				return (++count);
				}
				return count;
			}

			int count_btw_p(node *ptr) {
				if (ptr->parent->right == ptr) {
					return count_from_node(ptr->left);		
				}
				else {
					return count_from_node(ptr->right);		
				}
			}

			std::vector<std::vector <int> > aff;

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

			void aff_tree(int level, node *ptr, bool is_right)
			{
				int i;
				if (ptr != NULL)
				{
					aff_tree(level + 1, ptr->right, 1);
					std::cout << std::endl;
					if (ptr == root)
						std::cout << "Root -> ";
					for (i = 0; i < level && ptr != root; i++) {
						if (search_v(i))
							std::cout << "│       ";
						else
							std::cout << "        ";
						
					}
					if (ptr != root) {
						if (ptr == ptr->parent->right && count_btw_p(ptr) > 0) {
							std::vector<int> tmp;
							tmp.push_back(level);
							tmp.push_back(count_btw_p(ptr));
							aff.push_back(tmp);
						}
						if (is_right) {
							std::cout << "╭──────";
						}
						else {
							std::cout << "╰──────";
							
						}
					}
					if (ptr->left && count_btw_p(ptr->left) > 0) {
						std::vector<int> tmp;
						tmp.push_back(level + 1);
						tmp.push_back(count_btw_p(ptr->left));
						aff.push_back(tmp);
					}
					std::cout << ptr->value;
					aff_tree(level + 1, ptr->left, 0);
				}
			//////////////////////////////// end of display ///////////////////////////////
}
			
		
	};

}

#endif