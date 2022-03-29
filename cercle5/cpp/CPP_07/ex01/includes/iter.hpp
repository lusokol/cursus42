/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:18:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/29 14:11:30 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

template<typename ADDR>
void iter(ADDR *addr, size_t size, void (*fct)(ADDR &)) {
	size_t i = 0;
	while (i < size) {
		fct(addr[i]);
		i++;
	}
}

template<typename ADDR>
void iter(ADDR const *addr, size_t size, void (*fct)(ADDR const &)) {
	size_t i = 0;
	while (i < size) {
		fct(addr[i]);
		i++;
	}
}

template <typename T>
void add32(T &i) {
	i += 32;
}

template <typename T>
void	print_array(T const *array, size_t size) {
	size_t i;
	for (i = 0; i < size - 1; i++)
		std::cout << array[i] << " ";
	std::cout << array[i] << std::endl;
}
template <>
void	print_array(char const *array, size_t size) {
	size_t i;
	for (i = 0; i < size; i++)
		std::cout << array[i];
	std::cout << std::endl;
}