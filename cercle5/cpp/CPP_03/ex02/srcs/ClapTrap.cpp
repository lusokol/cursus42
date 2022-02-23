/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:08:02 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/23 14:06:01 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RED "\e[38;5;196m"
#define GREEN "\e[38;5;118m"
#define ORANGE "\e[38;5;208m"
#define BLUE "\033[34m"
#define STOP "\e[0m"
#define INTMAX 2147483647

ClapTrap::ClapTrap(std::string name) : Name(name), hp(10), ep(10), ad(0), type(std::string("ClapTrap")) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

void ClapTrap::attack(const std::string &target) {
	if (this->hp > 0) {
		if (this->ep > 0 && this->hp > 0) {
			this->ep--;
			std::cout << GREEN << this->type << " " << this->Name << " attacks " << target << ", causing " << this->ad << " points of damage! " << this->ep << " energy point left" << STOP << std::endl;
		}
		else
			std::cout << ORANGE << this->type << " " << this->Name << " can't attack, he doesn't have enough energy point" << STOP << std::endl;	
	}
	else {
		std::cout << RED << this->type << " " << this->Name << " is KO, he can't do anything" << STOP << std::endl;
	}
}

void ClapTrap::beRepaired(int amount) {
	if (this->hp > 0) {
		if (this->ep > 0) {
			this->ep--;
			std::cout << GREEN << this->type << " " << this->Name << " repairs himself " << amount << " hp! " << this->ep << " energy point left" << STOP << std::endl;
			this->hp = (this->hp + amount < this->hp) ? INTMAX : this->hp + amount;
		}
		else
			std::cout << ORANGE << this->type << " " << this->Name << " can't repairs himself, he doesn't have enough energy point" << STOP << std::endl;	
	}
	else {
		std::cout << RED << this->type << " " << this->Name << " is KO, he can't do anything" << STOP << std::endl;
	}
}

void ClapTrap::takeDamage(int amount) {
	std::cout << RED << this->type << " " << this->Name << " take " << amount << " points of damage. He goes from " << this->hp << " to ";
	this->hp = (this->hp - amount < 0) ? 0 : this->hp - amount;
	std::cout << this->hp << " hp" << STOP << std::endl;
}

std::string ClapTrap::getName(void) const {
	return this->Name;
}

int ClapTrap::getHp(void) const {
	return this->hp;
}

unsigned int ClapTrap::getEp(void) const {
	return this->ep;
}

unsigned int ClapTrap::getAd(void) const {
	return this->ad;
}

std::string ClapTrap::getType(void) const {
	return this->type;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &ref) {
	this->Name = ref.getName();
	this->ad = ref.getAd();
	this->ep = ref.getEp();
	this->hp = ref.getHp();
	return *this;
}

std::ostream &operator<<(std::ostream &ostream, ClapTrap const &ref) {
	ostream << BLUE << ref.getType() << " " << ref.getName() << " has " << ref.getHp() << " health points, " << ref.getEp() << " energy point(s) and have " << ref.getAd() << " attack damage" << STOP;
	return ostream;
}