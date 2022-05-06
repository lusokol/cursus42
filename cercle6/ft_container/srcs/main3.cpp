/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:55:10 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/06 17:21:19 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.tpp"
#include <iostream>
#include <vector>

#define __VECTOR ft

int main() {
	__VECTOR::vector<int> test(3, 10);
	
	__VECTOR::vector<int>::iterator it = test.begin();
	__VECTOR::vector<int>::iterator ite = test.end();

	
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "ite (" << &*ite << ")" << std::endl;
	for (; it != ite; ++it)
		std::cout << *it << " (" << &*it << ")" << std::endl;
	std::cout << *it << " (" << &*it << ")" << std::endl;
	return (0);
}