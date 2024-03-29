/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:42:24 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/15 15:47:00 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {

public:

    Intern(void);
    Intern(Intern const &ref);
    ~Intern(void);
    Intern &operator=(Intern const &ref);
    Form *makeForm(std::string formName, std::string formTarget);

};

#endif