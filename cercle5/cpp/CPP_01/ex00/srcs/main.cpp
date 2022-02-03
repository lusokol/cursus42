/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:25:19 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/03 18:01:13 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	Zombie *z1, *z2,*z3;

	std::cout << "\e[38;5;196mHeap allocation :\e[0m" << std::endl;
	z1 = newZombie("Rick");
	z1->announce();

	z2 = newZombie("Carl");
	z2->announce();

	z3 = newZombie("Daryl");
	z3->announce();

	std::cout << std::endl << "\e[38;5;196mStack allocation :\e[0m" << std::endl;

	randomChump("Michonne");
	randomChump("Carol");
	randomChump("Maggie");

	std::cout << std::endl << "\e[38;5;196mHeap free :\e[0m" << std::endl;
	
	delete z1;
	delete z2;
	delete z3;
	return 0;
}