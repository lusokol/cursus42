/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:34 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/22 12:37:09 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {

public:

	ClapTrap(std::string name = "ClapTrap");
	ClapTrap(ClapTrap const &copy);
	~ClapTrap(void);
	
	ClapTrap &operator=(ClapTrap const &ClapTrap);

	void attack(const std::string &target);
	void takeDamage(int amount);
	void beRepaired(int amount);

	std::string getName(void) const;
	int getHp(void) const;
	unsigned int getEp(void) const;
	unsigned int getAd(void) const;

protected:

	std::string Name;
	int			hp;
	int			ep;
	int			ad;
};

std::ostream &operator<<(std::ostream &ostream, ClapTrap const &ref);

#endif