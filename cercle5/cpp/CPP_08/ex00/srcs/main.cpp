/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:15:04 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/31 15:21:14 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#define ARRAY_SIZE(x) sizeof(x) / sizeof(*x)

int main(void) {


	int array[] = { -44, -86, -62, -1, -17, -58, -37, -55, 5, -22, -25, -49,
		-61, 80, -72, -71, 13, -6, 8, 42, 66, 90, -93, -53, 44, -76, -50, 31,
		41, 45, -84, 78, 50, 63, 18, -56, 33, -73, -18, -13, -92, -51, 92, 91,
		89, 87, 48, -43, 70, -99, -23, -57, 11, -65, -7, -78, -90, -21, -63,
		-54, 22, -4, 27, -42, 95, 94, -31, 72, 37, 85, -83, 47, 99, 84, 28, -68,
		36, 58, -10, 30, -5, 20, -30, 59, 26, 3, 73, -77, 32, -52, -45, 12, -59,
		77, 83, 10, -34, 57, -82, -35, -40, 86, 2, -48, -100, -38, 25, -47, -36,
		-11, -70, -20, -14, -74, 9, 14, 0, 96, 74, 100, -28, -39, -96, 17, -66,
		-89, 34, 21, 39, 60, 55, 68, 4, -32, 16, -33, 62, -95, -80, 51, 19, -69,
		-67, 61, 53, 40, -91, -81, -87, -15, -8, 76, -12, -98, 7, -79, 82, -26,
		81, 75, 15, 1, 97, 49, -29, 88, 38, -60, 54, 23, 43, 24, 35, -85, -64,
		-3, 93, 6, 64, -2, 71, -19, -27, 67, -75, -9, -16, 56, 52, 46, -97, 79,
		-24, 69, 65, -41, -88, 98, -94, 29, -46 };

	std::vector<int> vec(array, array + ARRAY_SIZE(array));
	//try {
		int val = -1;
		std::vector<int>::const_iterator result_vec = easyfind(vec, val);
		std::cout << val << " found in vector at index " << result_vec - vec.begin() << std::endl;
	//} catch (std::exception &except) {
		// std::cerr << except.what() << std::endl;
		// return (EXIT_FAILURE);
	// }
	
	//std::list<int>	lst;

	// lst.push_back(3);
	// lst.push_back(8);
	// lst.push_back(7);
	// lst.push_back(2);
	// lst.push_back(5);
	// lst.push_back(9);
	
	// std::vector<int>::iterator result = easyfind(lst, 1);
	// easyfind(lst, 1);
	// std::cout << "searching 1 : " << result - lst.begin() << std::endl;

	// std::cout << "searching 2 : " << easyfind(lst, 2) - lst.begin() << std::endl;
	// std::cout << "searching 3 : " << easyfind(lst, 3) - lst.begin() << std::endl;
	// std::cout << "searching 4 : " << easyfind(lst, 4) - lst.begin() << std::endl;
	// std::cout << "searching 5 : " << easyfind(lst, 5) - lst.begin() << std::endl;
	// std::cout << "searching 6 : " << easyfind(lst, 6) - lst.begin() << std::endl;
	// std::cout << "searching 7 : " << easyfind(lst, 7) - lst.begin() << std::endl;
	// std::cout << "searching 8 : " << easyfind(lst, 8) - lst.begin() << std::endl;
	// std::cout << "searching 9 : " << easyfind(lst, 9) - lst.begin() << std::endl;
}