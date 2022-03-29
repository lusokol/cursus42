/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:30:54 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/29 14:10:55 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include "color.hpp"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

int main(void) {
	{
		char str[] = "THIS IS AN EXEMPLE OF CHAR :D";
		char *ptr = str;
		print_array<char>(ptr, ARRAY_SIZE(str));
		iter<char>(ptr, ARRAY_SIZE(str), &add32);
		print_array<char>(ptr, ARRAY_SIZE(str));
	}
	std::cout << std::endl;
	{
		int str[] = {10,20,30,40,50};
		int *ptr = str;
		print_array<int>(ptr, ARRAY_SIZE(str));
		iter<int>(ptr, ARRAY_SIZE(str), &add32);
		print_array<int>(ptr, ARRAY_SIZE(str));
	}
}