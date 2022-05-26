/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:31:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/26 15:01:55 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
# include <memory>
# include <vector>

namespace ft {

	template <typename T>
	class	rbt_node {
		public:

		rbt_node *parent;
		rbt_node *left;
		rbt_node *right;
		
		bool is_black:1;
		T value;

		rbt_node(T val) : parent(NULL), left(NULL), right(NULL), is_black(false), value(val) {}
		~rbt_node(void) {}
	};

	template <class T, class Allocator = std::allocator<rbt_node<T> >, typename Compare = std::less<T> >
	class rbt {
		
		typedef rbt_node<T> node;
		typedef rbt_node<T> *node_ptr;
		typedef T value_type;
		//typedef Compare

		private:
			Allocator _myAlloc;			
			node *root;
			node *nil;
		
		public:

			rbt(void) : root(NULL) {
				this->nil = new_node(T(), NULL, true);
				this->nil->right = this->nil;
				this->nil->left = this->nil;
				this->nil->parent = this->nil;
				root = this->nil;
			}
			~rbt(void) {
				this->clear(root);
				this->_myAlloc.destroy(nil);
				this->_myAlloc.deallocate(nil, 1);
			}

			node_ptr getNode(void) { return root; }

		private:

			void clear(node *actual) {
				if (actual == nil)
					return ;
				if (actual->right != nil)
					clear(actual->right);
				if (actual->left != nil)
					clear(actual->left);
				this->_myAlloc.destroy(actual);
				this->_myAlloc.deallocate(actual, 1);
			}

			node_ptr new_node(T val, node_ptr parent, bool is_black) {
				node_ptr tmp;
				tmp = _myAlloc.allocate(1);
				_myAlloc.construct(tmp, val); 
				tmp->parent = parent;
				tmp->right = nil;
				tmp->left = nil;
				tmp->is_black = is_black;
				return (tmp);
			} 

		private:

			node_ptr insert_bis(node_ptr actual, T val, node_ptr parent, bool is_black) {
				if (actual == nil)
					return (new_node(val, parent, is_black));
				if (val <= actual->value)
					actual->left = insert_bis(actual->left, val, actual, is_black);
				else if (val > actual->value)
					actual->right = insert_bis(actual->right, val, actual, is_black);
				return (actual);
			}
		
		public:

			node_ptr getParent(node_ptr x) {
				return x->parent;
			}

			node_ptr getGP(node_ptr x) {
				return x->parent->parent;
			}

			node_ptr getUncle(node_ptr x) {
				if (getGP(x)->right == x->parent)
					return (getGP(x)->left);
				return (getGP(x)->right);
			}

			bool is_leftGP(node_ptr x) {
				if (getParent(x) == getGP(x)->left)
					return true;
				return false;
			}

			bool is_leftP(node_ptr x) {
				if (getParent(x)->left == x)
					return true;
				return false;
			}
			
			void insert_fix(node_ptr z) {
				node *y = nil;
				while (z->parent->is_black == false) {
					if (z->parent == z->parent->parent->left) {
						y = z->parent->parent->right;
						if (y->is_black == false) {
							z->parent->is_black = true;
							y->is_black = true;
							z->parent->parent->is_black = false;
							z = z->parent->parent;
						}
						else {
							if (z == z->parent->right) {
								z = z->parent;
								rotate_left(z);
							}
							z->parent->is_black = true;
							z->parent->parent->is_black = false;
							rotate_right(z->parent->parent);
						}
					}
					else {
						y = z->parent->parent->left;
						if (y->is_black == false) {
							z->parent->is_black = true;
							y->is_black = true;
							z->parent->parent->is_black = false;
							z = z->parent->parent;
						}
						else {
							if (z == z->parent->left) {
								z = z->parent;
								rotate_right(z);
							}
							z->parent->is_black = true;
							z->parent->parent->is_black = false;
							rotate_left(z->parent->parent);
						}
					}
				}
				root->is_black = true;
			}

			void insert(T val) {
				node *z = new_node(val, nil, false);
				node *y = nil;
				node *x = root;
				while (x != nil) {
					y = x;
					if (z->value < x->value)
						x = x->left;
					else
						x = x->right;
				}
				z->parent = y;
				if (y == nil)
					root = z;
				else if (z->value < y->value)
					y->left = z;
				else
					y->right = z;
				z->left = nil;
				z->right = nil;
				z->is_black = false;
				insert_fix(z);
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

			void rotate_left(node_ptr x) {
				node *y = x->right;
			    x->right = y->left;
			    if (y->left != nil) {
			      y->left->parent = x;
			    }
				y->parent = x->parent;
			    if (x->parent == nil) {
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

			void rotate_right(node_ptr x) {

				node *y = x->left;
				x->left = y->right;
			    if (y && y->right != nil) {
			      y->right->parent = x;
			    }
				y->parent = x->parent;
			    if (x->parent == nil) {
			      this->root = y;
			    } else if (x == x->parent->right) {
			      x->parent->right = y;
			    } else {
			      x->parent->left = y;
			    }
				y->right = x;
    			x->parent = y;
			}

			void rotate_left_right(node_ptr p) {
				this->rotate_left(p->left);
				this->rotate_right(p);
			}
			
			void rotate_right_left(node_ptr p) {
				this->rotate_right(p->right);
				this->rotate_left(p);
			}

			private:

				node_ptr minimum(node_ptr p) {
					while (p->left != nil)
						p = p->left;
					return p;
				}
				
				node_ptr maximum(node_ptr p) {
					while (p->right != nil)
						p = p->right;
					return p;
				}

				 void rbTransplant(node_ptr u, node_ptr v) {
					if (u->parent == nil)
						root = v;
					else if (u == u->parent->left)
						u->parent->left = v;
					else
						u->parent->right = v;
					v->parent = u->parent;
				}

				void deleteFix(node_ptr x) {
					node *w;
					while (x != root && x->is_black) {
						if (x == x->parent->left) {
							w = x->parent->right;
							if (!w->is_black) {
								w->is_black = true;
								w->parent->is_black = false;
								rotate_left(x->parent);
								w = x->parent->right;
							}
							if (w->left->is_black && w->right->is_black) {
								w->is_black = false;
								x = x->parent;
							}
							else {
								if (w->right->is_black) {
									w->left->is_black = true;
									w->is_black = false;
									rotate_right(w);
									w = x->parent->right;
								}
								w->is_black = x->parent->is_black;
								x->parent->is_black = true;
								w->right->is_black = true;
								rotate_left(x->parent);
								x = root;
							}
						}
						else {
							w = x->parent->left;
							if (!w->is_black) {
								w->is_black = true;
								w->parent->is_black = false;
								rotate_right(x->parent);
								w = x->parent->left;
							}
							if (w->right->is_black && w->left->is_black) {
								w->is_black = false;
								x = x->parent;
							}
							else {
								if (w->left->is_black) {
									w->right->is_black = true;
									w->is_black = false;
									rotate_left(w);
									w = x->parent->left;
								}
								w->is_black = x->parent->is_black;
								x->parent->is_black = true;
								w->left->is_black = true;
								rotate_right(x->parent);
								x = root;
							}
						}
					}
					x->is_black = true;
				}

			public:

			void delete_node(node_ptr z) {
				node *x;
				node *y = z;
				bool y_original_color = y->is_black;
				if (z->left == nil) {
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == nil) {
					x = z->left;
					rbTransplant(z, z->left);
				}
				else {
					y = minimum(z->right);
					y_original_color = y->is_black;
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else {
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->is_black = z->is_black;
				}
				_myAlloc.destroy(&z);
				_myAlloc.deallocate(z, 1);
				if (y_original_color == true)
					deleteFix(x);
			}
			
			//? ////////////////////////////// display binary tree ///////////////////////////////
			#include "map_display.hpp"
			//? //////////////////////////////// end of display /////////////////////////////////
			
		
	};

}

#endif