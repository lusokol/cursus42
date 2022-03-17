/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:08:47 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/15 16:54:57 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat zap1("Zap1", 1);
	Bureaucrat bob20("Bob20", 20);
	Bureaucrat dan70("Dan70", 70);
	Bureaucrat ted100("Ted100", 100);
	Bureaucrat tod150("Tod150", 150);
	Intern	   bibop;
	std::cout << std::endl;
	{
		Form *scf = bibop.makeForm("shrubbery creation", "Planet2000Express");
		tod150.executeForm(*scf);
		ted100.executeForm(*scf);
		tod150.signForm(*scf);
		ted100.signForm(*scf);
		tod150.executeForm(*scf);
		ted100.executeForm(*scf);
		delete scf;
	}
		std::cout << std::endl;
	{
		Form *rrf = bibop.makeForm("robotomy request", "Fry");
		ted100.executeForm(*rrf);
		dan70.executeForm(*rrf);
		ted100.signForm(*rrf);
		dan70.signForm(*rrf);
		dan70.executeForm(*rrf);
		bob20.executeForm(*rrf);
		bob20.executeForm(*rrf);
		bob20.executeForm(*rrf);
		bob20.executeForm(*rrf);
		bob20.executeForm(*rrf);
		delete rrf;
	}
		std::cout << std::endl;
	{
		Form *ppf = bibop.makeForm("presidential pardon", "Bender");
		bob20.executeForm(*ppf);
		zap1.executeForm(*ppf);
		dan70.signForm(*ppf);
		bob20.signForm(*ppf);
		bob20.executeForm(*ppf);
		zap1.executeForm(*ppf);
		delete ppf;
	}
	Form *test = bibop.makeForm("IT WILL NOT WORK", "TROLLLL");
	(void)test;
	std::cout << std::endl;
	return (0);
}