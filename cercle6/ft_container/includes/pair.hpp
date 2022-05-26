/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:10:15 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/26 18:17:48 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>

namespace ft {

    template <typename T1, typename T2>
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair(void) : first(first_type()), second(second_type()) {}
        
        template <class First, class Second>
        pair (pair<First,Second> const &p) : first(p.first), second(p.second) {}
        
        pair (first_type const &a, second_type const &b) : first(a), second(b) {}

        /* pair    &operator=(pair const &ref) {
            if (this != &ref) {
                this->first = ref.first;
                this->second = ref.second;
            }
            return (*this);
        } */

        operator pair<T1 const, T2 const>(void) const {
			return (pair<T1 const, T2 const>(this->first, this->second));
		}
    };

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

    // * /////////////////////// DEBUG ////////////////////// * //

	template <typename T, typename U>
	std::ostream	&operator<<(std::ostream &ostream, pair<T, U> const &rhs) {
		ostream << "key(" << rhs.first << "):" << rhs.second;
		return (ostream);
	}    

    // * /////////////////////// MAKE PAIR ////////////////////// * //

    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 first, T2 second) {
        return (pair<T1, T2>(first, second));
    }


}

#endif