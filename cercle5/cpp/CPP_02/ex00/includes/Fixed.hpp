/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:44:54 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/14 14:05:46 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed &copy);
	~Fixed(void);
	Fixed &operator=(Fixed const &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	int value;
	static const int bit = 8;

};

#endif