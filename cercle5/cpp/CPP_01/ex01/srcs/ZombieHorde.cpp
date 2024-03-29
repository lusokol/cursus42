/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:39:03 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/10 14:56:45 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie *horde;
	if (N > 0)
		horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setZombie(name);
	}
	return (horde);
}