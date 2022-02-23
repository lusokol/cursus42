/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:02:40 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 15:22:56 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define RED "\e[38;5;196m"
#define GREEN "\e[38;5;118m"
#define ORANGE "\e[38;5;208m"
#define BLUE "\033[34m"
#define STOP "\e[0m"

FragTrap::FragTrap(std::string name) : ClapTrap() {
    this->Name = name;
	// this->type = std::string("FragTrap");
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
	this->type = std::string("FragTrap");
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	this->type = std::string("FragTrap");
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

void    FragTrap::attack(std::string const &ref) {
	//this->ClapTrap::attack(ref);
    //std::cout << "test target from " << ref << std::endl;
	if (this->hp > 0) {
		if (this->ep > 0 && this->hp > 0) {
			this->ep--;
			std::cout << GREEN << this->type << " " << this->Name << " uses thunder, " << ref << " take " << this->ad << " points of damage! " << this->ep << " energy point left" << STOP << std::endl;
		}
		else
			std::cout << ORANGE << this->type << " " << this->Name << " can't attack, he doesn't have enough energy point" << STOP << std::endl;	
	}
	else {
		std::cout << RED << this->type << " " << this->Name << " is KO, he can't do anything" << STOP << std::endl;
	}
}

void	FragTrap::highFivesGuys(void) {
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