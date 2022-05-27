/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:31:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/27 15:38:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <iostream>
# include <memory>
# include <vector>
# include "iterator.hpp"

namespace ft {

	template <typename T, typename Node>
    class MapIterator {
        
        public:
			typedef T * pointer;
			typedef T & reference;
			typedef T const * const_pointer;
			typedef T const & const_reference;
			typedef T value_type;
			typedef Node * node_ptr;
			typedef std::ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef Node *node_ptr;
        
		private:
            node_ptr _current;
            node_ptr _root;
            node_ptr _nil;
			
		public:

			pointer const &base(void) const { return (this->_ptr); }

            //================= constructor / copy / destructor =================//
            MapIterator(void): _current(NULL), _root(NULL), _nil(NULL) {}
            MapIterator(node_ptr current, node_ptr root, node_ptr nil): _current(current), _root(root), _nil(nil) {}
            template <typename U>
                MapIterator(MapIterator<U> const &ref) : _current(ref.current), _root(ref.root), _nil(ref.nil) {}
            ~MapIterator(void) {}

            //============================ operator =============================//
            friend bool operator==(const MapIterator &a, const MapIterator &b) { return a._current == b._current; };
            friend bool operator!=(const MapIterator &a, const MapIterator &b) { return a._current != b._current; };
            reference operator*() const { return *(_current->value); }
            pointer operator->() { return &this->operator*(); }
            MapIterator &operator=(MapIterator<T, Node> const &ref) {
                this->_current = ref._current;
                this->_root = ref._root;
                this->_nil = ref._nil;
                return (*this);
            }
            MapIterator &operator++() {
                _current = this->_next(this->current);
                return *this;
            }
            MapIterator operator++(int) {
                MapIterator tmp(this->_current, this->_root, this->_nil);
				_current = this->_next(this->current);
                return tmp;
            }
            MapIterator &operator--() {
                _current = this->_prev(this->current);
                return *this;
            }
            MapIterator operator--(int) {
                MapIterator tmp(this->_current, this->_root, this->_nil);
				_current = this->_prev(this->current);
                return tmp;
            }

		private:
			
			node_ptr	_max(node_ptr node) {
				if (node != this->_nil)
					while (node->right != this->_nil)
						node = node->right;
				return (node);
			}

			node_ptr	_min(node_ptr node) {
				if (node != this->_nil)
					while (node->left != this->_nil)
						node = node->left;
				return (node);
			}

			node_ptr	_next(node_ptr node) {
				if (node->right != this->_nil)
					return (this->_min(node->right));
				node_ptr parent = node->parent;
				while (parent != this->_nil && node == parent->right) {
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

			node_ptr	_prev(node_ptr node) {
				if (node->left != this->_nil)
					return (this->_max(node->left));
				node_ptr parent = node->parent;
				while (parent != this->_nil && node == parent->left) {
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

    };

	// Forward iterator requirements

	template <typename T, typename U>
	bool	operator==(MapIterator<T> const &lhs,
	MapIterator<U> const &rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T, typename U>
	bool	operator!=(MapIterator<T> const &lhs,
	MapIterator<U> const &rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	class	rbt_node {
		public:

		rbt_node *parent;
		rbt_node *left;
		rbt_node *right;
		
		bool is_black:1;
		T value;

		rbt_node(void) : parent(NULL), left(NULL), right(NULL), is_black(false), value(T()) {}
		rbt_node(T val) : parent(NULL), left(NULL), right(NULL), is_black(false), value(val) {}
		rbt_node(rbt_node const &ref) : parent(ref.parent), left(ref.left), right(ref.right), is_black(ref.is_black), value(ref.value) {
			
		}
		~rbt_node(void) {}

		rbt_node &operator=(rbt_node const &ref) {
			if (this != &ref) {
				this->value = ref.data;
				this->is_black = ref.color;
				this->parent = ref.parent;
				this->left = ref.left;
				this->right = ref.right;
			}
			return (*this);
		}
	};

	template <class T, class Allocator/*  = std::allocator<rbt_node<T> >*/, typename Compare = std::less<T> >
	class rbt {
		
		typedef rbt_node<T> node;
		typedef rbt_node<T> *node_ptr;
		typedef T value_type;
		typedef typename Allocator::template rebind<rbt_node<value_type> >::other allocator_type;
		typedef Compare compare_type;

		private:
			allocator_type _myAlloc;			
			node *root;
			node_ptr nil;
			compare_type _compare;
		
		public:

			rbt(allocator_type const &alloc = allocator_type(), compare_type const &compare = compare_type()) : _myAlloc(alloc), root(NULL), _compare(compare) {
				this->nil = _myAlloc.allocate(1);
				_myAlloc.construct(this->nil, node());
				this->nil->right = this->nil;
				this->nil->left = this->nil;
				this->nil->parent = this->nil;
				this->nil->is_black = true;
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

			node_ptr search(value_type val) const {
				node_ptr current = root;
				while (current != nil) {
					if (_compare(value, current->value))
						current = current->left;
					else if (_compare(current->value, value))
						current = current->right;
					else
						break ;
				}
				return current;
			}

			void insert(T val) {
				/* node_ptr tmp = root;
				while (tmp != nil && tmp->value->first != val->first) {
					if (tmp)
				} */

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
				if (z != nil)
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