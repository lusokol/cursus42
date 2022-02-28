/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:58:07 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/28 19:24:35 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "color.hpp"

int main(void) {	
	Animal *horde[10];
	for (int i = 0; i < 10; i++) {
		if (i  % 2 == 0)
			horde[i] = new Dog();
		else
			horde[i] = new Cat();
	}
	
	// Animal something;
	// Cat *cat = new Cat();
	// Dog *dog = new Dog();
	// WrongCat wCat;

	// std::cout << YELLOW << std::endl;
	// std::cout << "cat type : " << cat->getType() << std::endl;
	// std::cout << "dog type : " << dog->getType() << std::endl;
	// std::cout << "WrongCat type : " << wCat.getType() << std::endl;
	// std::cout << "animal type : " << something.getType() << std::endl << std::endl << STOP;
	
	// cat->makeSound();
	// dog->makeSound();
	// wCat.makeSound();
	// something.makeSound();
	// std::cout << std::endl;
	// delete cat;
	// delete dog;
	
	for (int j = 0; j < 10; j++) {
		//horde[j] = NULL;
		delete horde[j];
	}
	//delete[] horde;
	system ("leaks Brain");
}