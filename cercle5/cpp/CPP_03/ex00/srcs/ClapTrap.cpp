/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:08:02 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/17 12:59:54 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), hp(10), ep(10), ad(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy) {
	*this = copy;
}

ClapTrap::attack(const std::string &target) {
	if (this->ep > 0) {
		this->ep -= 1
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->Name << " can't attack, he doesn't have enough energy points"
	}
	
}

std::ostream &operator<<(std::ostream &ref, ClapTrap const &ref) {
	ostream << 0;
	return ostream;
}