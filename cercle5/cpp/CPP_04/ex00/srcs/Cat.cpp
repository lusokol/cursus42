/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/24 14:40:33 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	Animal::type = "Cat";
	std::cout << "A wild Cat has spawn" << std::endl;
}

Cat::Cat(Cat const &ref) {
	std::cout << "A wild Cat has been duplicated" << std::endl;
	*this = ref;
}

Cat::~Cat(void) {
	std::cout << "The wild Cat has disappear" << std::endl;
}