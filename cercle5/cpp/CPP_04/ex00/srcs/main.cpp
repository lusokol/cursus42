/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:58:07 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/02 14:38:55 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "color.hpp"

int main(void) {	
	Animal something;
	WrongAnimal *wAnimal = new WrongCat();
	Cat cat;
	Dog dog;
	WrongCat wCat;

	std::cout << YELLOW << std::endl;
	std::cout << "cat type : " << cat.getType() << std::endl;
	std::cout << "dog type : " << dog.getType() << std::endl;
	std::cout << "WrongCat type : " << wCat.getType() << std::endl;
	std::cout << "animal type : " << something.getType() << std::endl << std::endl << STOP;
	
	cat.makeSound();
	dog.makeSound();
	std::cout << "WrongCat on a WrongCat variable : " << std::endl;
	wCat.makeSound();
	std::cout << "WrongCat on a WrongAnimal variable : " << std::endl;
	wAnimal->makeSound();
	something.makeSound();
	std::cout << std::endl;
}