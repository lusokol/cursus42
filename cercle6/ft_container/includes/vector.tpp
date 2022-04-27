/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:07:52 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/18 13:24:50 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <limits>
#include <type_traits>

namespace std {
    
    template <class T, class Alloc = std::allocator<T> >
    class vector {
        
        public:

            // typedef //
            typedef T                           value_type;
            typedef Alloc                       allocator_type;
            typedef &T                          reference;
            typedef const &T                    const_reference;
            typedef T*                          pointer;
            typedef const T*                    const_pointer;
            
            typedef std::ptrdiff_t				difference_type;
		    typedef size_t						size_type;
		    typedef std::forward_iterator_tag	iterator_category;
            
            protected:

                Alloc _myAlloc;
                size_type _capacity;
                size_type _dataCounter;
                T *_data;

            // iterators

            // constructor

            vector (const allocator_type& alloc = allocator_type()): _capacity(0), _dataCounter(0), _data(0) { (void)alloc; }

            vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _dataCounter(0) {
                _capacity = n;
                _data = _myAlloc.allocate(n);
                for (; _dataCounter < n: _dataCounter++) {
                    _myAlloc.construct(_data + _dataCounter, val);
                }
            }
            
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
     
     
     
     
     
     
     
     
            vector (const vector& x);
    }    
}

#endif