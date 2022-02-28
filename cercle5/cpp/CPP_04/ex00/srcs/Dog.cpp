/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 17:43:11 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "color.hpp"

Dog::Dog(void) : Animal() {
	Animal::type = "Dog";
	Animal::sound = "Wooof 🐶";
	std::cout << ORANGE << "A wild Dog has spawn" << STOP << std::endl;
}

Dog::Dog(Dog const &ref) {
	std::cout << ORANGE << "A wild Dog has been duplicated" << STOP << std::endl;
	*this = ref;
}

Dog::~Dog(void) {
	std::cout << ORANGE << "The wild Dog has disappear" << STOP << std::endl;
}