/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:58:01 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/14 15:54:36 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form {
    
public:
    
    ShrubberyCreationForm(std::string target = "default");
	ShrubberyCreationForm(ShrubberyCreationForm const &form);
	virtual ~ShrubberyCreationForm(void);
    
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	
    void do_execute(void) const;

private:

	std::string const target;

};

#endif