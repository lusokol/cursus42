/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:06:59 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/10 15:20:11 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	std::cout << "\e[38;5;208mWeapon created\e[0m" << std::endl;
	return ;
}

Weapon::Weapon(std::string name) : type(name) {
	std::cout << "\e[38;5;208mWeapon created\e[0m" << std::endl;
	return ;
}

Weapon::~Weapon() {
	std::cout << "\e[38;5;208mWeapon destroyed\e[0m" << std::endl;
	return ;
}

std::string &Weapon::getType() {
	return (this->type);
}

void Weapon::setType (std::string str) {
	this->type = str;
}