/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:31:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/24 21:06:47 by lusokol          ###   ########.fr       */
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
		~node(void) {}
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
				if (!actual)
					return ;
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
			
			void insert_fix(void) {
				
				while (last && !this->last->is_black && !getParent(last)->is_black) { // 1
					if (is_leftGP(last)) {	
						if (getUncle(last) && !getUncle(last)->is_black) {
							getUncle(last)->is_black = true;
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							last = getGP(last);
						}
						else {
							if (!is_leftP(last)) {
								last = getParent(last);
								this->rotate_left(last);
							}
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							this->rotate_right(getGP(last));
						}
					}
					else {
						if (getUncle(last) && !getUncle(last)->is_black) {
							getUncle(last)->is_black = true;
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							last = getGP(last);
						}
						else {
							if (is_leftP(last)) {
								last = getParent(last);
								rotate_right(last);
							}
							getParent(last)->is_black = true;
							getGP(last)->is_black = false;
							rotate_left(getGP(last));
						}
					}
					getNode()->is_black = true;
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
				if (y)
			    	x->right = y->left;
			    if (y && y->left != NULL) {
			      y->left->parent = x;
			    }
				if (y)
					y->parent = x->parent;
			    if (x->parent == NULL) {
			      this->root = y;
			    } else if (x == x->parent->left) {
			      x->parent->left = y;
			    } else {
			      x->parent->right = y;
			    }
			    if (y)
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
				if (y)
					x->left = y->right;
			    if (y && y->right != NULL) {
			      y->right->parent = x;
			    }
				if (y)
					y->parent = x->parent;
			    if (x->parent == NULL) {
			      this->root = y;
			    } else if (x == x->parent->right) {
			      x->parent->right = y;
			    } else {
			      x->parent->left = y;
			    }
				if (y)
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

			private:

				node *minimum(node *p) {
					while (p && p->left)
						p = p->left;
					return p;
				}
				
				node *maximum(node *p) {
					while (p && p->right)
						p = p->right;
					return p;
				}

				 void rbTransplant(node *u, node *v) {
					if (u->parent == NULL)
						root = v;
					else if (this->is_leftP(u))
						u->parent->left = v;
					else
						u->parent->right = v;
					v->parent = u->parent;
				}

				void deleteFix(node *x) {
					node *w;
					while (x && x != root && x->is_black) {
						if (is_leftP(x)) {
							if (x && x->parent && x->parent->right)
								w = x->parent->right;
							if (w && !w->is_black) {
								//* CASE 1
								w->is_black = true;
								w->parent->is_black = false;
								rotate_left(x->parent);
								w = x->parent->right;
							}
							if (w && w->right && w->right->is_black && w->left && w->left->is_black) {
								//* CASE 2
								w->is_black = false;
								x = x->parent;
							}
							else {
								if (w && w->right && w->right->is_black) {
									//* CASE 3
									w->left->is_black = true;
									w->is_black = false;
									rotate_right(w);
									w = x->parent->right;
								}
								if (w)
									w->is_black = x->parent->is_black;
								x->parent->is_black = true;
								if (w && w->right)
									w->right->is_black = true;
								rotate_left(x->parent);
								x = root;
							}
						}
						else if (!is_leftP(x)) {
							if (x && x->parent && x->parent->left)
								w = x->parent->left;
							if (w && !w->is_black) {
								// * CASE 1
								w->is_black = true;
								w->parent->is_black = false;
								rotate_right(x->parent);
								w = x->parent->left;
							}
							if (w && w->left && w->left->is_black && w->right && w->right->is_black) {
								// * CASE 2
								w->is_black = false;
								x = x->parent;
							}
							else {
								if (w && w->left && w->left->is_black) {
									// * CASE 3
									if (w->right)
										w->right->is_black = true;
									w->is_black = false;
									rotate_left(w);
									w = x->parent->left;
								}
								if (w && x && x->parent)
									w->is_black = x->parent->is_black;
								x->parent->is_black = true;
								if (w && w->left)
									w->left->is_black = true;
								rotate_right(x->parent);
								x = root;
							}
						}
						if (x)
							x->is_black = true;
					}
						/* else {
								// * CASE 4
								if (x && x->parent && x->parent->left)
									w = x->parent->left;
								if (w && !w->is_black) {
									w->is_black = true;
									x->parent->is_black = false;
									rotate_right(x->parent);
									w = x->parent->left;
								}

								if (w && w->right && w->right->is_black && w->right->is_black) {
									w->is_black = false;
									x = x->parent;
								}
								else {
									if (w && w->left && w->left->is_black) {
										if (w && w->right)
											w->right->is_black = true;
										if (w)
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
							} */


							
						/* else {
							//! ////////

							if (!is_leftP(x)) {
							w = x->parent->left;
								if (!w->is_black) {
									// * CASE 1
									w->is_black = true;
									w->parent->is_black = false;
									rotate_right(x->parent);
									x->parent->left = w;
								}
								if (w->left->is_black && w->right->is_black) {
									// * CASE 2
									w->is_black = false;
									x = x->parent;
								}
								else {
									if (w->left->is_black) {
										// * CASE 3
										w->right->is_black = true;
										w->is_black = false;
										rotate_left(w);
										w = x->parent->left;
									}
									else {
										// * CASE 4
										w->is_black = x->parent->is_black;
										x->parent->is_black = true;
										w->left->is_black = true;
										rotate_right(x->parent);
										root = x;
									}
								}
							}
							
							//! ////////
						} */
				}

			public:

			void delete_node(node *del) {
				node *x;
				node *y = del;
				if (!del)
					return ;
				bool color = del->is_black;
				if (del->right == NULL && del->left == NULL)
					root = NULL;
				else if (del->left == NULL) {
					x = del->right;
					rbTransplant(del, del->right);
				}
				else if (del->right == NULL) {
					x = del->left;
					rbTransplant(del, del->left);
				}
				else {
					y = minimum(del->right);
					color = y->is_black;
					x = y->right;
					if (y->parent == del) {
						if (x)
							x->parent = y;
					}
					else {
						if (y && y->right)
							rbTransplant(y, y->right);
						else {
							if (this->is_leftP(y))
								y->parent->left = y->right;
							else
								y->parent->right = y->right;
						}
						y->right = del->right;
						y->right->parent = y;
					}
					rbTransplant(del, y);
					y->left = del->left;
					y->left->parent = y;
					y->is_black = del->is_black;
				}
				_myAlloc.destroy(&del);
				_myAlloc.deallocate(del, 1);
				// TODO delete fix
				if (color)
					deleteFix(x);
			}
			
			//////////////////////////////// display binary tree ///////////////////////////////
			#include "map_display.hpp"
			////////////////////////////////// end of display /////////////////////////////////
			
		
	};

}

#endif