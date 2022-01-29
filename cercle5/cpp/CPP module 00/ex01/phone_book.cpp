/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:59:31 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/29 21:36:37 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

Book::Book( void ) {
	this->nb_contact = 0;
    return;
}

Book::~Book( void ) {
    return;
}

void	Book::Add(void) {
	if (this->nb_contact >= 8) {
		std::cout << "Limit of maximum contact reached" << std::endl;
		return ;
	}
	this->list[this->nb_contact].Add_contact();
	this->nb_contact++;
}

void	Book::Search(void) {
	int i = 0;
	std::string tmp;
	std::cout << "\e[0;49;33mINDEX     |FIRST NAME|LAST NAME |NICKNAME" << std::endl;
	while (i < this->nb_contact) {
		this->list[i].Aff_itself_less(i);
		i++;
	}
	std::cout << "\033[34mChoose an index for more informations : \033[0m";
	int index;
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index >= this->nb_contact) {
		std::cout << "\e[38;5;208mWrong index, go back to the menu\e[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else {
		this->list[index].Aff_itself();
	}
}