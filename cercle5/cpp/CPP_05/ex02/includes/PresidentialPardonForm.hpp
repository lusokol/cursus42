/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:58:01 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/14 15:54:36 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
    
public:
    
    PresidentialPardonForm(std::string target = "default");
	PresidentialPardonForm(PresidentialPardonForm const &form);
	virtual ~PresidentialPardonForm(void);
    
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	
    void do_execute(void) const;

private:

	std::string const target;

};

#endif