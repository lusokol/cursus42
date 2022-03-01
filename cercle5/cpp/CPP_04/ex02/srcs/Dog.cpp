/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 19:31:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "color.hpp"

Dog::Dog(void) : Animal() {
	Animal::type = "Dog";
	Animal::sound = "Wooof 🐶";
	this->brain = new Brain();
	std::cout << ORANGE << "A wild Dog has spawn" << STOP << std::endl;
}

Dog::Dog(Dog const &ref) {
	std::cout << ORANGE << "A wild Dog has been duplicated" << STOP << std::endl;
	this->brain = new Brain();
	*this = ref;
}

Dog::~Dog(void) {
	std::cout << ORANGE << "The wild Dog has disappear" << STOP << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(Dog const &ref)
{
	std::cout << ORANGE << "Dog assignation operator called." << STOP << std::endl;
	Animal::type = ref.type;
	*this->brain = *ref.brain;
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << LGREEN << "[" << this->type << "] " << this->sound << STOP << std::endl;
}

void Dog::addIdea(std::string idea) {this->brain->addIdea(idea);}
void Dog::affIdea(void) const {this->brain->affIdea();}