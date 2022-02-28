/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/24 14:40:23 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	Animal::type = "Dog";
	std::cout << "A wild Dog has spawn" << std::endl;
}

Dog::Dog(Dog const &ref) {
	std::cout << "A wild Dog has been duplicated" << std::endl;
	*this = ref;
}

Dog::~Dog(void) {
	std::cout << "The wild Dog has disappear" << std::endl;
}