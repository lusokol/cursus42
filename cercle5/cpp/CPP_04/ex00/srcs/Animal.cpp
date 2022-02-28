/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:07:40 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/24 14:40:08 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type(std::string("wild")) {
	std::cout << "A wild animal has spawn" << std::endl;
}

Animal::Animal(Animal const &ref) {
	std::cout << "A wild animal has been duplicated" << std::endl;
	*this = ref;
}

Animal::~Animal(void) {
	std::cout << "The wild animal has disappear" << std::endl;
}

Animal &Animal::operator=(Animal const &ref) {
	this->type = ref.getType();
	return *this;
}

std::string Animal::getType(void) const {
	return this->type;
}