/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:40:30 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/03 17:41:29 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

    template <bool Cond, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };
}