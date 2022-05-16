/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:04:32 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/16 17:49:01 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#ifndef STACK_HPP
# define STACK_HPP

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {
		
		public:
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef Container container_type;
		
			template <typename _T, typename _Container>
			friend bool	ft::operator==(stack<_T, _Container> const &lhs,
			stack<_T, _Container> const &rhs);

			template <typename _T, typename _Container>
			friend bool	ft::operator<(stack<_T, _Container> const &lhs,
			stack<_T, _Container> const &rhs);
			
		protected:
			Container ctnr;

		public:
		
			explicit stack (const container_type& ctnr = container_type()) : ctnr(ctnr) {}

			bool empty () const { return (ctnr.empty()); }
			size_type size() const { return (ctnr.size()); }
			value_type& top() { return (ctnr.back()); }
			const value_type& top() const { return (ctnr.back()); }
			void push (const value_type& val) { ctnr.push_back(val); }
			void pop() { ctnr.pop_back(); }

	};

	/* template <typename T, typename Container>
	bool	operator==(stack<T, Container> const &lhs,
	stack<T, Container> const &rhs) {
		return (lhs.ctnr == rhs.ctnr);
	} */
	
	template <typename T, typename Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.ctnr == rhs.ctnr);
	}

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (!(lhs == rhs));  
	}

	template <class T, class Container>
  	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return (lhs.ctnr < rhs.ctnr);
	}

	template <class T, class Container>
  	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs < rhs || lhs == rhs);
	}
	
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs > rhs || lhs == rhs);
	}
}

#endif