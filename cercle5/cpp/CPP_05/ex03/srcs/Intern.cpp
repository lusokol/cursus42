/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:47:02 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/15 16:58:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "color.hpp"
#include <iostream>

Intern::Intern(void) {
    std::cout << "An intern has been hired" << std::endl;
}

Intern::Intern(Intern const &ref) {
    (void)ref;
    std::cout << "A copy of an intern has been hired" << std::endl;
}

Intern::~Intern(void) {
    std::cout << "An intern has been fired" << std::endl;
}

Intern	&Intern::operator=(Intern const &ref) {
	(void)ref;
	return (*this);
}

Form *make_ShrubberyCreationForm(std::string target) {
	std::cout << ORANGE << "Intern create a ShrubberyCreationForm" << std::endl << STOP;
	return (new ShrubberyCreationForm(target));
}

Form *make_RobotomyRequestForm(std::string target) {
	std::cout << ORANGE << "Intern create a RobotomyRequestForm" << std::endl << STOP;
	return (new RobotomyRequestForm(target));
}

Form *make_PresidentialPardonForm(std::string target) {
	std::cout << ORANGE << "Intern create a PresidentialPardonForm" << std::endl << STOP;
	return (new PresidentialPardonForm(target));
}

Form *make_null_form(std::string target) {
	std::cout << ORANGE << "Intern cannot create " << target << ": administration doesn't know it" << std::endl << STOP;
	(void)target;
	return (NULL);
}

Form *Intern::makeForm(std::string formName, std::string formTarget) {
    std::string form_names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	Form *(*fct[4])(std::string target) = {
		&make_ShrubberyCreationForm,
		&make_RobotomyRequestForm,
		&make_PresidentialPardonForm,
		&make_null_form
	};
    int i = 0;
    while (i < 3 && form_names[i] != formName)
		i++;
	//if (form)
	return (fct[i](formTarget));
}