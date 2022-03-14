/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:08:47 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/14 17:30:36 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat zap1("Zap1", 1);
	Bureaucrat bob20("Bob20", 20);
	Bureaucrat dan70("Dan70", 70);
	Bureaucrat ted100("Ted100", 100);
	Bureaucrat tod150("Tod150", 150);
	std::cout << std::endl;
	{
		ShrubberyCreationForm scf("Planet2000Express");
		tod150.executeForm(scf);
		ted100.executeForm(scf);
		tod150.signForm(scf);
		ted100.signForm(scf);
		tod150.executeForm(scf);
		ted100.executeForm(scf);
	}
		std::cout << std::endl;
	{
		RobotomyRequestForm rrf("Fry");
		ted100.executeForm(rrf);
		dan70.executeForm(rrf);
		ted100.signForm(rrf);
		dan70.signForm(rrf);
		dan70.executeForm(rrf);
		bob20.executeForm(rrf);
		bob20.executeForm(rrf);
		bob20.executeForm(rrf);
		bob20.executeForm(rrf);
		bob20.executeForm(rrf);
	}
		std::cout << std::endl;
	{
		PresidentialPardonForm ppf("Bender");
		bob20.executeForm(ppf);
		zap1.executeForm(ppf);
		dan70.signForm(ppf);
		bob20.signForm(ppf);
		bob20.executeForm(ppf);
		zap1.executeForm(ppf);
	}
	std::cout << std::endl;
	return (0);
}