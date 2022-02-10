/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:32:41 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/10 15:13:44 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void) {
	Karen grosse;
	std::cout << std::endl;
	grosse.complain("DEBUG");
	grosse.complain("INFO");
	grosse.complain("WARNING");
	grosse.complain("ERROR");
	std::cout << std::endl;
}