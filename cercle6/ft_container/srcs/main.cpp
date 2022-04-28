/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:02:23 by macbookpro        #+#    #+#             */
/*   Updated: 2022/04/28 15:02:06 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include <vector>
#include <iostream>

//namespace ft;

void test_it(ft::Iterator<int> it, ft::Iterator<int> ite) {
	while (it != ite)
	{
		std::cout << "iterator : " << *it1 << std::endl;
		it1++;
	}
}

int main() {
	int test[5];
	for (int i = 0; i < 5; i++) {test[i] = i;}
	ft::Iterator<int> it1;
	it1 = &test[0];	
	ft::Iterator<int> ite1;
	ite1 = &test[5];
	while (it1 != ite1)
	{
		std::cout << "iterator : " << *it1 << std::endl;
		it1++;
	}
	std::cout << std::endl;
	
	ft::Iterator<int> it2(&test[0]);	
	ft::Iterator<int> ite2(&test[5]);
	while (it2 != ite2)
	{
		std::cout << "iterator : " << *it2 << std::endl;
		it2++;
	}
	std::cout << std::endl;

	ft::Iterator<int> it3 = &test[0];	
	ft::Iterator<int> ite3 = &test[5];
	while (it3 != ite3)
	{
		std::cout << "iterator : " << *it3 << std::endl;
		it3++;
	}
}