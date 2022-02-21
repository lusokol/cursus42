/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:44:54 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/16 14:04:22 by macbookpro       ###   ########.fr       */
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

	float getFloat(void) const;
	int getRawBits(void) const;
	int toInt(void) const;
	void setRawBits(int const raw);
	static Fixed min(Fixed &ref1, Fixed &ref2);
	static Fixed min(Fixed const &ref1, Fixed const &ref2);
	static Fixed max(Fixed &ref1, Fixed &ref2);
	static Fixed max(Fixed const &ref1, Fixed const &ref2);
	
	Fixed &operator=(Fixed const &fixed); // a = b
	Fixed operator++(); //++a
	Fixed operator++(int); //a++
	Fixed operator--(); //--a
	Fixed operator--(int); //a--
	Fixed operator+(Fixed const &ref) const; // a + a
	Fixed operator-(Fixed const &ref) const; // a - a
	Fixed operator*(Fixed const &ref) const; // a * a
	Fixed operator/(Fixed const &ref) const; // a / a
	bool operator==(Fixed const &ref) const; // (a == a)
	bool operator!=(Fixed const &ref) const; // (a != a)
	bool operator>(Fixed const &ref) const;  // (a > a)
	bool operator>=(Fixed const &ref) const; // (a >= a)
	bool operator<(Fixed const &ref) const;  // (a < a)
	bool operator<=(Fixed const &ref) const; // (a <= a)

private:

	int value;
	static const int bit = 8;

};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);

#endif