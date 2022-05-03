/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:07:52 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/03 13:53:20 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <limits>
#include <type_traits>

namespace ft {
    
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

            
        //┌───────────────────────────────────┐
        //│ CONSTRUCTOR                       │
        //└───────────────────────────────────┘

            explicit vector (const allocator_type& alloc = allocator_type()): _capacity(0), _dataCounter(0), _data(0) { (void)alloc; }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _dataCounter(0) {
                _capacity = n;
                _data = _myAlloc.allocate(n);
                for (; _dataCounter < n: _dataCounter++) {
                    _myAlloc.construct(_data + _dataCounter, val);
                }
            }
            
            template <class InputIterator>
            explicit vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
                int distance = std::distance(first,last); 
                int i = 0;
                this->_capacity = distance;
                _data = _myAlloc.allocate(distance);
                while (first != last) {
                    this->_data[i++] = *first;
                    this->_dataCounter++;
                }
            }

            explicit vector (const vector& x) : _capacity(x._capacity), _dataCounter(x._dataCounter) {
                this->_data = _myAlloc.allocate(this->_capacity);
                for (int i = 0; i < this->_capacity; i++) {
                    this->_data[i] = x._data[i];
                }
            }
            
        //┌───────────────────────────────────┐
        //│ DESTRUCTOR                        │
        //└───────────────────────────────────┘
        
            ~vector() {
                if (this->_capacity > 0) {
                    this->data.deallocate();
                }
            }
    }    
}

#endif