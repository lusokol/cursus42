/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 18:37:55 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "color.hpp"

Cat::Cat(void) : Animal() {
	Animal::type = "Cat";
	Animal::sound = "Miaouuuuuuu 🐈";
	this->brain = new Brain();
	std::cout << ORANGE << "A wild Cat has spawn" << STOP << std::endl;
}

Cat::Cat(Cat const &ref) {
	std::cout << ORANGE << "A wild Cat has been duplicated" << STOP << std::endl;
	*this = ref;
}

Cat::~Cat(void) {
	std::cout << ORANGE << "The wild Cat has disappear" << STOP << std::endl;
	delete this->brain;
}