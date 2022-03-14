/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:42:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/14 15:53:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form::Form(void) : name("Simple Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
// 	std::cout << "Form constructor called" << std::endl;
// }

Form::Form(std::string name, int toSign, int toExecute) : name(name), isSigned(false), gradeToSign(toSign), gradeToExecute(toExecute) {
	std::cout << BLUE << "Form constructor called" << std::endl << STOP;
}

Form::Form(const Form &ref) {
	*this = ref;
	std::cout << BLUE << "Form copy constructor called" << std::endl << STOP;
}

Form::~Form(void) {
	std::cout << BLUE << "Form destructor called" << std::endl << STOP;
}

Form &Form::operator=(const Form &ref) {
	this->isSigned = ref.getIsSigned();
	this->gradeToSign = ref.getGradeToSign();
	this->gradeToExecute = ref.getGradeToExecute();
	std::cout << BLUE << "Form assignation operator called" << std::endl << STOP;
	return *this;
}

void Form::beSigned(Bureaucrat &ref) {
	if (ref.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->isSigned = true;
}

void	Form::execute(Bureaucrat const &executor) const {
	if (this->isSigned == false)
		throw Form::NotSignedException();
	if (this->gradeToExecute < executor.getGrade())
		throw Form::GradeTooLowException();
}

std::string	Form::getName(void) const { return this->name; }
int	Form::getIsSigned(void) const { return this->isSigned; }
int	Form::getGradeToSign(void) const { return this->gradeToSign; }
int	Form::getGradeToExecute(void) const { return this->gradeToExecute; }

std::ostream &operator<<(std::ostream &ostream, const Form &ref) {
	ostream << "Name : " << ref.getName() << std::endl << "Is signed : "	<< ((ref.getIsSigned()) ? "true" : "false") << std::endl << "Grade needed to sign : " << ref.getGradeToSign() << std::endl << "Grade needed to execute : " << ref.getGradeToExecute();
	return ostream;
}