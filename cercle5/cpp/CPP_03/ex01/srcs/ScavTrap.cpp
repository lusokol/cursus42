/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:02:40 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/21 18:53:54 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
    this->Name = name;
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
    std::cout << this->Name << " is a ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
    std::cout << this->Name << " is a ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "The ScavTrap " << this->Name << " has been destroyed" << std::endl;
}

void    ScavTrap::attack(std::string const &ref) {
    std::cout << "test target from " << ref << std::endl;
}