/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:58:47 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 20:02:46 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {

public:

	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &ref);
	virtual ~WrongAnimal(void);
	WrongAnimal &operator=(WrongAnimal const &ref);

	std::string getType(void) const;
	virtual void makeSound(void) const;

protected:

	std::string type;

};

#endif