/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:03:31 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/14 17:11:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "color.hpp"
#include <iostream>
#include <fstream>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << BLUE << "RobotomyRequestForm created for target " << this->target << std::endl << STOP;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form) : Form("RobotomyRequestForm", 72, 45), target(form.target) {
    std::cout << BLUE << "RobotomyRequestForm copy created for target " << this->target << std::endl << STOP;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << BLUE << "RobotomyRequestForm destroyed" << std::endl << STOP;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) {
    if (this != &ref)
        *this = ref;
    return *this;
}

void RobotomyRequestForm::do_execute(void) const {
    struct timeval time;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
    std::cout << YELLOW << "* drilling noises * ... ";
	if (rand() % 2 == 0)
		std::cout << this->target << " get robotomized" << std::endl << STOP;
	else
		std::cout << "Nnlucky, the robotomization of " << this->target << " is a failure" << std::endl << STOP;
}