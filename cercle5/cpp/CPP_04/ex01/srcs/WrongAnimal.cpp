/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:07:40 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/02 15:43:32 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "color.hpp"

WrongAnimal::WrongAnimal(void) : type(std::string("wild")) {
	std::cout << BLUE << "A wild WrongAnimal has spawn" << STOP << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref) {
	std::cout << BLUE << "A wild WrongAnimal has been duplicated" << STOP << std::endl;
	*this = ref;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << BLUE << "The wild WrongAnimal has disappear" << STOP << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &ref) {
	this->type = ref.getType();
	std::cout << BLUE << "Assignation operator called" << STOP << std::endl;
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << LGREEN << "[" << this->type << "] *strange sound from an unknow WrongAnimal*" << STOP << std::endl;
}