/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:58:12 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 17:26:12 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    
public:
    ScavTrap(std::string name = "5C4V-7R4P");
    ScavTrap(ScavTrap const &ref);
    ~ScavTrap(void);
    
    void    attack(std::string const &ref);
	void	guardGate(void);
	int 	getDefaultHp() const;
	int 	getDefaultEp() const;
	int 	getDefaultAd() const;

protected:
	static const int defaultHp = 100;
	static const int defaultEp = 50;
	static const int defaultAd = 20;
};

#endif