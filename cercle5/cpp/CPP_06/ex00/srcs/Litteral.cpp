/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:51:49 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/17 14:59:38 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Litteral.hpp"

Litteral::Litteral(std::string toConvert) {
    std::cout << "Litteral constructor called" << std::endl;
    (void)toConvert;
}

Litteral::~Litteral(void) {
    std::cout << "Litteral destructor called" << std::endl;
}