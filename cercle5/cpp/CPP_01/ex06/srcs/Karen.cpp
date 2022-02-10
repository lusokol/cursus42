/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:36:52 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/10 15:18:44 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

enum e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

Karen::Karen(void) {}

Karen::~Karen(void) {}

void Karen::complain(std::string level) {
	std::string lvl[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int i;
	for (i = 0; i < 4; i++)
		if (lvl[i] == level) 
			break ;
	switch (i)
	{
		case DEBUG: 
			this->debug();
			std::cout << std::endl;
		case INFO: 
			this->info();
			std::cout << std::endl;
		case WARNING: 
			this->warning();
			std::cout << std::endl;
		case ERROR: 
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "\e[93m[ Probably complaining about insignificant problems ]\e[0m" << std::endl;		
			break;
	}
}

void Karen::debug(void) {
	std::cout << "\033[34m[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\033[0m" << std::endl;
}

void Karen::info(void) {
	std::cout << "\e[38;5;118m[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\e[0m" << std::endl;
}

void Karen::warning(void) {
	std::cout << "\e[38;5;208m[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\e[0m" << std::endl;
}

void Karen::error(void) {
	std::cout << "\e[38;5;196m[ ERROR ]" << std::endl;
	std::cout <<  "This is unacceptable ! I want to speak to the manager now.\e[0m" << std::endl;
}