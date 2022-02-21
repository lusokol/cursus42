/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:58:12 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/21 18:54:59 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    
public:
    ScavTrap(std::string name = "5C4V-7R4P");
    ScavTrap(ScavTrap const &ref);
    ~ScavTrap(void);
    
    void    attack(std::string const &ref);
};

#endif