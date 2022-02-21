/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:47:46 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/16 14:02:01 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
	// DISPLAY std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int nb) {
	// DISPLAY std::cout << "Int constructor called" << std::endl;
	value = nb;
	value = value << this->bit;
}

Fixed::Fixed(float nb) {
	// DISPLAY std::cout << "Float constructor called" << std::endl;
	this->value = roundf(nb * (1 << this->bit));
}

Fixed::Fixed(Fixed &copy) {
	// DISPLAY std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(Fixed const &copy) {
	// DISPLAY std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void) {
	// DISPLAY std::cout << "Destructor called" << std::endl;
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

Fixed Fixed::min(Fixed &ref1, Fixed &ref2) {
	if (ref1 > ref2)
		return ref2;
	else
		return ref1;
}

Fixed Fixed::min(Fixed const &ref1, Fixed const &ref2) {
	if (ref1 > ref2)
		return ref2;
	else
		return ref1;
}

Fixed Fixed::max(Fixed &ref1, Fixed &ref2) {
	if (ref1 < ref2)
		return ref2;
	else
		return ref1;
}

Fixed Fixed::max(Fixed const &ref1, Fixed const &ref2) {
	if (ref1 < ref2)
		return ref2;
	else
		return ref1;
}

// incrementation/decrementation operator

Fixed Fixed::operator++() {
	this->value += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->value += 1;
	return (tmp);
}

Fixed Fixed::operator--() {
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->value -= 1;
	return (tmp);
}

// Assignment operator

Fixed &Fixed::operator=(Fixed const &fixed) {
	// DISPLAY std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}

// arithmetic operator

Fixed Fixed::operator+(Fixed const &ref) const {
	Fixed ret;

	ret.setRawBits(this->value + ref.getRawBits());
	return ret;
}

Fixed Fixed::operator-(Fixed const &ref) const {
	Fixed ret;

	ret.setRawBits(this->value - ref.getRawBits());
	return ret;
}

Fixed Fixed::operator*(Fixed const &ref) const {
	Fixed ret;

	ret.setRawBits(this->getFloat() * ref.getRawBits());
	return ret;
}

Fixed Fixed::operator/(Fixed const &ref) const {
	Fixed ret;

	ret.setRawBits(roundf((1 << this->bit) * this->value / ref.value));
	return ret;
}

// compare operator

bool Fixed::operator==(Fixed const &ref) const {
	return (this->value == ref.getRawBits());
}

bool Fixed::operator!=(Fixed const &ref) const {
	return (this->value != ref.getRawBits());
}

bool Fixed::operator>(Fixed const &ref) const {
	return (this->value > ref.getRawBits());
}

bool Fixed::operator>=(Fixed const &ref) const {
	return (this->value >= ref.getRawBits());
}

bool Fixed::operator<(Fixed const &ref) const {
	return (this->value < ref.getRawBits());
}

bool Fixed::operator<=(Fixed const &ref) const {
	return (this->value <= ref.getRawBits());
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed) {
	ostream << fixed.getFloat();
	return ostream;
}
