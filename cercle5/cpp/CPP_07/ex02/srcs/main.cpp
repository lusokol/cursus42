/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:26:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/29 17:17:02 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "color.hpp"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

int main(void) {
	Array<char> empty;
	char str[] = "This string is 34 characters long";
	Array<char> array_char(ARRAY_SIZE(str));
	for (unsigned long i = 0; i < ARRAY_SIZE(str); i++)
		array_char[i] = str[i];
	Array<char> copy_char(array_char);
	std::cout << ORANGE << "Initial char *str   = " << STOP << str << std::endl;
	std::cout << ORANGE << "Array array_char    = " << STOP << array_char << std::endl;
	std::cout << ORANGE << "Copy array_char     = " << STOP << copy_char << std::endl;

	try {
		empty = array_char;
	} catch (std::exception &except) {
		std::cerr << RED << BOLD << "Cannot assign array: " << STOP << LRED << except.what() << std::endl << STOP;
	}
	return 0;
}