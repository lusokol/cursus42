/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:03:31 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/14 17:47:44 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "color.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << BLUE << "ShrubberyCreationForm created for target " << this->target << std::endl << STOP;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form) : Form("ShrubberyCreationForm", 145, 137), target(form.target) {
    std::cout << BLUE << "ShrubberyCreationForm copy created for target " << this->target << std::endl << STOP;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << BLUE << "ShrubberyCreationForm destroyed" << std::endl << STOP;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref) {
    if (this != &ref)
        *this = ref;
    return *this;
}

void ShrubberyCreationForm::do_execute(void) const {
    std::string fileName = this->target + "_shrubbery";
    std::ofstream file(fileName);
    if (file.fail() == true)
        std::cerr << RED << "Error : Cannot create file" << STOP << std::endl;
    else {
        std::cout << LGREEN << "Planting tree in " << fileName << std::endl << STOP;
        file << LGREEN;
        file << "             # #### ####" << std::endl;
        file << "           ### \\/#|### |/####" << std::endl;
        file << "          ##\\/#/ \\||/##/_/##/_#" << std::endl;
        file << "        ###  \\/###|/ \\/ # ###" << std::endl;
        file << "      ##_\\_#\\_\\## | #/###_/_####" << std::endl;
        file << "     ## #### # \\ #| /  #### ##/##" << std::endl;
        file << "      __#_--###`  |{,###---###-~" << std::endl;
        file << ORANGE << "                \\ }{" << std::endl;
        file << "                 }}{" << std::endl;
        file << "                 }}{" << std::endl;
        file << "                 {{}" << std::endl;
        file << "           , -=-~{ .-^- _" << std::endl << STOP;
        file.close();
    }
}