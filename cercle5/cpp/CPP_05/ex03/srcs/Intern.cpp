/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:47:02 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/15 15:04:44 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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

Form Intern::makeForm(std::string formName, std::string formTarget) {
    std::string form_names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	Form *(Intern::*fct[4])(std::string target) {
		&make_ShrubberyCreationForm,
		&make_RobotomyRequestForm,
		&make_PredidentialPardonForm,
		&make_null_form
	};
    int i = 0;
    while (i < 4) {
        
    }
}