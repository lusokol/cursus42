/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:31:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/19 19:14:57 by lusokol          ###   ########.fr       */
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
		
		bool is_black:1;
		int value;

		node(int val) : parent(NULL), left(NULL), right(NULL), is_black(false), value(val) {}
	};

	template <class T, class Alloc = std::allocator<node> >
	class map {
		
		private:
			Alloc _myAlloc;			
			node *root;
			node *last;
		
		public:

			map(void) : root(NULL) {}
			~map(void) {
				this->clear(root);
			}

			node *getNode(void) { return root; }

		private:

			void clear(node *actual) {
				if (actual->right)
					clear(actual->right);
				if (actual->left)
					clear(actual->left);
				this->_myAlloc.destroy(actual);
				this->_myAlloc.deallocate(actual, 1);
			}

			node *new_node(T val, node *parent, bool is_black) {
				node *tmp;
				tmp = _myAlloc.allocate(1);
				_myAlloc.construct(tmp, val); 
				tmp->parent = parent;
				tmp->is_black = is_black;
				this->last = tmp;
				return (tmp);
			} 

		private:

			node *insert_bis(node *actual, T val, node *parent, bool is_black) {
				if (actual == NULL)
					return (new_node(val, parent, is_black));
				if (val <= actual->value)
					actual->left = insert_bis(actual->left, val, actual, is_black);
				else if (val > actual->value)
					actual->right = insert_bis(actual->right, val, actual, is_black);
				return (actual);
			}
		
		public:

			/* bool check_violation(void) {
				if (root->is_black == false)
					return 1;
				return 0;
			} */

			node *getParent(node *x) {
				if (x->parent)
					return x->parent;
				else
					return NULL;
			}

			node *getGP(node *x) {
				return this->getParent(this->getParent(x));
			}

			node *getUncle(node *x) {
				if (this->getParent(x) && this->getGP(x)->right == this->getParent(x))
					return (this->getGP(x)->left);
				else if (this->getParent(x) && this->getGP(x)->left == this->getParent(x))
					return (this->getGP(x)->right);
				else
					return NULL;
			}

			bool is_leftGP(node *x) {
				if (getParent(x) == getGP(x)->left)
					return true;
				return false;
			}

			bool is_leftP(node *x) {
				if (getParent(x)->left == x)
					return true;
				return false;
			}

			/* void check_node(node *x) {
				if (!this->getParent(x)->is_black)
			} */
			
			void insert_fix(void) {
				
				while (last && !this->last->is_black && !getParent(last)->is_black) { // 1
					if (is_leftGP(last)) {	
						//std::cout << "5" << std::endl;								  // 2
						if (getUncle(last) && !getUncle(last)->is_black) {    // 2.a)
							//std::cout << "1" << std::endl;
							getUncle(last)->is_black = true;
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							last = getGP(last);								  // 2.b)
						}
						else {
							if (!is_leftP(last)) {
								//std::cout << "2" << std::endl;
								last = getParent(last);
								this->rotate_left(last);
							}
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							this->rotate_right(getGP(last));
						}
					}
					else {
						//std::cout << "6" << std::endl;
						if (getUncle(last) && !getUncle(last)->is_black) {
							//std::cout << "3" << std::endl;
							getUncle(last)->is_black = true;
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							last = getGP(last);
						}
						else {
							if (is_leftP(last)) {
								//std::cout << "4" << std::endl;
								last = getParent(last);
								rotate_right(last);
							}
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							rotate_left(getGP(last));
						}
					}
					getNode()->is_black = true;
				//std::cout << "last value : " << last->value << std::endl;
				/* if (x->left) {
					if (!x->is_black && !x->left->is_black)
						x->left->is_black = true;
					insert_fix(x->left);
				}
				if (x->right) {
					if (!x->is_black && !x->right->is_black)
						x->right->is_black = true;
					insert_fix(x->right);
				} */
				}
			}

			void insert(T val) {
				bool is_black = false;
				if (!root)
					is_black = true;
				root = insert_bis(this->getNode(), val, NULL, is_black);
				insert_fix();
			}

			/*
					P					P		
					|					|		
				   (X)				   (Y)		
				   / \		---->	   / \		
				  a	 (Y)			 (X)  c
				     / \			 / \	
					b   c			a   b	
			*/

			void rotate_left(node *x) {
				node *y = x->right;
			    x->right = y->left;
			    if (y->left != NULL) {
			      y->left->parent = x;
			    }
			    y->parent = x->parent;
			    if (x->parent == NULL) {
			      this->root = y;
			    } else if (x == x->parent->left) {
			      x->parent->left = y;
			    } else {
			      x->parent->right = y;
			    }
			    y->left = x;
			    x->parent = y;
			}
			
			/*
					P				P					
					|				|					
				   (Y)			   (X)					
				   / \	  ---->	   / \				
				 (X)  a 		  c	 (Y)			
				 / \			     / \			
				c   b				b   a			
			*/

			void rotate_right(node *x) {

				node *y = x->left;
			    x->left = y->right;
			    if (y->right != NULL) {
			      y->right->parent = x;
			    }
			    y->parent = x->parent;
			    if (x->parent == NULL) {
			      this->root = y;
			    } else if (x == x->parent->right) {
			      x->parent->right = y;
			    } else {
			      x->parent->left = y;
			    }
			    y->right = x;
    			x->parent = y;
			}

			void rotate_left_right(node *p) {
				if (p && p->left)
					this->rotate_left(p->left);
				if (p)
					this->rotate_right(p);
			}
			
			void rotate_right_left(node *p) {
				if (p && p->right)
					this->rotate_right(p->right);
				if (p)
					this->rotate_left(p);
			}

			//////////////////////////////// display binary tree ///////////////////////////////
			#include "map_display.hpp"
			////////////////////////////////// end of display /////////////////////////////////
			
		
	};

}

#endif