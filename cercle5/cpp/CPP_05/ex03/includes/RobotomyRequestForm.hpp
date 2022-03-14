/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:58:01 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/14 17:22:09 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {
    
public:
    
    RobotomyRequestForm(std::string target = "default");
	RobotomyRequestForm(RobotomyRequestForm const &form);
	virtual ~RobotomyRequestForm(void);
    
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	
    void do_execute(void) const;

private:

	std::string const target;

};

#endif