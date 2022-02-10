/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:32:41 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/10 14:42:32 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int ac, char **av) {
	Karen grosse;
	if (ac != 2) {
		std::cout << "\e[38;5;196mInvalid format :" << std::endl << "./karenFilter [ level ]\e[0m" << std::endl;
		return (1);
	}
	grosse.complain(av[1]);
}