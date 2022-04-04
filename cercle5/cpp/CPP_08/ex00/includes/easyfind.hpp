/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:00:00 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/31 15:07:40 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &lst, int const &tofind) {
	typename T::iterator it = std::find(lst.begin(), lst.end(), tofind);
	//std::cout << "return : " << it << std::endl;
	return it;
}