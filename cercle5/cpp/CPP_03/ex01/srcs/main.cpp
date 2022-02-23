/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:57:55 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/22 12:31:10 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
// {
    ClapTrap jean("Jean");
    ScavTrap albert("Albert");
        
    std::cout << std::endl << albert << std::endl;
	std::cout << std::endl << jean << std::endl;
	
	albert.attack(std::string("a zombie"));
	jean.attack(std::string("a zombie"));

	std::cout << std::endl << albert << std::endl;
	std::cout << std::endl << jean << std::endl;
    // albert.attack(std::string("a zombie"));
    // albert.takeDamage(3);
    
    // std::cout << albert << std::endl;
    
    // albert.attack(std::string("a zombie"));
    // albert.takeDamage(2);

    // std::cout << albert << std::endl;

    // albert.beRepaired(1);

    // std::cout << albert << std::endl;

    // albert.attack(std::string("a zombie"));
    // albert.takeDamage(6);

    // std::cout << albert << std::endl;
    
    // albert.attack(std::string("a zombie"));
    // albert.takeDamage(2);
    
    // std::cout << albert << std::endl << std::endl;
// }
//  std::cout << std::endl << std::endl << std::endl;
// {
//     ClapTrap albert(std::string("Albert"));
        
//     for (int i = 0; i < 12; i++)
//         albert.attack(std::string("someone"));
// }
}