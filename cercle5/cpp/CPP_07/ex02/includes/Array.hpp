/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:15:58 by macbookpro        #+#    #+#             */
/*   Updated: 2022/03/29 17:18:06 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	
public:
	
	// constructor and destructor

	Array(unsigned int n = 0): array(new T[n]), _size(n) {
		for (unsigned int i = 0; i < n; i++) {
			this->array[i] = 0;
		}
	};
	
	Array(Array const &ref): array(new T[ref._size]), _size(ref._size) {*this = ref;};
	
	~Array(void) {delete[] this->array;};
	
	// operator = and []

	Array &operator=(Array const &ref) {
		if (ref._size > this->_size)
			throw ArrayTooLarge();
		if (this != &ref) {
			for (unsigned int i = 0; i < ref._size; i++)
				this->array[i] = ref.array[i];
		}
		return (*this);
	};
	
	T &operator[](unsigned int i) {
		if (i >= this->_size)
			throw IndexTooHigh();
		return (this->array[i]);
	};
	
	T &operator[](unsigned int i) const {
		if (i >= this->_size)
			throw IndexTooHigh();
		return (this->array[i]);
	};

	// function size

	unsigned int size(void) const {return this->_size;};

	// std::exception

	class ArrayTooLarge: public std::exception {
		const char * what() const throw() {
			return ("Array too large");
		};
	};
	class IndexTooHigh: public std::exception {
		const char * what() const throw() {
			return ("Invalide index");
		};
	};

private:

	T *array;
	unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &ostream, Array<T> const &ref) {
	unsigned int size = ref.size();
	unsigned int i;
	for (i = 0; i < size - 1; i++) {
		ostream << ref[i] << " ";
	}
	ostream << ref[i];
	return (ostream);
}

template <>
std::ostream &operator<<(std::ostream &ostream, Array<char> const &ref) {
	unsigned int size = ref.size();
	unsigned int i;
	for (i = 0; i < size; i++)
		ostream << ref[i];
	return (ostream);
}

#endif