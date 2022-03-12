/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:42:39 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/10 16:10:44 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form::Form(void) : name("Simple Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
// 	std::cout << "Form constructor called" << std::endl;
// }

Form::Form(std::string name, int toSign, int toExecute) : name(name), isSigned(false), gradeToSign(toSign), gradeToExecute(toExecute) {
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &ref) {
	*this = ref;
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &ref) {
	this->name = ref.getName();
	this->isSigned = ref.getIsSigned();
	this->gradeToSign = ref.getGradeToSign();
	this->gradeToExecute = ref.getGradeToExecute();
	std::cout << "Form assignation operator called" << std::endl;
	return *this;
}

void Form::beSigned(Bureaucrat &ref) {
	if (ref.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->isSigned = true;
}

std::string	Form::getName(void) const { return this->name; }
int	Form::getIsSigned(void) const { return this->isSigned; }
int	Form::getGradeToSign(void) const { return this->gradeToSign; }
int	Form::getGradeToExecute(void) const { return this->gradeToExecute; }

std::ostream &operator<<(std::ostream &ostream, const Form &ref) {
	ostream << "Name : " << ref.getName() << std::endl << "Is signed : "	<< ((ref.getIsSigned()) ? "true" : "false") << std::endl << "Grade needed to sign : " << ref.getGradeToSign() << std::endl << "Grade needed to execute : " << ref.getGradeToExecute();
	return ostream;
}