/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:34 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/17 12:53:40 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {

public:

	ClapTrap(std::string name);
	ClapTrap(ClapTrap &copy);
	~ClapTrap(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:

	std::string Name;
	int			hp;
	int			ep;
	int			ad;
};

std::ostream &operator<<(std::ostream &ref, ClapTrap const &ref);

#endif