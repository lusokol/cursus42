/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:31:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/18 18:51:06 by lusokol          ###   ########.fr       */
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
			#include "map_display.hpp"
			////////////////////////////////// end of display /////////////////////////////////
			
		
	};

}

#endif