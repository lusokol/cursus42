/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:43:21 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/28 14:59:06 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
#include <type_traits>
//#include "reverse_iterator.hpp"
namespace ft {

    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

    template <typename Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <typename Traits>
    struct iterator_traits<Traits *> {
        typedef ptrdiff_t difference_type;
        typedef Traits value_type;
        typedef Traits * pointer;
        typedef Traits & reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename Traits>
    struct iterator_traits<Traits * const> {
        typedef ptrdiff_t difference_type;
        typedef Traits value_type;
        typedef const Traits* pointer;
        typedef const Traits& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename T>
    class Iterator {
        
        private:
            T *_ptr;
            typedef iterator_traits<T *> _traits;
            
        public:
            typedef typename _traits::difference_type   difference_type;
            typedef typename _traits::value_type        value_type;
            typedef typename _traits::pointer           pointer;
            typedef typename _traits::reference         reference;
            typedef typename _traits::iterator_category iterator_category;

            //================= constructor / copy / destructor =================//
            Iterator(void): _ptr(0) {}
            Iterator(pointer ptr): _ptr(ptr) {}
            template <typename U>
                Iterator(Iterator<U> & ref) : _ptr(ref._ptr) {}
            ~Iterator(void) {}

            //============================ operator =============================//
            bool operator==(const Iterator &a, const Iterator &b) { return a._ptr == b._ptr; };
            bool operator!=(const Iterator &a, const Iterator &b) { return a._ptr != b._ptr; };
            reference operator*() const { return *_ptr; }
            pointer operator->() { return _ptr; }
            Iterator &operator=(Iterator<T> const &ref) {
                this->_ptr = ref._ptr;
                return (*this);
            }
            Iterator &operator=(pointer ptr) {
                this->_ptr = ptr;
                return (*this);
            }
            Iterator &operator++() {
                _ptr++;
                return *this;
            }
            Iterator operator++(int) {
                Iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            Iterator &operator--() {
                this->_ptr--;
                return *this;
            }
            Iterator operator--(int) {
                Iterator tmp = *this;
                --(*this);
                return tmp;
            }
            Iterator operator+(difference_type n) const {
                return (this)
            }
    };
    #endif
}
/*class Integers
{
public:
    struct Iterator
    {
        typedef std::forward_iterator_tag   iterator_category;
        typedef std::ptrdiff_t              difference_type;
        typedef int                         value_type;
        typedef int*                        pointer;
        typedef int&                        reference;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator &operator++()
        {
            m_ptr++;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        /* friend */ bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };
        /* friend */ bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end() { return Iterator(&m_data[200]); }

private:
    int m_data[200];
};*/