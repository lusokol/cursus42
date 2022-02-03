/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:34:47 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/01 18:45:15 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

Contact::Contact(void) {
	//std::cout << "Constructeur" << std::endl;
	this->info[0] = std::string("First name");
	this->info[1] = std::string("Last name");
	this->info[2] = std::string("Nickname");
	this->info[3] = std::string("Phone number");
	this->info[4] = std::string("Darkest secret");
	return ;
}

Contact::~Contact(void) {
	//std::cout << "Destructeur" << std::endl;
	return ;
}

int	check_arg(std::string tmp, int i) {
	if (i == 0 || i == 1 || i == 3) {
		for (int j = 0; tmp[j]; j++) {
			if (i != 3 && isalpha(tmp[j]) == 0)
				return (1);
			else if (i == 3 && isdigit(tmp[j]) == 0)
				return (1);
		}
	}
	return (0);
}

void	Contact::Add_contact(void) {
	std::string tmp;
	for (int i = 0; i < 5; i++) {
		tmp.clear();
		while (tmp.size() == 0 || check_arg(tmp, i)) {
			std::cout << this->info[i] << " : ";
			std::getline(std::cin, tmp);
			if (tmp.size() == 0)
				std::cout << "\e[38;5;208mYou have to fill each informations\e[0m" << std::endl;
			else if (check_arg(tmp, i)) {
				if (i == 0 || i == 1)
					std::cout << "\e[38;5;208mThis information take only characters\e[0m" << std::endl;
				if (i == 3)
					std::cout << "\e[38;5;208mThis information take only numbers\e[0m" << std::endl;
			}
			else
				this->info[i] = tmp;
		}
	}
}

void	Contact::Aff_itself_less(int index) {
	std::cout.width(10);
	std::cout << index << "|";
	for (int i = 0; i < 3; i++) {
		int j = 0;
		if (this->info[i].length() > 10) {
			for (j = 0; j < 9; j++) {
				putchar(this->info[i][j]);
			}
			putchar('.');
		}
		else {
			std::cout.width(10);
			std::cout << this->info[i];
		}
		if (i < 2)
			putchar('|');
	}
	std::cout << std::endl;
}

void	Contact::Aff_itself(void) {
	Contact tmp;
	for (int i = 0; i < 5; i++) {
		std::cout << "\e[0;49;33m" << tmp.info[i] << ":\e[0m " << this->info[i] << std::endl;
	}
}