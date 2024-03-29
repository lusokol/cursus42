/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:58:12 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/23 17:26:06 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    
public:
    FragTrap(std::string name = "Fr49-7r4p");
    FragTrap(FragTrap const &ref);
    ~FragTrap(void);
    
    void    attack(std::string const &ref);
	void	highFivesGuys(void);
	int 	getDefaultHp() const;
	int 	getDefaultEp() const;
	int 	getDefaultAd() const;
	
protected:
	static const int defaultHp = 100;
	static const int defaultEp = 100;
	static const int defaultAd = 30;
};

#endif