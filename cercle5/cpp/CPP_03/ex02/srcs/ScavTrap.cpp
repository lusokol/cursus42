/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:02:40 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 14:51:31 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define RED "\e[38;5;196m"
#define GREEN "\e[38;5;118m"
#define ORANGE "\e[38;5;208m"
#define BLUE "\033[34m"
#define STOP "\e[0m"

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
    this->Name = name;
	// this->type = std::string("ScavTrap");
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
	this->type = std::string("ScavTrap");
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
	this->type = std::string("ScavTrap");
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::attack(std::string const &ref) {
	//this->ClapTrap::attack(ref);
    //std::cout << "test target from " << ref << std::endl;
	if (this->hp > 0) {
		if (this->ep > 0 && this->hp > 0) {
			this->ep--;
			std::cout << GREEN << this->type << " " << this->Name << " uses charge, " << ref << " take " << this->ad << " points of damage! " << this->ep << " energy point left" << STOP << std::endl;
		}
		else
			std::cout << ORANGE << this->type << " " << this->Name << " can't attack, he doesn't have enough energy point" << STOP << std::endl;	
	}
	else {
		std::cout << RED << this->type << " " << this->Name << " is KO, he can't do anything" << STOP << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << ORANGE << this->type << " enter in GATE KEEPER mode" << std::endl;
}