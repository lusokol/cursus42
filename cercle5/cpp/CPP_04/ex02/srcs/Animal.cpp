/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:07:40 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 19:55:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "color.hpp"

Animal::Animal(void) : type(std::string("Unknow animal")) {
	std::cout << BLUE << "A wild animal has spawn" << STOP << std::endl;
}

Animal::Animal(Animal const &ref) {
	std::cout << BLUE << "A wild animal has been copied" << STOP << std::endl;
	*this = ref;
}

Animal::~Animal(void) {
	std::cout << BLUE << "The wild animal has disappear" << STOP << std::endl;
}

Animal &Animal::operator=(Animal const &ref) {
	this->type = ref.getType();
	std::cout << BLUE << "Assignation operator called" << STOP << std::endl;
	return *this;
}

std::string Animal::getType(void) const {
	return this->type;
}

void Animal::makeSound(void) const {
	std::cout << LGREEN << "[" << this->type << "] *strange sound from an unknow animal*" << STOP << std::endl;
}