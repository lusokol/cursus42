/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:58:07 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 17:57:38 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "color.hpp"

int main(void) {	
	// Array test
	std::cout << std::endl << LRED << "============== Array test ==============" << STOP << std::endl;
	Animal *horde[10];
	for (int i = 0; i < 10; i++) {
		if (i  % 2 == 0)
			horde[i] = new Dog();
		else
			horde[i] = new Cat();
	}
	std::cout << MAGENTA << "===== Array created =====" << STOP << std::endl << std::endl;
	for (int j = 0; j < 10; j++) {
		delete horde[j];
	}
	std::cout << MAGENTA << "===== Array destroyed =====" << STOP << std::endl << std::endl;
	
	// cat test
	std::cout << LRED << "============== Cat test ==============" << STOP << std::endl;
	
	Cat cat1;
	for (int ideas = 0; ideas < 10; ideas++) {
		switch (ideas % 3){
			case 0:	cat1.addIdea("MEOWWW!"); break;
			case 1:	cat1.addIdea("Meoooooooow"); break;
			case 2:	cat1.addIdea("Miaou"); break;
		}	
	}
	std::cout << MAGENTA << "cat1 ideas : " << YELLOW;
	cat1.affIdea();
	std::cout << std::endl;
	cat1.makeSound();
	Cat cat2(cat1);
	std::cout << MAGENTA << "cat2 ideas : " << YELLOW;
	cat2.affIdea();
	std::cout << STOP << std::endl << std::endl;
	
	// dog test
	std::cout << LRED << "============== Dog test ==============" << STOP << std::endl;
	
	Dog dog1;
	for (int ideas = 0; ideas < 10; ideas++) {
		switch (ideas % 3){
			case 0:	dog1.addIdea("Wooooof"); break;
			case 1:	dog1.addIdea("Wouphe"); break;
			case 2:	dog1.addIdea("ARghff"); break;
		}	
	}
	std::cout << MAGENTA << "dog1 ideas : " << YELLOW;
	dog1.affIdea();
	std::cout << std::endl;
	dog1.makeSound();
	Dog dog2(dog1);
	std::cout << MAGENTA << "dog2 ideas : " << YELLOW;
	dog2.affIdea();
	std::cout << STOP << std::endl << std::endl;
	
	// std::cout << LRED << "============== Leaks ==============" << STOP << std::endl;
	// system ("leaks Brain");
}