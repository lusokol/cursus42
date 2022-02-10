/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:18 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/08 17:35:14 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"

HumanA::HumanA(std::string name, Weapon &arme) : name(name), myWeapon(arme) {
	std::cout << "\e[38;5;208mHumanA created\e[0m" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "\e[38;5;208mHumanA destroyed\e[0m" << std::endl;
}

void HumanA::attack() {
	std::cout << "\e[38;5;118m" << this->name << " attacks with their " << this->myWeapon.getType() << "\e[0m" << std::endl;
}