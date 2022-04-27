/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:17:59 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/06 15:54:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack: public std::stack<T> {
    
public:

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

// CANONICAL

    MutantStack(void) {};
    
    MutantStack(MutantStack const &ref) {
        *this = ref;
    };
    
    ~MutantStack(void) {};
    
    MutantStack &operator=(MutantStack const &ref) {
        if (*this != ref)
            this->_stack = ref._stack;
        return (*this);
    };
    
// ALL ITERATORS
    
    iterator begin(void) { //iterator
		return (this->c.begin());
	};
	iterator end(void) { //iterator
		return (this->c.end());
	};
    const_iterator	begin(void) const { //const iterator
		return (this->c.begin());
	};
	const_iterator	end(void) const { //const iterator
		return (this->c.end());
	};
    reverse_iterator	rbegin(void) { //reverse iterator
		return (this->c.rbegin());
	};
	reverse_iterator	rend(void) { //reverse iterator
		return (this->c.rend());
	};
    const_reverse_iterator	rbegin(void) const { //const reverse iterator
		return (this->c.rbegin());
	};
	const_reverse_iterator	rend(void) const { //const reverse iterator
		return (this->c.rend());
	};
};

#endif