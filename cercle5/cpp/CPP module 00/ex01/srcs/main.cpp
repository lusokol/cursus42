/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:01:18 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/29 21:26:28 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
    Book phoneBook;
	std::string buff;
	std::cout << "Welcome in the awesome Phone Book !" << std::endl;
	while (1)
	{
		std::cout << "\033[34mADD/SEARCH/EXIT : \033[0m";
		std::getline(std::cin, buff);
		if (buff == "ADD")
			phoneBook.Add();
		if (buff == "SEARCH")
			phoneBook.Search();
		if (buff == "EXIT") {
			std::cout << "\e[38;5;196mPhoneBook is closing and you have lost your contacts forever\e[0m" << std::endl;	
			break;
		}
	}
    return 0;
}