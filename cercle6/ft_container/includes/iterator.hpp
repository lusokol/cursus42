/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:43:21 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/18 13:42:35 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <cstddef>

class Integers
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
};