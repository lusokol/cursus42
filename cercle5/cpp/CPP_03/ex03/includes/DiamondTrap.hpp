/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:58:12 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 19:54:17 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    
public:
    DiamondTrap(std::string name = "D14M0ND-7R4P");
    DiamondTrap(DiamondTrap const &ref);
    ~DiamondTrap(void);
    
    void    attack(std::string const &ref);
	void	highFivesGuys(void);
	void	whoAmI(void) const;

private:
	std::string Name;
};

#endif