/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:47:46 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/15 14:36:19 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int nb) {
	std::cout << "Int constructor called" << std::endl;
	value = nb;
	value = value << this->bit;
	// std::cout << value << std::endl;
	// value = value << this->bit;
	// std::cout << value << std::endl;
}

Fixed::Fixed(float nb) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(nb * (1 << this->bit));
}

Fixed::Fixed(Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(Fixed const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::getFloat(void) const {
	return (((float)this->value / (float)(1 << this->bit)));
}

int	Fixed::toInt(void) const {
	return (this->value >> this->bit);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed) {
	ostream << fixed.getFloat();
	return ostream;
}
