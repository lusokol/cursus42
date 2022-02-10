/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:36:52 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/09 19:15:32 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void) {
	std::cout << "\e[93mA wild Karen has spawned\e[0m" << std::endl;
}

Karen::~Karen(void) {
	std::cout << "\e[93mKaren ran away\e[0m" << std::endl;
}

void Karen::complain(std::string level) {
	void (Karen::*fct[4])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	std::string lvl[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++) {
		if (lvl[i] == level) {
			(this->*fct[i])();
			return ;
		}
	}
	std::cout << "I don't understand" << std::endl;
}

void Karen::debug(void) {
	std::cout << "\033[34mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\033[0m" << std::endl;
}

void Karen::info(void) {
	std::cout << "\e[38;5;118mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\e[0m" << std::endl;
}

void Karen::warning(void) {
	std::cout << "\e[38;5;208mI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\e[0m" << std::endl;
}

void Karen::error(void) {
	std::cout <<  "\e[38;5;196mThis is unacceptable ! I want to speak to the manager now.\e[0m" << std::endl;
}