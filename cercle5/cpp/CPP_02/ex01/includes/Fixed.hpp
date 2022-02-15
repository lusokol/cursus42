/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:44:54 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/15 14:26:21 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:

	Fixed(void);
	Fixed(int nb);
	Fixed(float nb);
	Fixed(Fixed &copy);
	Fixed(Fixed const &copy);
	~Fixed(void);
	Fixed &operator=(Fixed const &fixed);

	float getFloat(void) const;
	int getRawBits(void) const;
	int toInt(void) const;
	void setRawBits(int const raw);

private:

	int value;
	static const int bit = 8;

};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);

#endif