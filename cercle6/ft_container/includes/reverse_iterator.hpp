/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:43:21 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/02 15:48:00 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <iterator>
#include <type_traits>
namespace ft {

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
                _ptr--;
                return *this;
            }
            ReverseIterator operator++(int) {
                Iterator tmp = *this;
                --(*this);
                return tmp;
            }
            ReverseIterator &operator--() {
                this->_ptr++;
                return *this;
            }
            ReverseIterator operator--(int) {
                Iterator tmp = *this;
                ++(*this);
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