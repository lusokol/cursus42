/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 14:34:43 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	Animal::type = "Dog";
	Animal::sound = "Wooof 🐶";
	std::cout << "A wild Dog has spawn" << std::endl;
}

Dog::Dog(Dog const &ref) {
	std::cout << "A wild Dog has been duplicated" << std::endl;
	*this = ref;
}

Dog::~Dog(void) {
	std::cout << "The wild Dog has disappear" << std::endl;
}