/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:18 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/10 15:23:56 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), myWeapon(NULL) {
	std::cout << "\e[38;5;208mHumanB created\e[0m" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "\e[38;5;208mHumanB destroyed\e[0m" << std::endl;
}

void HumanB::attack() {
	if (myWeapon)
		std::cout << "\e[38;5;118m" << this->name << " attacks with their " << this->myWeapon->getType() << "\e[0m" << std::endl;
	else
		std::cout << "\e[38;5;196m" << this->name << " can't attack, he have no weapon\e[0m" << std::endl;
}

void HumanB::setWeapon(Weapon &arme) {
	this->myWeapon = &arme;
}