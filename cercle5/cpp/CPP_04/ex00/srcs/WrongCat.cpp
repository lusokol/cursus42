/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 17:49:16 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "color.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	WrongAnimal::type = "WrongCat";
	WrongAnimal::sound = "Fake Moewwwwww 🐈";
	std::cout << ORANGE << "A wild WrongCat has spawn" << STOP << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref) {
	std::cout << ORANGE << "A wild WrongCat has been dupliWrongcated" << STOP << std::endl;
	*this = ref;
}

WrongCat::~WrongCat(void) {
	std::cout << ORANGE << "The wild WrongCat has disappear" << STOP << std::endl;
}