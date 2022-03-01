/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 16:55:13 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "color.hpp"

Cat::Cat(void) : Animal() {
	Animal::type = "Cat";
	Animal::sound = "Miaouuuuuuu 🐈";
	std::cout << ORANGE << "A wild Cat has spawn" << STOP << std::endl;
}

Cat::Cat(Cat const &ref) {
	std::cout << ORANGE << "A wild Cat has been duplicated" << STOP << std::endl;
	*this = ref;
}

Cat::~Cat(void) {
	std::cout << ORANGE << "The wild Cat has disappear" << STOP << std::endl;
}

Cat &Cat::operator=(Cat const &ref) {
	this->type = ref.type;
	std::cout << ORANGE << "Wild cat assignation operator called" << STOP << std::endl;
	return *this;
}