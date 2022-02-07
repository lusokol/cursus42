/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:30:54 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/07 16:17:04 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name) : name(name) {
	std::cout << "\e[38;5;208m" << name << " created" << "\e[0m" << std::endl;
	return ;
}

Zombie::Zombie () {
	std::cout << "\e[38;5;208mA zombie has joined the horde" << "\e[0m" << std::endl;
};

Zombie::~Zombie (void) {
	std::cout << "\e[38;5;208m" << this->name << " leaved the horde" <<  "\e[0m" << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << "\e[38;5;118m" << this->name << ": BraiiiiiiinnnzzzZ..." << "\e[0m" << std::endl;
	return ;
}

void	Zombie::setZombie(std::string zname) {
	this->name = zname;
}