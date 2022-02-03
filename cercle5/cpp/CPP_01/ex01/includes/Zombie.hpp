/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:26:24 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/03 19:10:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	
	public : 
	
	Zombie (std::string name);
	~Zombie (void);

	void announce (void);
	
	private :
	
	std::string name;
	
	void setZombie(std::string name);
};

#endif