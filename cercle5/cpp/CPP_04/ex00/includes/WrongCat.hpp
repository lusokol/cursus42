/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:58:47 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/01 16:52:03 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat(void);
	WrongCat(WrongCat const &ref);
	~WrongCat(void);
	WrongCat &operator=(WrongCat const &ref);
	
};

#endif