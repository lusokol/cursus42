/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:46:58 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/05 16:09:32 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
    
template <typename T>
struct is_integral {    static const bool value = false; };
    
template <> struct is_integral<bool>                    { static const bool value = true; };
template <> struct is_integral<char>                    { static const bool value = true; };
template <> struct is_integral<wchar_t>                 { static const bool value = true; };
template <> struct is_integral<signed char>             { static const bool value = true; };
template <> struct is_integral<short int>               { static const bool value = true; };
template <> struct is_integral<int>                     { static const bool value = true; };
template <> struct is_integral<long int>                { static const bool value = true; };
template <> struct is_integral<long long int>           { static const bool value = true; };
template <> struct is_integral<unsigned char>           { static const bool value = true; };
template <> struct is_integral<unsigned short int>      { static const bool value = true; };
template <> struct is_integral<unsigned int>            { static const bool value = true; };
template <> struct is_integral<unsigned long int>       { static const bool value = true; };
template <> struct is_integral<unsigned long long int>  { static const bool value = true; };
    
}