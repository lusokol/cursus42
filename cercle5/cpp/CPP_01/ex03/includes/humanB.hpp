/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:33:41 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/08 17:32:10 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:

	HumanB(std::string name);
	~HumanB();
	
	void attack();
	void setWeapon(Weapon &arme);

private:
	Weapon *myWeapon;
	std::string name;

};

#endif