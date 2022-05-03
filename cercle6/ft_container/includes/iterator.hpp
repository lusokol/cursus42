/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:43:21 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/02 18:32:10 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
#include <type_traits>
#include <iostream>

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
            friend bool operator==(const Iterator &a, const Iterator &b) { return a._ptr == b._ptr; };
            friend bool operator!=(const Iterator &a, const Iterator &b) { return a._ptr != b._ptr; };
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
                return Iterator(this->_ptr + n);
            }
            Iterator operator-(difference_type n) const {
                return Iterator(this->_ptr - n);
            }
            difference_type operator+(Iterator &ref)  {
                return (this->_ptr + ref._ptr);
            }
            difference_type operator-(Iterator &ref)  {
                return (this->_ptr - ref._ptr);
            }
			Iterator operator+=(difference_type n) {
				this->_ptr += n;
                return *this;
            }
			Iterator operator-=(difference_type n) {
				this->_ptr -= n;
                return *this;
            }

			bool operator<(Iterator &ref) {
				return (this->_ptr < ref._ptr);
			}
			bool operator>(Iterator &ref) {
				return (this->_ptr > ref._ptr);
			}
			bool operator<=(Iterator &ref) {
				return (this->_ptr <= ref._ptr);
			}
			bool operator>=(Iterator &ref) {
				return (this->_ptr >= ref._ptr);
			}
			reference operator[](difference_type n) const {
				return *(this->_ptr + n);
			}
    };

	template <typename T>
    class ReverseIterator {
        
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
            ReverseIterator(void): _ptr(0) {}
            ReverseIterator(pointer ptr): _ptr(ptr) {}
            template <typename U>
                ReverseIterator(ReverseIterator<U> & ref) : _ptr(ref._ptr) {}
            ~ReverseIterator(void) {}

            //============================ operator =============================//
            friend bool operator==(const ReverseIterator &a, const ReverseIterator &b) { return a._ptr == b._ptr; };
            friend bool operator!=(const ReverseIterator &a, const ReverseIterator &b) { return a._ptr != b._ptr; };
            reference operator*() const { return *_ptr; }
            pointer operator->() { return _ptr; }
            ReverseIterator &operator=(ReverseIterator<T> const &ref) {
                this->_ptr = ref._ptr;
                return (*this);
            }
            ReverseIterator &operator=(pointer ptr) {
                this->_ptr = ptr;
                return (*this);
            }
            ReverseIterator &operator++() {
                (this->_ptr)--;
                return *this;
            }
            ReverseIterator operator++(int) {
                ReverseIterator tmp = *this;
                --(this->_ptr);
                return tmp;
            }
            ReverseIterator &operator--() {
                (this->_ptr)++;
                return *this;
            }
            ReverseIterator operator--(int) {
                ReverseIterator tmp = *this;
                ++(this->_ptr);
                return tmp;
            }

            
            ReverseIterator operator+(difference_type n) const {
                return ReverseIterator(this->_ptr - n);
            }
            ReverseIterator operator-(difference_type n) const {
                return ReverseIterator(this->_ptr + n);
            }
            difference_type operator+(ReverseIterator &ref)  {
                return (this->_ptr - ref._ptr);
            }
            difference_type operator-(ReverseIterator &ref)  {
                return (this->_ptr + ref._ptr);
            }
			ReverseIterator operator+=(difference_type n) {
				this->_ptr -= n;
                return *this;
            }
			ReverseIterator operator-=(difference_type n) {
				this->_ptr += n;
                return *this;
            }

			bool operator<(ReverseIterator &ref) {
				return (this->_ptr > ref._ptr);
			}
			bool operator>(ReverseIterator &ref) {
				return (this->_ptr < ref._ptr);
			}
			bool operator<=(ReverseIterator &ref) {
				return (this->_ptr >= ref._ptr);
			}
			bool operator>=(ReverseIterator &ref) {
				return (this->_ptr <= ref._ptr);
			}
			reference operator[](difference_type n) const {
				return *(this->_ptr - n);
			}
    };
}

#endif

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
        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end() { return Iterator(&m_data[200]); }

private:
    int m_data[200];
};*/