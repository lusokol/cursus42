/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:46:45 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/10 16:08:29 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "color.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat {

public:

    Bureaucrat(void);
    Bureaucrat(std::string bname = "Jean", int bgrade = 150);
    Bureaucrat(Bureaucrat const &ref);
    ~Bureaucrat(void);
    std::string getName(void) const;
    int getGrade(void) const;
    void gradeUp(void);
    void gradeDown(void);
	void signForm(Form &ref);
    Bureaucrat &operator=(Bureaucrat const &ref);
    
    class GradeTooHighException : public std::exception {
        
        public:
            virtual const char* what() const throw() {
                return ("Grade is too high");
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
    int grade;

        
};

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat const &ref);

#endif