/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:59:31 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/31 15:53:32 by lusokol          ###   ########.fr       */
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
		std::cout << "\e[38;5;196mLimit of maximum contact reached\e[0m" << std::endl;
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
	std::getline(std::cin, tmp);
	int index = tmp[0] - '0';
	if (tmp.size() > 1 | index < 0 || index >= this->nb_contact) {
		std::cout << "\e[38;5;208mWrong index, go back to the menu\e[0m" << std::endl;
	}
	else
	 	this->list[index].Aff_itself();
}