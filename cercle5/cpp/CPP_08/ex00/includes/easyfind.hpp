/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:00:00 by macbookpro        #+#    #+#             */
/*   Updated: 2022/04/04 13:40:53 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &lst, int const &tofind) {
	typename T::iterator it = std::find(lst.begin(), lst.end(), tofind);
	if (it == lst.end())
		throw std::runtime_error("Value not found");
	return it;
}