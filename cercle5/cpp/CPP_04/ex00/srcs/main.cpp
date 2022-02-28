/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:58:07 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 14:35:46 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	Cat cat1;
	Dog dog1;
	Cat cat2;
	Dog dog2;

	std::cout << std::endl;
	std::cout << "cat type : " << cat1.getType() << std::endl;
	std::cout << "dog type : " << dog1.getType() << std::endl;
	cat2 = cat1;
	dog2 = dog1;
	std::cout << "cat type : " << cat2.getType() << std::endl;
	std::cout << "dog type : " << dog2.getType() << std::endl;
	cat1.makeSound();
	cat2.makeSound();
	dog1.makeSound();
	dog2.makeSound();
	std::cout << std::endl;
}