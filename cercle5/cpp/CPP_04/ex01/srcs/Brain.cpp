/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:24:49 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/28 18:32:25 by lusokol          ###   ########.fr       */
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
	std::cout << "Brain assignation operator called." << std::endl;
	for (int i = 0; ref.ideas[i].empty() != true; i++)
		this->ideas[i] = ref.ideas[i];
	return (*this);
}