/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:32:20 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/26 14:41:06 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <iterator>
#include <type_traits>
#include "iterator.hpp"

/* template <typename Riterator>
struct iterator_traits {
	typedef typename Riterator::difference_type difference_type;
	typedef typename Riterator::value_type value_type;
	typedef typename Riterator::pointer pointer;
	typedef typename Riterator::reference reference;
	typedef typename Riterator::iterator_category iterator_category;
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
 */
template <typename T>
class Riterator {
	public:
		typedef T*                        pointer;
        typedef T&                        reference;

		Riterator(void): _ptr(0) {}
		Riterator(pointer ptr): _ptr(ptr) {}
		template <typename U>
			Riterator(Riterator<U> & ref) : _ptr(ref._ptr) {}
		~Riterator(void) {}
		Riterator &operator=(Riterator<T> const &ref) { this->_ptr = ref._ptr; return (*this); }
		Riterator &operator=(pointer ptr) { this->_ptr = ptr; return (*this); }
		friend bool operator==(const Riterator &a, const Riterator &b) { return a._ptr == b._ptr; };
        friend bool operator!=(const Riterator &a, const Riterator &b) { return a._ptr != b._ptr; };
		reference operator*() const { return *_ptr; }
        pointer operator->() { return _ptr; }
		Riterator &operator++()
        {
            _ptr--;
            return *this;
        }
        Riterator operator++(int)
        {
            Riterator tmp = *this;
            --(*this);
            return tmp;
        }
		Riterator &operator--()
        {
            _ptr++;
            return *this;
        }
        Riterator operator--(int)
        {
            Riterator tmp = *this;
            ++(*this);
            return tmp;
        }
	private:
		T *_ptr;
		typedef Iterator::iterator_traits<T> _traits;
};

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