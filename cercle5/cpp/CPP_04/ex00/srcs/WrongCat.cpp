/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:21:53 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 15:23:48 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : Animal() {
	Animal::type = "WrongCat";
	Animal::sound = "Miawronnnng 🐈";
	std::cout << "A wild WrongCat has spawn" << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref) {
	std::cout << "A wild WrongCat has been dupliWrongcated" << std::endl;
	*this = ref;
}

WrongCat::~WrongCat(void) {
	std::cout << "The wild WrongCat has disappear" << std::endl;
}