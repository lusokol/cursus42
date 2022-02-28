/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:07:40 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 15:15:38 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type(std::string("wild")) {
	std::cout << "A wild WrongAnimal has spawn" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref) {
	std::cout << "A wild WrongAnimal has been duplicated" << std::endl;
	*this = ref;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "The wild WrongAnimal has disappear" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &ref) {
	this->type = ref.getType();
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "[" << this->type << "] " << this->sound << std::endl;
}