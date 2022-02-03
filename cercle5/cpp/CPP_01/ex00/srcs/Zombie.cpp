/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:30:54 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/03 17:56:42 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name) : name(name) {
	std::cout << "\e[38;5;208m" << name << " created" << "\e[0m" << std::endl;
	return ;
}

Zombie::~Zombie (void) {
	std::cout << "\e[38;5;208m" << this->name << " destroyed" <<  "\e[0m" << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << "\e[38;5;118m" << this->name << ": BraiiiiiiinnnzzzZ..." << "\e[0m" << std::endl;
	return ;
}