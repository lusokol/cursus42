/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:02:36 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/10 15:55:19 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void check_grade(int grade) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(void) : name(std::string("Jean")), grade(150) {
    check_grade(this->grade);
    std::cout << BLUE << "Bureaucrat constructor called" << STOP << std::endl;
}

Bureaucrat::Bureaucrat(std::string bname, int bgrade) : name(bname), grade(bgrade) {
    check_grade(this->grade);
    std::cout << BLUE << "Bureaucrat constructor called" << STOP << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) {
    std::cout << BLUE << "Bureaucrat copy constructor called" << STOP << std::endl;
    *this = ref;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << BLUE << "Bureaucrat destructor called" << STOP << std::endl;
}

void Bureaucrat::gradeUp(void) {
    check_grade(this->grade - 1);
    if (this->grade > 1)
        this->grade--;
}

void Bureaucrat::gradeDown(void) {
    check_grade(this->grade + 1);
    if (this->grade < 150)
        this->grade++;
}

std::string Bureaucrat::getName(void) const {return this->name;}
int Bureaucrat::getGrade(void) const {return this->grade;}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ref) {
    this->grade = ref.getGrade();
    return *this;
}

void Bureaucrat::signForm(Form &ref) {
	try {
		ref.beSigned(*this);
	}
	catch (std::exception const &except) {
		std::cout << this->getName() << " couldn't sign " << ref.getName() << " because " << except.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << ref.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat const &ref)
{
	ostream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (ostream);
}