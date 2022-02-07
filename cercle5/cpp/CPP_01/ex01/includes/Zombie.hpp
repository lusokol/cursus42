/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:26:24 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/07 15:57:07 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	
	public : 
	
	Zombie ();
	Zombie (std::string name);
	~Zombie (void);

	void announce (void);
	void setZombie (std::string zname);
	
	private :
	
	std::string name;
};

#endif