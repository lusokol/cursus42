/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:10:15 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/25 14:40:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

    template <typedef T1, typedef T2>
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair(void) : first(first_type()), second(second_type()) {}
        
        template <class First, class Second>
        pair (const pair<First,Second> & p) : first(p.first), second(p.second) {}
        
        pair (const first_type & a, const second_type & b) : first(a), second(b) {}

        pair &operator=(pair const &ref) {
            if (this != &ref) {
                this->first = ref.first;
                this->second = ref.second;
            }
            return (*this);
        }
    }

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };
        
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs == rhs)); };

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); };

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs < lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }

    // * /////////////////////// MAKE PAIR ////////////////////// * //

    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y) {
        return (pair<T, U>(first, second));
    }


}

#endif