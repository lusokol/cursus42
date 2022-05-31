/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:54:53 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/31 18:18:06 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include "rbt.hpp"
# include "lexicographical_compare.tpp"

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

			template <class InputIterator>
 			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : 
			_myAlloc(alloc), 
			_key_comp(comp),
			_value_comp(comp),
			_rbt(_myAlloc, _value_comp)
			{
				 this->insert(first, last);
			}

			map (const map& x) : _myAlloc(x._myAlloc), _key_comp(x._key_comp), _value_comp(x._value_comp), _rbt(_myAlloc, _key_comp) {
				this->insert(x.begin(), x.end());
			}

			~map(void) {}

			map<key_type, value_type, key_compare, allocator_type> &operator=(map<key_type, value_type, key_compare, allocator_type> const &ref) {
				this->_rbt = ref._rbt;
				this->_myAlloc = ref._myAlloc;
				this->_key_comp = ref._key_comp;
				this->_value_comp = ref._value_comp;
				return (*this);
			}

			// * // MODIFIERS // * //
			
			ft::pair<iterator, bool> insert (const value_type& val) {
				return (this->_rbt.insert(this->end(), val));
				// return (this->_rbt.insert(val));
			}

			iterator insert (iterator position, const value_type& val) {
				return (this->_rbt.insert(position, val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (; first != last; ++first)
					this->_rbt.insert(this->end(), *first);
			}

			iterator begin(void) { return this->_rbt.begin(); }
			const_iterator begin(void) const { return this->_rbt.begin(); }
			
			iterator end(void) { return this->_rbt.end(); }
			const_iterator end(void) const { return this->_rbt.end(); }

			reverse_iterator rbegin(void) { return this->_rbt.rbegin(); }
			const_reverse_iterator rbegin(void) const { return this->_rbt.rbegin(); }
			
			reverse_iterator rend(void) { return this->_rbt.rend(); }
			const_reverse_iterator rend(void) const { return this->_rbt.rend(); }

			iterator find (const key_type& k) { return (this->_rbt.find(ft::make_pair(k, mapped_type())));}
			const_iterator find (const key_type& k) const { return (this->_rbt.find(ft::make_pair(k, mapped_type()))); }

			bool empty() const { return (this->_rbt.empty()); }
			size_type size() const { return (this->_rbt.size()); }
			size_type max_size() const { return (this->_rbt.max_size()); }

			size_type count (const key_type& k) const {
				return (this->_rbt.find(ft::make_pair(k, mapped_type())) != this->end());
			}

			iterator lower_bound (const key_type& k) { return (this->_rbt.lower_bound(ft::make_pair(k, mapped_type()))); }
			const_iterator lower_bound (const key_type& k) const { return (this->_rbt.lower_bound(ft::make_pair(k, mapped_type()))); }
			
			iterator upper_bound (const key_type& k) { return (this->_rbt.upper_bound(ft::make_pair(k, mapped_type()))); }
			const_iterator upper_bound (const key_type& k) const { return (this->_rbt.upper_bound(ft::make_pair(k, mapped_type()))); }

			pair<const_iterator, const_iterator> equal_range (const key_type& k) const {
				const_iterator it = upper_bound(k);
				const_iterator ite = lower_bound(k);
				return (ft::make_pair<const_iterator, const_iterator>(ite, it));
			}
			
			pair<iterator, iterator> equal_range (const key_type& k) {
				iterator it = upper_bound(k);
				iterator ite = lower_bound(k);
				return (ft::make_pair<iterator, iterator>(ite, it));
			}
			
			key_compare key_comp() const { return (this->_key_comp); }
			value_compare value_comp() const { return (this->_value_comp); }
			
			mapped_type& operator[] (const key_type& k) {
				//std::cout << "pair : " << ft::make_pair(k, mapped_type()) << std::endl;
				// std::cout << "K = " << k << std::endl;
				iterator it = this->find(k);
				if (it == this->end())
					it = this->insert(ft::make_pair(k, mapped_type())).first;
				return (it->second);
			}

			void clear() { this->_rbt.clear_call(); }

			void erase (iterator position) { this->_rbt.erase(position); }
			
			size_type erase (const key_type& k) {
				size_type ret = this->count(k);
				if (ret > 0)
					this->_rbt.erase(this->find(k));
				return ret;
			}
			
			void erase (iterator first, iterator last) {
				iterator it;
				while (first != last) {
					it = first;
					++first;
					this->_rbt.erase(it);
				}
			}

			void swap(map<Key, T, Compare, allocator_type> &m) {
				this->_rbt.swap(m._rbt);
			}

			//! A NE PAS LAISSER
			void print_tree(void) {
				_rbt.print_tree(_rbt.getNode());
			}
			//! ////////////////

	};

	
	template <typename Key, typename T, typename Compare, typename Allocator>
	bool	operator==(map<Key, T, Compare, Allocator> const &lhs,
	map<Key, T, Compare, Allocator> const &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool	operator<(map<Key, T, Compare, Allocator> const &lhs,
	map<Key, T, Compare, Allocator> const &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool	operator!=(map<Key, T, Compare, Allocator> const &lhs,
	map<Key, T, Compare, Allocator> const &rhs) {
		return (!(lhs == rhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool	operator>(map<Key, T, Compare, Allocator> const &lhs,
	map<Key, T, Compare, Allocator> const &rhs) {
		return (rhs < lhs);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool	operator<=(map<Key, T, Compare, Allocator> const &lhs,
	map<Key, T, Compare, Allocator> const &rhs) {
		return (!(rhs < lhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool	operator>=(map<Key, T, Compare, Allocator> const &lhs,
	map<Key, T, Compare, Allocator> const &rhs) {
		return (!(lhs < rhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	void swap(map<Key, T, Compare, Allocator> &lhs, map<Key, T, Compare, Allocator> &rhs) {
		lhs.swap(rhs);
	}

}

#endif