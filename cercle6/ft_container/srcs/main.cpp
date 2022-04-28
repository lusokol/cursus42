/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:02:23 by macbookpro        #+#    #+#             */
/*   Updated: 2022/04/28 16:47:49 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "color.hpp"
#include <vector>
#include <iostream>

//namespace ft;

void test_it(ft::Iterator<int> it, ft::Iterator<int> ite) {
	ft::Iterator<int> actual(it);
	std::cout << BLUE << "START" << STOP << std::endl;
	while (actual != ite)
	{
		std::cout << "iterator : " << *actual << std::endl;
		actual++;
	}
	std::cout << BLUE << "MIDDLE" << STOP << std::endl;
	actual--;
	while (actual != it - 1)
	{
		std::cout << "iterator : " << *actual << std::endl;
		actual--;
	}
	std::cout << BLUE << "END" << STOP << std::endl;
}

int main() {
	int test[5];
	for (int i = 0; i < 5; i++) {test[i] = i;}
	ft::Iterator<int> it1;
	it1 = &test[0];	
	ft::Iterator<int> ite1;
	ite1 = &test[5];
	ft::Iterator<int> it2(&test[0]);	
	ft::Iterator<int> ite2(&test[5]);
	ft::Iterator<int> it3 = &test[0];	
	ft::Iterator<int> ite3 = &test[5];
	test_it(it1, ite1);
	std::cout << ORANGE << "==============================" << std::endl << STOP;
	test_it(it2, ite2);
	std::cout << ORANGE << "==============================" << std::endl << STOP;
	test_it(it3, ite3);
	
}