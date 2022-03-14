/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:40:03 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/14 17:35:47 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	Form(std::string name = "simple form", int toSign = 150, int toExecute = 150);
	Form(const Form &ref);
	virtual ~Form(void);
	Form &operator=(const Form &ref);

	std::string	getName(void) const;
	int	getIsSigned(void) const;
	int	getGradeToSign(void) const;
	int	getGradeToExecute(void) const;
	void beSigned(Bureaucrat &ref);
	virtual void do_execute(void) const = 0;
	void execute(Bureaucrat const &executor) const;

	class NotSignedException : public std::exception {
        
        public:
            virtual const char* what() const throw() {
                return ("Form isn't signed");
            }        
    };
	class GradeTooLowException : public std::exception {
        
        public:
            virtual const char* what() const throw() {
                return ("Grade is too low");
            }        
    };

private:

	std::string const name;
	bool isSigned;
	int	gradeToSign;
	int gradeToExecute;

};

std::ostream &operator<<(std::ostream &ostream, const Form &ref);

#endif