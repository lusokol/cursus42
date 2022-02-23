/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:02:40 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 17:53:13 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define RED "\e[38;5;196m"
#define GREEN "\e[38;5;118m"
#define ORANGE "\e[38;5;208m"
#define BLUE "\033[34m"
#define STOP "\e[0m"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap("test"/*name + "_clap_name"*/), ScavTrap(), FragTrap(), Name(name) {
	this->ClapTrap::Name = name + "_clap_name";
	this->type = std::string("DiamondTrap");
    this->hp = FragTrap::getDefaultHp();
    this->ep = ScavTrap::getDefaultEp();
    this->ad = FragTrap::getDefaultAd();
	this->type = std::string("DiamondTrap");
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy) {
	this->type = std::string("DiamondTrap");
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void    DiamondTrap::attack(std::string const &ref) {
	this->ScavTrap::attack(ref);
}

void	DiamondTrap::highFivesGuys(void) {
	std::string buf;
	std::cout << GREEN << this->type << " " << this->Name << " ask you for a high fives (y/n) : ";
	while (1) {
		std::cin >> buf;
		if (std::cin.eof() == true)
				exit(EXIT_FAILURE);
		if (buf.size() == 1 && (buf == "y" || buf == "Y")) {
			std::cout << ORANGE << "ヘ( ^o^)ノ＼(^_^ )" << std::endl;
			break ;
		}
		else if (buf.size() == 1 && (buf == "n" || buf == "N")) {
			std::cout << ORANGE << "( ╯﹏╰ )" << std::endl;
			break ;
		}
		else {
			std::cout << "I did not understand your answer" << std::endl << GREEN << this->type << " " << this->Name << " ask you for a high fives (y/n) : ";
		}
	}
	std::cout << STOP;
}