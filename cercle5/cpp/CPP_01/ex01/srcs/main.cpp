/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:25:19 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/07 16:20:50 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	Zombie *horde;
	int	nb;

	std::cout << "\e[38;5;220mHow much zombie do you want in the horde ?\e[0m" << std::endl;
	std::cin >> nb;
	horde = zombieHorde(nb, "Hugue");
	for (int i = 0; i < nb; i++) {
		horde[i].announce();	
	}
	delete[] horde;
//	system ("leaks BraiiiiiiinnnzzzZ");
	return 0;
}