/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:02:23 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/02 18:58:10 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "color.hpp"
#include <vector>
#include "iterator.hpp"
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define ORANGE "\e[38;5;208m"
#define STOP "\033[0m"

template <typename T>
void test_it(ft::Iterator<T> it, ft::Iterator<T> ite) {
	ft::Iterator<T> actual(it);
	std::cout << BLUE << "START " << "IT value : " << *it << " ITE value :" << *ite << STOP << std::endl;
	std::cout << YELLOW << "[IT value] ([IT address]) | [ITE value] ([ITE address])" << STOP << std::endl;
	while (actual != ite)
	{
		std::cout << *actual << " (" << &(*actual) << ") | " << *ite << " (" << &(*ite) << ")" << std::endl;
		actual++;
	}
	std::cout << ORANGE << "It shouldn't be display but as you can see, it's the same value AND address :" << STOP << std::endl << "iterator : " << *actual << " (" << &(*actual) << ") | " << *ite << " (" << &(*ite) << ")" << std::endl;
	std::cout << BLUE << "IN THE OTHER DIRECTION :" << STOP << std::endl;
	actual--;
	while (actual != it - 1)
	{
		std::cout << *actual << " (" << &(*actual) << ") | " << *(it - 1) << " (" << &(*(it - 1)) << ")" << std::endl;
		actual--;
	}
	std::cout << ORANGE << "It shouldn't be display but as you can see, it's the same value AND address :" << STOP << std::endl << "iterator : " << *actual << " (" << &(*actual) << ") | " << *ite << " (" << &(*ite) << ")" << std::endl;
	std::cout << BLUE << "END" << STOP << std::endl;
}

template <typename T>
void test_it(ft::ReverseIterator<T> it, ft::ReverseIterator<T> ite) {
	ft::ReverseIterator<T> actual(it);
	std::cout << BLUE << "START " << "IT value : " << *it << " ITE value :" << *ite << STOP << std::endl;
	std::cout << YELLOW << "[IT value] ([IT address]) | [ITE value] ([ITE address])" << STOP << std::endl;
	while (actual != ite)
	{
		std::cout << *actual << " (" << &(*actual) << ") | " << *ite << " (" << &(*ite) << ")" << std::endl;
		actual++;
	}
	std::cout << ORANGE << "It shouldn't be display but as you can see, it's the same value AND address :" << STOP << std::endl << "iterator : " << *actual << " (" << &(*actual) << ") | " << *ite << " (" << &(*ite) << ")" << std::endl;
	std::cout << BLUE << "IN THE OTHER DIRECTION :" << STOP << std::endl;
	actual--;
	while (actual != it - 1)
	{
		std::cout << *actual << " (" << &(*actual) << ") | " << *(it - 1) << " (" << &(*(it - 1)) << ")" << std::endl;
		actual--;
	}
	std::cout << ORANGE << "It shouldn't be display but as you can see, it's the same value AND address :" << STOP << std::endl << "iterator : " << *actual << " (" << &(*actual) << ") | " << *ite << " (" << &(*ite) << ")" << std::endl;
	std::cout << BLUE << "END" << STOP << std::endl;
}

int main() {
	int test[7] = {-1, 10, 20, 30, 40, 50, -2};
	std::cout << "Creating Array of 5 elements (10, 20, 30, 40, 50) with '-1' before and '-2' after" << std::endl;
	{
		ft::Iterator<int> it = &test[1];	
		ft::Iterator<int> ite = &test[6];
		std::cout << "it < ite = " << (it < ite) << std::endl;
		std::cout << "it > ite = " << (it > ite) << std::endl;
		std::cout << "it <= ite = " << (it <= ite) << std::endl;
		std::cout << "it >= ite = " << (it >= ite) << std::endl;
		std::cout << "it == ite = " << (it == ite) << std::endl;
		std::cout << "it != ite = " << (it != ite) << std::endl;
		std::cout << "it[1] = " << it[1] << "should be 20" << std::endl << std::endl;
		test_it(it, ite);
		it = &test[1];
		for (int i = 0; i < 5; i++) {
			std::cout << *it << " ";
			it++;
		}
		it--;
		std::cout << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << *it << " ";
			it--;
		}
		std::cout << std::endl;
	}
	std::cout << ORANGE << std::endl << "==============================" << std::endl << std::endl << STOP;
	{
		ft::ReverseIterator<int> it = &test[5];	
		ft::ReverseIterator<int> ite = &test[0];
		std::cout << "it < ite = " << (it < ite) << std::endl;
		std::cout << "it > ite = " << (it > ite) << std::endl;
		std::cout << "it <= ite = " << (it <= ite) << std::endl;
		std::cout << "it >= ite = " << (it >= ite) << std::endl;
		std::cout << "it == ite = " << (it == ite) << std::endl;
		std::cout << "it != ite = " << (it != ite) << std::endl;
		std::cout << "it[1] = " << it[1] << "should be 40" << std::endl << std::endl;
		test_it(it, ite);
		it = &test[5];
		for (int i = 0; i < 5; i++) {
			std::cout << *it << " ";
			it++;
		}
		it--;
		std::cout << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << *it << " ";
			it--;
		}
		std::cout << std::endl;
	}
}