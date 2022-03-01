/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 18:00:14 by lusokol          ###   ########.fr       */
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

Cat::Cat(Cat const &ref) : Animal(ref) {
	std::cout << ORANGE << "A wild Cat has been duplicated" << STOP << std::endl;
	this->brain = new Brain();
	// this->brain = ref.brain;
	*this = ref;
}

Cat::~Cat(void) {
	std::cout << ORANGE << "The wild Cat has disappear" << STOP << std::endl;
	delete this->brain;
}

Cat	&Cat::operator=(Cat const &ref)
{
	std::cout << ORANGE << "Cat assignation operator called." << STOP << std::endl;
	Animal::type = ref.type;
	*this->brain = *ref.brain;
	return (*this);
}

void Cat::addIdea(std::string idea) {this->brain->addIdea(idea);}
void Cat::affIdea(void) const {this->brain->affIdea();}
