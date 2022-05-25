/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:54:53 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/25 19:06:46 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include "rbt.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = allocator<pair<const Key,T> > >
	class map {
		public:
		
			typedef key key_type;
			typedef T mapped_type;
			typedef pair<const Key, T> value_type;
			typedef Compare key_compare;
			
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

			typedef Alloc allocator_type;
			typedef allocator_type::reference reference;
			typedef allocator_type::const_reference const_reference;
			typedef allocator_type::pointer pointer;
			typedef allocator_type::const_pointer const_pointer;
			// TODO typedef iterator
			// TODO typedef const_iterator
			// TODO typedef reverse_iterator
			// TODO typedef const_reverse_iterator
			typedef std::ptrdiff_t difference_type;
			typedef std::size_t size_type;

	};

}

#endif