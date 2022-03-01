/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:58:47 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 19:49:20 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {

public:

	Cat(void);
	Cat(Cat const &ref);
	~Cat(void);
	Cat &operator=(Cat const &ref);
	void makeSound(void) const;
};

#endif