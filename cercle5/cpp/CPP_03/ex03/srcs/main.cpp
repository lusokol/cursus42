/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:57:55 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 18:03:59 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
    ClapTrap jean("Jean");
	std::cout << std::endl;
    ScavTrap albert("Albert");
	std::cout << std::endl;
	FragTrap philipe("Philipe");
	std::cout << std::endl;
	DiamondTrap hugue("Hugue");
        
    std::cout << std::endl << albert << std::endl << jean << std::endl << philipe << std::endl << hugue << std::endl;
	
	std::cout << std::endl;
	jean.attack(std::string("étourmi"));
	albert.attack(std::string("étourmi"));
	philipe.attack(std::string("étourmi"));
	hugue.attack(std::string("étourmi"));

	std::cout << std::endl << albert << std::endl << jean << std::endl << philipe << std::endl << hugue << std::endl;
	
	std::cout << std::endl;
	jean.takeDamage(8);
	albert.takeDamage(8);
	philipe.takeDamage(8);
	hugue.takeDamage(8);

	std::cout << std::endl << albert << std::endl << jean << std::endl << philipe << std::endl << hugue << std::endl;
	
	std::cout << std::endl;
	jean.beRepaired(3);
	albert.beRepaired(3);
	philipe.beRepaired(3);
	hugue.beRepaired(3);

	std::cout << std::endl << albert << std::endl << jean << std::endl << philipe << std::endl << hugue << std::endl;
	
	std::cout << std::endl;
	jean.takeDamage(8);
	albert.takeDamage(8);
	philipe.takeDamage(8);
	hugue.takeDamage(8);

	std::cout << std::endl << albert << std::endl << jean << std::endl << philipe << std::endl << hugue << std::endl;
	
	std::cout << std::endl;
	jean.beRepaired(3);
	albert.beRepaired(3);
	philipe.beRepaired(3);
	hugue.beRepaired(3);

	std::cout << std::endl << albert << std::endl << jean << std::endl << philipe << std::endl << hugue << std::endl << std::endl;

	std::cout << "Étourmi a prit tarif !" << std::endl;

	philipe.highFivesGuys();
	
	std::cout << std::endl;
}