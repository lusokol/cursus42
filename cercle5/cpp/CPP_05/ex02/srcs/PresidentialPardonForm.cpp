/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:03:31 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/14 17:26:53 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "color.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << BLUE << "PresidentialPardonForm created for target " << this->target << std::endl << STOP;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &form) : Form("PresidentialPardonForm", 25, 5), target(form.target) {
    std::cout << BLUE << "PresidentialPardonForm copy created for target " << this->target << std::endl << STOP;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << BLUE << "PresidentialPardonForm destroyed" << std::endl << STOP;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ref) {
    if (this != &ref)
        *this = ref;
    return *this;
}

void PresidentialPardonForm::do_execute(void) const {
    std::cout << YELLOW << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl << STOP;
}