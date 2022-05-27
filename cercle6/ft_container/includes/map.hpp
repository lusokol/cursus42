/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:54:53 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/27 20:08:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include "rbt.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<Key const, T> > >
	class map {
		public:
		
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<Key const, T> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			
			class value_compare: public std::binary_function<value_type, value_type, bool> {
					private:
						friend class map;
					protected:
						key_compare comp;
						value_compare(key_compare c): comp(c) {
						}
					public:
						bool	operator()(value_type const &lhs, value_type const &rhs) const {
							return (comp(lhs.first, rhs.first));
						}
				};

		private:
			typedef rbt<value_type, allocator_type, value_compare> tree_type;

		public:

			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename tree_type::iterator iterator;
			typedef typename tree_type::const_iterator const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef std::size_t size_type;

		private:

			allocator_type _myAlloc;
			key_compare _key_comp;
			value_compare _value_comp;
			tree_type _rbt;

		public:

			// * // CONSTRUCTOR // * //

			explicit map (const key_compare& comp = key_compare(), const allocator_type& allocT = allocator_type()) :
			_myAlloc(allocT), 
			_key_comp(comp),
			_value_comp(comp),
			_rbt(_myAlloc, _value_comp) {}

			/* template <class InputIterator>
 			map (InputIterator first, InputIterator last,
    		const key_compare& comp = key_compare(),
    		const allocator_type& alloc = allocator_type()); */

			/* map (const map& x) {
				
			} */

			~map(void) {}

			// * // MODIFIERS // * //
			
			void /* ft::pair<int,char> */ insert (const value_type& val) {
				this->_rbt.insert(val);
				// return (this->_rbt.insert(val));
			}

			// TODO hint
			// ? iterator insert (iterator position, const value_type& val);

			// TODO iterator
			// ? template <class InputIterator>
  			// ? void insert (InputIterator first, InputIterator last);

			iterator find (const key_type& k) { return (_rbt->search(k));}
			const_iterator find (const key_type& k) const { return (_rbt->search(k)); }


			//! A NE PAS LAISSER
			void print_tree(void) {
				_rbt.print_tree(_rbt.getNode());
			}
			//! ////////////////

	};

}

#endif