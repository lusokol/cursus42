/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:25:19 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/10 15:28:45 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	Zombie *horde;
	int	nb = 0;

	std::cout << "\e[38;5;220mHow much zombie do you want in the horde ?\e[0m" << std::endl;
	while (nb <= 0) {
		std::cin >> nb;
		if (nb <= 0)
			std::cout << "\e[38;5;208mNeed at least ONE zombie in the horde\e[0m" << std::endl << "\e[38;5;220mHow much zombie do you want in the horde ?\e[0m" << std::endl;	
	}
	horde = zombieHorde(nb, "Hugue");
	for (int i = 0; i < nb; i++) {
		horde[i].announce();	
	}
	delete[] horde;
//	system ("leaks Horde");
	return 0;
}