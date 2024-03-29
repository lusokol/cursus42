/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:57:55 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 14:06:54 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ClapTrap jean("Jean");
    ScavTrap albert("Albert");
        
    std::cout << std::endl << albert << std::endl;
	std::cout << jean << std::endl;
	
	std::cout << std::endl;
	jean.attack(std::string("zombie"));
	albert.attack(std::string("zombie"));

	std::cout << std::endl;
	std::cout << albert << std::endl;
	std::cout << jean << std::endl;
	
	std::cout << std::endl;
	jean.takeDamage(8);
	albert.takeDamage(8);

	std::cout << std::endl;
	std::cout << albert << std::endl;
	std::cout << jean << std::endl;
	
	std::cout << std::endl;
	jean.beRepaired(3);
	albert.beRepaired(3);

	std::cout << std::endl;
	std::cout << albert << std::endl;
	std::cout << jean << std::endl;
	
	std::cout << std::endl;
	jean.takeDamage(8);
	albert.takeDamage(8);

	std::cout << std::endl;
	std::cout << albert << std::endl;
	std::cout << jean << std::endl;

	std::cout << std::endl;
	jean.beRepaired(3);
	albert.beRepaired(3);

	std::cout << std::endl;
	std::cout << albert << std::endl;
	std::cout << jean << std::endl << std::endl;
}