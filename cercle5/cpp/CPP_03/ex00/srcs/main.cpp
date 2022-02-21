/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:57:55 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/21 17:16:52 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
{
    ClapTrap albert(std::string("Albert"));
        
    std::cout << std::endl << albert << std::endl;
    
    albert.attack(std::string("a zombie"));
    albert.takeDamage(3);
    
    std::cout << albert << std::endl;
    
    albert.attack(std::string("a zombie"));
    albert.takeDamage(2);

    std::cout << albert << std::endl;

    albert.beRepaired(1);

    std::cout << albert << std::endl;

    albert.attack(std::string("a zombie"));
    albert.takeDamage(6);

    std::cout << albert << std::endl;
    
    albert.attack(std::string("a zombie"));
    albert.takeDamage(2);
    
    std::cout << albert << std::endl << std::endl;
}
//  std::cout << std::endl << std::endl << std::endl;
// {
//     ClapTrap albert(std::string("Albert"));
        
//     for (int i = 0; i < 12; i++)
//         albert.attack(std::string("someone"));
// }
}