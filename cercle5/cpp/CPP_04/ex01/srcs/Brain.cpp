/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:24:49 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/01 16:32:48 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "color.hpp"

Brain::Brain(void) {
    std::cout << BLUE << "Brain constructor called" << STOP << std::endl;
}

Brain::Brain(Brain const &ref) {
    std::cout << BLUE << "Brain copy constructor called" << STOP << std::endl;
   *this = ref;
}

Brain::~Brain(void) {
    std::cout << BLUE << "Brain destructor called" << STOP << std::endl;
}

Brain	&Brain::operator=(Brain const &ref)
{
	std::cout << BLUE << "Brain assignation operator called." << STOP << std::endl;
	for (int i = 0; ref.ideas[i].empty() != true; i++)
		this->ideas[i] = ref.ideas[i];
	return (*this);
}

void    Brain::affIdea(void) {
    for (int i = 0; this->ideas[i].empty() != true; i++) {
        if (this->ideas[i + 1].empty() != true)
            std::cout << this->ideas[i] << ", ";
        else
            std::cout << this->ideas[i];
    }
}

void    Brain::addIdea(std::string idea) {
    int i = 0;
    while (this->ideas[i].empty() != true)
        i++;
    if (i < 100)
        this->ideas[i] = idea;
}