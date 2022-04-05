/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:05:24 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/05 17:37:39 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "Span.hpp"
#include <iostream>
#include <ctime>

int myRand(void) {
    static int seed __attribute__((unused)) = (srand(time(nullptr)), 0);
    int res = rand() % 1000000;
    return res;
}

void test(int size, int inside, int print = 0) {
	Span test = Span(size);
	std::vector<int> v(inside);
	std::generate(v.begin(), v.end(), myRand);
	static int check = 1;
	try {
		std::cout << YELLOW << "Test number " << check << std::endl;
		check++;
		std::cout << LGREEN << "Adding " << inside << " numbers in a span of size " << size << std::endl << STOP;
		test.addNumber(v.begin(), v.end());
		if (print == 0) {
			std::cout << BLUE << "Data inside the new span :" << STOP << std::endl;
			test.affData();
		}
	}
	catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << std::endl << STOP;
	}
	try {
		std::cout << BLUE << "Shortest span : " << LGREEN << test.shortestSpan() << STOP << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << std::endl << STOP;
	}
	try {
		std::cout << BLUE << "Longest span : " << LGREEN << test.longestSpan() << STOP << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << std::endl << STOP;
	}
	std::cout << std::endl;
}

int main(void) {
	{
    	std::cout << BLUE << "Creation of array step by step" << STOP << std::endl;
    	Span sp = Span(5);
    	sp.affData();
    	sp.addNumber(6);
    	sp.affData();
    	sp.addNumber(3);
    	sp.affData();
    	sp.addNumber(17);
    	sp.affData();
    	sp.addNumber(9);
    	sp.affData();
    	sp.addNumber(11);
    	sp.affData();
    	try {sp.addNumber(1);}
    	catch (std::exception &exce) {std::cout << RED << "Cannot add number : " << exce.what() << std::endl << STOP;}
    	sp.affData();
	
	    std::cout << BLUE << "Shortest span : " << LGREEN << sp.shortestSpan() << STOP << std::endl;
	    std::cout << BLUE << "Longest span : " << LGREEN << sp.longestSpan() << STOP << std::endl;
		std::cout << std::endl;
	}
	test(6, 5);
	test(5, 5);
	test(1, 5);
	test(1, 1);
	test(0, 0);
	test(10000000,10000000,1); // change 1 by 0 to print data
	test(10000000,10000,1); //    change 1 by 0 to print data
}