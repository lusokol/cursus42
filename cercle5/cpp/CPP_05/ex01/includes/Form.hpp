/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:40:03 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/10 16:09:15 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	//Form(void);
	Form(std::string name = "simple form", int toSign = 150, int toExecute = 150);
	Form(const Form &ref);
	~Form(void);
	Form &operator=(const Form &ref);

	std::string	getName(void) const;
	int	getIsSigned(void) const;
	int	getGradeToSign(void) const;
	int	getGradeToExecute(void) const;
	void beSigned(Bureaucrat &ref);

	class GradeTooLowException : public std::exception {
        
        public:
            virtual const char* what() const throw() {
                return ("Grade is too low");
            }        
    };

private:

	std::string name;
	bool isSigned;
	int	gradeToSign;
	int gradeToExecute;

};

std::ostream &operator<<(std::ostream &ostream, const Form &ref);

#endif